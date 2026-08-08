#include "JMCustomGridMapGeneratorDetails.h"

#include "Actors/JMCustomGridMapGenerator.h"
#include "Blueprint/JMRoomGridLibrary.h"
#include "Data/JMRoomDefinition.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "Editor.h"
#include "PropertyCustomizationHelpers.h"
#include "ScopedTransaction.h"
#include "Styling/AppStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "JMCustomGridMapGeneratorDetails"

namespace
{
    struct FDirectionInfo
    {
        EJMRoomDirection Direction;
        int32 DX;
        int32 DY;
        const TCHAR* Label;
    };

    constexpr FDirectionInfo Directions[] = {
        { EJMRoomDirection::North, 0, 1, TEXT("North") },
        { EJMRoomDirection::East, 1, 0, TEXT("East") },
        { EJMRoomDirection::South, 0, -1, TEXT("South") },
        { EJMRoomDirection::West, -1, 0, TEXT("West") }
    };

    const FDirectionInfo* FindDirectionInfo(const EJMRoomDirection Direction)
    {
        for (const FDirectionInfo& Info : Directions)
            if (Info.Direction == Direction) return &Info;
        return nullptr;
    }
}

TSharedRef<IDetailCustomization> FJMCustomGridMapGeneratorDetails::MakeInstance()
{
    return MakeShared<FJMCustomGridMapGeneratorDetails>();
}

void FJMCustomGridMapGeneratorDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
    TArray<TWeakObjectPtr<UObject>> Objects;
    DetailBuilder.GetObjectsBeingCustomized(Objects);
    if (Objects.Num() != 1) return;
    Generator = Cast<AJMCustomGridMapGenerator>(Objects[0].Get());
    if (!Generator.IsValid()) return;

    if (Generator->Cells.Num() != Generator->GridWidth * Generator->GridHeight)
        Generator->SynchronizeGridCells();
    DetailBuilder.HideProperty(GET_MEMBER_NAME_CHECKED(AJMCustomGridMapGenerator, Cells));

    if (SelectedCoordinate.X < 0 || SelectedCoordinate.X >= Generator->GridWidth
        || SelectedCoordinate.Y < 0 || SelectedCoordinate.Y >= Generator->GridHeight)
        SelectedCoordinate = FJMGridCoordinate(0, 0);

    IDetailCategoryBuilder& Category = DetailBuilder.EditCategory(
        TEXT("Grid Designer"), LOCTEXT("GridDesignerCategory", "Grid Designer"), ECategoryPriority::Important);

    Category.AddCustomRow(LOCTEXT("DesignerModeFilter", "Shape Connections Mode"))
    .WholeRowContent()
    [
        SNew(SHorizontalBox)
        + SHorizontalBox::Slot().AutoWidth().Padding(2)
        [
            SNew(SButton)
            .Text(LOCTEXT("ShapeMode", "1. Shape Edit"))
            .ToolTipText(LOCTEXT("ShapeModeTip", "Click grid sectors to enable or disable the map shape."))
            .ButtonColorAndOpacity_Lambda([this]() { return Mode == EDesignerMode::Shape ? FLinearColor(0.15f, 0.55f, 0.95f) : FLinearColor::White; })
            .OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleModeClicked, EDesignerMode::Shape)
        ]
        + SHorizontalBox::Slot().AutoWidth().Padding(2)
        [
            SNew(SButton)
            .Text(LOCTEXT("ConnectionMode", "2. Way / Direction Edit"))
            .ToolTipText(LOCTEXT("ConnectionModeTip", "Select one enabled sector, then choose its Way preset and directions below."))
            .ButtonColorAndOpacity_Lambda([this]() { return Mode == EDesignerMode::Connections ? FLinearColor(0.15f, 0.55f, 0.95f) : FLinearColor::White; })
            .OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleModeClicked, EDesignerMode::Connections)
        ]
    ];

    TSharedRef<SGridPanel> GridPanel = SNew(SGridPanel).FillColumn(0, 1.0f);
    for (int32 Y = Generator->GridHeight - 1; Y >= 0; --Y)
    {
        const int32 DisplayRow = Generator->GridHeight - 1 - Y;
        for (int32 X = 0; X < Generator->GridWidth; ++X)
        {
            GridPanel->AddSlot(X, DisplayRow)
            .Padding(2)
            [
                SNew(SBox)
                .MinDesiredWidth(74.0f)
                .MinDesiredHeight(54.0f)
                [
                    SNew(SButton)
                    .HAlign(HAlign_Center)
                    .VAlign(VAlign_Center)
                    .Text_Lambda([this, X, Y]() { return GetCellLabel(X, Y); })
                    .ButtonColorAndOpacity_Lambda([this, X, Y]() { return GetCellColor(X, Y); })
                    .OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleCellClicked, X, Y)
                ]
            ];
        }
    }

    Category.AddCustomRow(LOCTEXT("VisualGridFilter", "Visual Grid Sectors"))
    .WholeRowContent()
    [
        SNew(SBox)
        .MaxDesiredHeight(430.0f)
        [
            SNew(SScrollBox)
            .Orientation(Orient_Horizontal)
            + SScrollBox::Slot()
            [
                SNew(SScrollBox)
                .Orientation(Orient_Vertical)
                + SScrollBox::Slot()
                [
                    GridPanel
                ]
            ]
        ]
    ];

    Category.AddCustomRow(LOCTEXT("ShapeActionsFilter", "Shape Actions"))
    .WholeRowContent()
    [
        SNew(SHorizontalBox)
        + SHorizontalBox::Slot().AutoWidth().Padding(2)
        [
            SNew(SButton)
            .Text(LOCTEXT("AutoConnect", "Auto Connect Adjacent Cells"))
            .ToolTipText(LOCTEXT("AutoConnectTip", "Open reciprocal passages between every pair of touching enabled cells. Existing Entrance/Exit external openings are preserved."))
            .OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleAutoConnectClicked)
        ]
        + SHorizontalBox::Slot().AutoWidth().Padding(2)
        [
            SNew(SButton)
            .Text(LOCTEXT("ClearShape", "Clear Shape"))
            .OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleClearShapeClicked)
        ]
    ];

    Category.AddCustomRow(LOCTEXT("SelectedCellFilter", "Selected Sector"))
    .NameContent()[SNew(STextBlock).Text(LOCTEXT("SelectedCell", "Selected Sector"))]
    .ValueContent()
    .MinDesiredWidth(330.0f)
    [
        SNew(STextBlock)
        .Text_Lambda([this]() { return GetSelectedSummary(); })
        .ColorAndOpacity(FLinearColor(1.0f, 0.85f, 0.2f))
    ];

    Category.AddCustomRow(LOCTEXT("WayPresetFilter", "Way Preset"))
    .NameContent()[SNew(STextBlock).Text(LOCTEXT("WayPreset", "Way Preset"))]
    .ValueContent()
    .MinDesiredWidth(330.0f)
    [
        SNew(SHorizontalBox)
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("OneWay", "1-Way")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleWayPresetClicked, 1)]
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("TwoWay", "2-Way")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleWayPresetClicked, 2)]
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("ThreeWay", "3-Way")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleWayPresetClicked, 3)]
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("FourWay", "4-Way")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleWayPresetClicked, 4)]
    ];

    TSharedRef<SHorizontalBox> DirectionRow = SNew(SHorizontalBox);
    for (const FDirectionInfo& Info : Directions)
    {
        DirectionRow->AddSlot().AutoWidth().Padding(2)
        [
            SNew(SCheckBox)
            .Style(FAppStyle::Get(), "ToggleButtonCheckbox")
            .IsEnabled_Lambda([this]() { const FJMCustomGridCell* Cell = FindSelectedCell(); return Cell && Cell->bEnabled; })
            .IsChecked_Lambda([this, Direction = Info.Direction]()
            {
                const FJMCustomGridCell* Cell = FindSelectedCell();
                return Cell && EnumHasAnyFlags(Cell->GetDirectionMask(), Direction) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
            })
            .OnCheckStateChanged(this, &FJMCustomGridMapGeneratorDetails::HandleDirectionChanged, Info.Direction)
            [SNew(STextBlock).Text(FText::FromString(Info.Label))]
        ];
    }
    Category.AddCustomRow(LOCTEXT("DirectionsFilter", "North East South West"))
    .NameContent()[SNew(STextBlock).Text(LOCTEXT("Directions", "Directions"))]
    .ValueContent().MinDesiredWidth(330.0f)[DirectionRow];

    Category.AddCustomRow(LOCTEXT("RoleFilter", "Entrance Exit Role"))
    .NameContent()[SNew(STextBlock).Text(LOCTEXT("CellRole", "Cell Role"))]
    .ValueContent().MinDesiredWidth(330.0f)
    [
        SNew(SHorizontalBox)
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("SetEntrance", "Set Entrance")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleSetRoleClicked, true, false)]
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("SetExit", "Set Exit")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleSetRoleClicked, false, true)]
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("ClearRole", "Normal")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleSetRoleClicked, false, false)]
    ];

    Category.AddCustomRow(LOCTEXT("SpecialRoomFilter", "Special Room Definition"))
    .NameContent()[SNew(STextBlock).Text(LOCTEXT("SpecialRoom", "Special Room"))]
    .ValueContent().MinDesiredWidth(330.0f)
    [
        SNew(SObjectPropertyEntryBox)
        .AllowedClass(UJMRoomDefinition::StaticClass())
        .ObjectPath_Lambda([this]() { return GetSpecialRoomObjectPath(); })
        .OnObjectChanged(this, &FJMCustomGridMapGeneratorDetails::HandleSpecialRoomChanged)
        .DisplayBrowse(true)
        .DisplayUseSelected(true)
    ];

    Category.AddCustomRow(LOCTEXT("BuildActionsFilter", "Validate Draw Generate"))
    .WholeRowContent()
    [
        SNew(SHorizontalBox)
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("Validate", "Validate Grid")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleValidateClicked)]
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("Draw", "Refresh Viewport Preview")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleDrawClicked)]
        + SHorizontalBox::Slot().AutoWidth().Padding(2)[SNew(SButton).Text(LOCTEXT("Generate", "Generate Rooms")).OnClicked(this, &FJMCustomGridMapGeneratorDetails::HandleGenerateClicked)]
    ];
}

FReply FJMCustomGridMapGeneratorDetails::HandleCellClicked(const int32 X, const int32 Y)
{
    if (!Generator.IsValid()) return FReply::Handled();
    SelectedCoordinate = FJMGridCoordinate(X, Y);
    FJMCustomGridCell* Cell = FindSelectedCell();
    if (Mode == EDesignerMode::Shape && Cell)
    {
        const FScopedTransaction Transaction(LOCTEXT("ToggleGridCell", "Toggle Custom Grid Sector"));
        Generator->Modify();
        const bool bEnable = !Cell->bEnabled;
        if (!bEnable)
        {
            for (const FDirectionInfo& Info : Directions)
            {
                FJMCustomGridCell* Neighbor = Generator->Cells.FindByPredicate([this, &Info](const FJMCustomGridCell& Candidate)
                {
                    return Candidate.Coordinate == FJMGridCoordinate(SelectedCoordinate.X + Info.DX, SelectedCoordinate.Y + Info.DY);
                });
                if (Neighbor)
                    Neighbor->OpenDirections &= ~static_cast<int32>(UJMRoomGridLibrary::OppositeDirection(Info.Direction));
            }
            Cell->OpenDirections = 0;
            Cell->bEntrance = false;
            Cell->bExit = false;
            Cell->SpecialRoomDefinition.Reset();
        }
        Cell->bEnabled = bEnable;
        Generator->PostEditChange();
    }
    if (GEditor) GEditor->RedrawLevelEditingViewports();
    return FReply::Handled();
}

FReply FJMCustomGridMapGeneratorDetails::HandleModeClicked(const EDesignerMode NewMode)
{
    Mode = NewMode;
    return FReply::Handled();
}

FReply FJMCustomGridMapGeneratorDetails::HandleWayPresetClicked(const int32 WayCount)
{
    static const int32 Masks[] = {
        static_cast<int32>(EJMRoomDirection::North),
        static_cast<int32>(EJMRoomDirection::North | EJMRoomDirection::South),
        static_cast<int32>(EJMRoomDirection::West | EJMRoomDirection::East | EJMRoomDirection::South),
        static_cast<int32>(EJMRoomDirection::All)
    };
    if (WayCount >= 1 && WayCount <= 4) SetSelectedMask(Masks[WayCount - 1]);
    Mode = EDesignerMode::Connections;
    return FReply::Handled();
}

FReply FJMCustomGridMapGeneratorDetails::HandleAutoConnectClicked()
{
    if (!Generator.IsValid()) return FReply::Handled();
    const FScopedTransaction Transaction(LOCTEXT("AutoConnectGrid", "Auto Connect Custom Grid Sectors"));
    Generator->Modify();
    for (FJMCustomGridCell& Cell : Generator->Cells)
    {
        if (!Cell.bEnabled) continue;
        int32 Mask = Cell.OpenDirections;
        for (const FDirectionInfo& Info : Directions)
        {
            const FJMCustomGridCell* Neighbor = Generator->Cells.FindByPredicate([&Cell, &Info](const FJMCustomGridCell& Candidate)
            {
                return Candidate.Coordinate == FJMGridCoordinate(Cell.Coordinate.X + Info.DX, Cell.Coordinate.Y + Info.DY);
            });
            if (Neighbor && Neighbor->bEnabled) Mask |= static_cast<int32>(Info.Direction);
            else if (!Cell.bEntrance && !Cell.bExit) Mask &= ~static_cast<int32>(Info.Direction);
        }
        Cell.OpenDirections = Mask;
    }
    Generator->PostEditChange();
    return FReply::Handled();
}

FReply FJMCustomGridMapGeneratorDetails::HandleClearShapeClicked()
{
    if (!Generator.IsValid()) return FReply::Handled();
    const FScopedTransaction Transaction(LOCTEXT("ClearGridShape", "Clear Custom Grid Shape"));
    Generator->Modify();
    for (FJMCustomGridCell& Cell : Generator->Cells)
    {
        Cell.bEnabled = false;
        Cell.OpenDirections = 0;
        Cell.bEntrance = false;
        Cell.bExit = false;
        Cell.SpecialRoomDefinition.Reset();
    }
    Generator->PostEditChange();
    return FReply::Handled();
}

FReply FJMCustomGridMapGeneratorDetails::HandleSetRoleClicked(const bool bEntrance, const bool bExit)
{
    if (!Generator.IsValid()) return FReply::Handled();
    FJMCustomGridCell* Selected = FindSelectedCell();
    if (!Selected || !Selected->bEnabled) return FReply::Handled();
    const FScopedTransaction Transaction(LOCTEXT("SetGridCellRole", "Set Custom Grid Sector Role"));
    Generator->Modify();
    if (bEntrance || bExit)
    {
        for (FJMCustomGridCell& Cell : Generator->Cells)
        {
            if (bEntrance) Cell.bEntrance = false;
            if (bExit) Cell.bExit = false;
        }
    }
    Selected->bEntrance = bEntrance;
    Selected->bExit = bExit;
    Generator->PostEditChange();
    return FReply::Handled();
}

FReply FJMCustomGridMapGeneratorDetails::HandleValidateClicked()
{
    if (Generator.IsValid()) Generator->ValidateGridDesignInEditor();
    return FReply::Handled();
}

FReply FJMCustomGridMapGeneratorDetails::HandleDrawClicked()
{
    if (Generator.IsValid()) Generator->DrawGridDesign();
    return FReply::Handled();
}

FReply FJMCustomGridMapGeneratorDetails::HandleGenerateClicked()
{
    if (Generator.IsValid()) Generator->GeneratePreview();
    return FReply::Handled();
}

void FJMCustomGridMapGeneratorDetails::HandleDirectionChanged(const ECheckBoxState NewState, const EJMRoomDirection Direction)
{
    if (!Generator.IsValid()) return;
    const FScopedTransaction Transaction(LOCTEXT("SetGridDirection", "Set Custom Grid Direction"));
    Generator->Modify();
    SetDirectionMirrored(Direction, NewState == ECheckBoxState::Checked);
    Generator->PostEditChange();
}

void FJMCustomGridMapGeneratorDetails::HandleSpecialRoomChanged(const FAssetData& AssetData)
{
    FJMCustomGridCell* Cell = FindSelectedCell();
    if (!Generator.IsValid() || !Cell || !Cell->bEnabled) return;
    const FScopedTransaction Transaction(LOCTEXT("SetSpecialRoom", "Set Custom Grid Special Room"));
    Generator->Modify();
    Cell->SpecialRoomDefinition = Cast<UJMRoomDefinition>(AssetData.GetAsset());
    Generator->PostEditChange();
}

FJMCustomGridCell* FJMCustomGridMapGeneratorDetails::FindSelectedCell() const
{
    if (!Generator.IsValid()) return nullptr;
    return Generator->Cells.FindByPredicate([this](const FJMCustomGridCell& Cell) { return Cell.Coordinate == SelectedCoordinate; });
}

void FJMCustomGridMapGeneratorDetails::SetDirectionMirrored(const EJMRoomDirection Direction, const bool bOpen)
{
    FJMCustomGridCell* Cell = FindSelectedCell();
    const FDirectionInfo* Info = FindDirectionInfo(Direction);
    if (!Generator.IsValid() || !Cell || !Cell->bEnabled || !Info) return;
    if (bOpen) Cell->OpenDirections |= static_cast<int32>(Direction);
    else Cell->OpenDirections &= ~static_cast<int32>(Direction);

    FJMCustomGridCell* Neighbor = Generator->Cells.FindByPredicate([this, Info](const FJMCustomGridCell& Candidate)
    {
        return Candidate.Coordinate == FJMGridCoordinate(SelectedCoordinate.X + Info->DX, SelectedCoordinate.Y + Info->DY);
    });
    if (Neighbor && Neighbor->bEnabled)
    {
        const int32 Opposite = static_cast<int32>(UJMRoomGridLibrary::OppositeDirection(Direction));
        if (bOpen) Neighbor->OpenDirections |= Opposite;
        else Neighbor->OpenDirections &= ~Opposite;
    }
}

void FJMCustomGridMapGeneratorDetails::SetSelectedMask(const int32 NewMask)
{
    if (!Generator.IsValid()) return;
    FJMCustomGridCell* Cell = FindSelectedCell();
    if (!Cell || !Cell->bEnabled) return;
    const FScopedTransaction Transaction(LOCTEXT("SetWayPreset", "Set Custom Grid Way Preset"));
    Generator->Modify();
    for (const FDirectionInfo& Info : Directions)
        SetDirectionMirrored(Info.Direction, (NewMask & static_cast<int32>(Info.Direction)) != 0);
    Generator->PostEditChange();
}

FText FJMCustomGridMapGeneratorDetails::GetCellLabel(const int32 X, const int32 Y) const
{
    if (!Generator.IsValid()) return FText::GetEmpty();
    const FJMCustomGridCell* Cell = Generator->Cells.FindByPredicate([X, Y](const FJMCustomGridCell& Candidate)
    {
        return Candidate.Coordinate == FJMGridCoordinate(X, Y);
    });
    if (!Cell || !Cell->bEnabled) return FText::FromString(FString::Printf(TEXT("(%d,%d)\nInactive"), X, Y));
    FString DirectionsText;
    if (EnumHasAnyFlags(Cell->GetDirectionMask(), EJMRoomDirection::North)) DirectionsText += TEXT("N");
    if (EnumHasAnyFlags(Cell->GetDirectionMask(), EJMRoomDirection::East)) DirectionsText += TEXT("E");
    if (EnumHasAnyFlags(Cell->GetDirectionMask(), EJMRoomDirection::South)) DirectionsText += TEXT("S");
    if (EnumHasAnyFlags(Cell->GetDirectionMask(), EJMRoomDirection::West)) DirectionsText += TEXT("W");
    if (DirectionsText.IsEmpty()) DirectionsText = TEXT("No Way");
    return FText::FromString(FString::Printf(TEXT("(%d,%d)\n%s%s%s"), X, Y, *DirectionsText,
        Cell->bEntrance ? TEXT(" [IN]") : TEXT(""), Cell->bExit ? TEXT(" [OUT]") : TEXT("")));
}

FSlateColor FJMCustomGridMapGeneratorDetails::GetCellColor(const int32 X, const int32 Y) const
{
    if (!Generator.IsValid()) return FLinearColor::Gray;
    const FJMCustomGridCell* Cell = Generator->Cells.FindByPredicate([X, Y](const FJMCustomGridCell& Candidate)
    {
        return Candidate.Coordinate == FJMGridCoordinate(X, Y);
    });
    if (!Cell || !Cell->bEnabled) return FLinearColor(0.12f, 0.12f, 0.12f);
    if (SelectedCoordinate == FJMGridCoordinate(X, Y)) return FLinearColor(0.95f, 0.65f, 0.05f);
    if (Cell->bEntrance) return FLinearColor(0.05f, 0.65f, 0.18f);
    if (Cell->bExit) return FLinearColor(0.05f, 0.3f, 0.9f);
    if (!Cell->SpecialRoomDefinition.IsNull()) return FLinearColor(0.9f, 0.35f, 0.05f);
    return FLinearColor(0.25f, 0.48f, 0.7f);
}

FText FJMCustomGridMapGeneratorDetails::GetSelectedSummary() const
{
    const FJMCustomGridCell* Cell = FindSelectedCell();
    if (!Cell) return LOCTEXT("NoSelection", "No sector selected");
    if (!Cell->bEnabled)
        return FText::FromString(FString::Printf(TEXT("(%d,%d) - Inactive"), SelectedCoordinate.X, SelectedCoordinate.Y));
    const int32 Count = UJMRoomGridLibrary::CountDirections(Cell->GetDirectionMask());
    return FText::FromString(FString::Printf(TEXT("(%d,%d) - %d-Way%s%s"), SelectedCoordinate.X, SelectedCoordinate.Y, Count,
        Cell->bEntrance ? TEXT(" / Entrance") : TEXT(""), Cell->bExit ? TEXT(" / Exit") : TEXT("")));
}

FString FJMCustomGridMapGeneratorDetails::GetSpecialRoomObjectPath() const
{
    const FJMCustomGridCell* Cell = FindSelectedCell();
    return Cell ? Cell->SpecialRoomDefinition.ToSoftObjectPath().ToString() : FString();
}

#undef LOCTEXT_NAMESPACE
