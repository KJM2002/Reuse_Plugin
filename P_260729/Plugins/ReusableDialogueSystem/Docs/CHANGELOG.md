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
