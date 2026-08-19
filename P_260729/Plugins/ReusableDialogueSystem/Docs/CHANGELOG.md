---
title: "Changelog"
status: ReviewRequired
authority: Historical
scope: "Plugin: ReusableDialogueSystem"
classified_on: 2026-08-19
owners:
  - "ReusableDialogueSystem Maintainers"
review_reason: "릴리스 및 Git 이력과 변경 항목의 누락 여부를 재대조하지 않음"
---

# Changelog

## Unreleased

- Dialogue interaction prompt text is fully instance-authored; an empty value now hides the prompt instead of using a hardcoded fallback.

## 0.2.1

### Changed

- Dialogue lines now default to character-by-character reveal.
- Added `bForceCharacterReveal`, enabled by default, so existing word-mode assets also reveal per character while instant lines stay instant.
- Added a short ease-out opacity blend for visible character updates. Duration and starting opacity are configurable in Project Settings.

### Fixed

- Reveal timing now uses the effective runtime reveal mode, so forced character reveal uses the character interval instead of the word interval.
