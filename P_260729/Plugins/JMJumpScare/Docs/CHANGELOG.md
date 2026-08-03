# Changelog

## 1.1.0

### Added

- Backward-compatible Presentation Mode: WorldActor, CameraRelative, CameraAttached, ForcedLookAt
- Preparing/Entering/Impact/Holding/Exiting/Finishing detailed Phase API
- Impact and Exiting Actor Interface events and Gameplay Event tags
- Optional Focus Component, Control Rotation/Camera Position/FOV blends
- Phase Audio Events, Exit Noise, Exit Camera Shake
- Camera-local Post Process glitch blend and None/InstantHide/InterfaceDriven vanish policies
- Camera/Input restore policies and cancellation coverage for additional phases

### Compatibility

- Existing SpawnMode, State, Sound, SoundDelay, CameraShake and FOV properties remain intact.
- New Definitions default to UseLegacySpawnMode, so existing Data Assets retain their previous behavior.

## 1.0.0

### Added

- Data-driven JumpScare Definition, World subsystem and explicit state machine
- CameraRelative and WorldAnchor transforms
- Box Trigger, Gameplay Event Trigger component and Blueprint API
- Timer-based delay/audio/duration flow with actor, camera, FOV and input cleanup
- Native Gameplay Event tags and payload
- Project Settings, Editor-only Anchor visualization, save-state extension contract
- Editor automation coverage and Korean architecture/integration guides
