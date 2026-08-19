[CmdletBinding()]
param(
    [string]$DocsRoot = (Split-Path -Parent $PSScriptRoot),
    [switch]$ProjectDocsOnly
)

$ErrorActionPreference = 'Stop'

$ResolvedDocsRoot = (Resolve-Path -LiteralPath $DocsRoot).Path
$ProjectRoot = Split-Path -Parent $ResolvedDocsRoot
$MarkdownFiles = [System.Collections.Generic.List[System.IO.FileInfo]]::new()
$MarkdownFiles.AddRange([System.IO.FileInfo[]]@(
    Get-ChildItem -LiteralPath $ResolvedDocsRoot -Recurse -File -Filter '*.md'))

$PluginsRoot = Join-Path -Path $ProjectRoot -ChildPath 'Plugins'
if (-not $ProjectDocsOnly -and (Test-Path -LiteralPath $PluginsRoot))
{
    $PluginMarkdown = @(
        Get-ChildItem -LiteralPath $PluginsRoot -Recurse -File -Filter '*.md' |
            Where-Object { $_.Name -ne 'AGENTS.md' })
    $MarkdownFiles.AddRange([System.IO.FileInfo[]]$PluginMarkdown)
}

$MarkdownFiles = @($MarkdownFiles | Sort-Object FullName -Unique)
$Errors = [System.Collections.Generic.List[string]]::new()

$AllowedStatuses = @('Current', 'Draft', 'ReviewRequired', 'Superseded', 'Archived')
$AllowedAuthorities = @('Canonical', 'Supporting', 'Guide', 'Plan', 'Historical')

foreach ($File in $MarkdownFiles)
{
    $RelativePath = [System.IO.Path]::GetRelativePath($ProjectRoot, $File.FullName)
    $Content = Get-Content -LiteralPath $File.FullName -Raw
    $FrontMatterMatch = [regex]::Match(
        $Content,
        '\A---\r?\n(?<Yaml>.*?)\r?\n---(?:\r?\n|\z)',
        [System.Text.RegularExpressions.RegexOptions]::Singleline)

    if (-not $FrontMatterMatch.Success)
    {
        $Errors.Add("${RelativePath}: YAML front matter가 없습니다.")
        continue
    }

    $Yaml = $FrontMatterMatch.Groups['Yaml'].Value
    foreach ($RequiredKey in @('title', 'status', 'authority', 'scope', 'owners'))
    {
        if ($Yaml -notmatch "(?m)^$([regex]::Escape($RequiredKey)):\s*\S?")
        {
            $Errors.Add("${RelativePath}: 필수 메타데이터 '$RequiredKey'가 없습니다.")
        }
    }

    $StatusMatch = [regex]::Match($Yaml, '(?m)^status:\s*(?<Value>[^\r\n#]+)')
    $Status = $StatusMatch.Groups['Value'].Value.Trim()
    if ($Status -notin $AllowedStatuses)
    {
        $Errors.Add("${RelativePath}: 허용되지 않은 status '$Status'입니다.")
    }

    $AuthorityMatch = [regex]::Match($Yaml, '(?m)^authority:\s*(?<Value>[^\r\n#]+)')
    $Authority = $AuthorityMatch.Groups['Value'].Value.Trim()
    if ($Authority -notin $AllowedAuthorities)
    {
        $Errors.Add("${RelativePath}: 허용되지 않은 authority '$Authority'입니다.")
    }

    if ($Status -eq 'Current' -and
        $Yaml -notmatch '(?m)^last_(verified|reviewed):\s*\S+')
    {
        $Errors.Add("${RelativePath}: Current 문서에는 last_verified 또는 last_reviewed가 필요합니다.")
    }
    if ($Status -eq 'ReviewRequired' -and
        $Yaml -notmatch '(?m)^review_reason:\s*\S+')
    {
        $Errors.Add("${RelativePath}: ReviewRequired 문서에는 review_reason이 필요합니다.")
    }
    if ($Status -eq 'Superseded' -and
        $Yaml -notmatch '(?m)^superseded_by:\s*\S+')
    {
        $Errors.Add("${RelativePath}: Superseded 문서에는 superseded_by가 필요합니다.")
    }

    $LinkMatches = [regex]::Matches($Content, '!?(?:\[[^\]]*\])\((?<Target>[^)]+)\)')
    foreach ($LinkMatch in $LinkMatches)
    {
        $Target = $LinkMatch.Groups['Target'].Value.Trim().Trim('<', '>')
        if ([string]::IsNullOrWhiteSpace($Target) -or
            $Target.StartsWith('#') -or
            $Target.StartsWith('/') -or
            $Target -match '^(https?|mailto|data):')
        {
            continue
        }

        $TargetWithoutAnchor = ($Target -split '[#?]', 2)[0]
        if ([string]::IsNullOrWhiteSpace($TargetWithoutAnchor))
        {
            continue
        }

        $DecodedTarget = [System.Uri]::UnescapeDataString($TargetWithoutAnchor)
        $ResolvedTarget = [System.IO.Path]::GetFullPath(
            (Join-Path -Path $File.DirectoryName -ChildPath $DecodedTarget))
        if (-not (Test-Path -LiteralPath $ResolvedTarget))
        {
            $Errors.Add("${RelativePath}: 링크 대상이 없습니다: $Target")
        }
    }
}

if ($Errors.Count -gt 0)
{
    Write-Host "문서 검증 실패: $($Errors.Count)개" -ForegroundColor Red
    $Errors | ForEach-Object { Write-Host "- $_" -ForegroundColor Red }
    exit 1
}

Write-Host "문서 검증 성공: Markdown $($MarkdownFiles.Count)개" -ForegroundColor Green
Write-Host "Project Root: $ProjectRoot"
if ($ProjectDocsOnly)
{
    Write-Host 'Scope: Project Docs only'
}
else
{
    Write-Host 'Scope: Project Docs + Plugin Docs (Plugins/AGENTS.md 제외)'
}
