---
title: "Changelog"
status: ReviewRequired
authority: Historical
scope: "Plugin: JMRoomGrid"
classified_on: 2026-08-19
owners:
  - "JMRoomGrid Maintainers"
review_reason: "릴리스 및 Git 이력과 변경 항목의 누락 여부를 재대조하지 않음"
---

# Changelog

## 1.5.0

### Added

- Added the independent native `AJMCustomGridMapGenerator`; the fixed 5x5 generator and existing content remain unchanged.
- Added editable grid dimensions, enabled cells, explicit direction masks, entrance, exit and per-cell special Room Definition overrides.
- Added pre-generation validation for reciprocal connections, external openings, duplicate/out-of-range cells and whole-map reachability.
- Added direction-count-based 1/2/3/4-Way classification while preserving serialized enum values for all existing assets.
- Added isolated custom-generated actor cleanup, design debug drawing and custom-topology automation coverage.
- Added a visual Grid Designer Details panel with separate shape and connection editing modes, clickable sectors, Way presets, reciprocal direction toggles, roles, special rooms and build actions.

### Fixed

- Fixed a Unity Build compile failure caused by the fixed and custom generator translation units using the same anonymous-namespace helper name.

## 1.4.1

- Fixed generated 13x13 floor, wall, and ceiling components failing to attach to the movable `StructureRoot`.
- Existing generated room structures are upgraded to version 3 while user-authored Blueprint components remain preserved.
- Updated the Korean guide with the complete 13x13 specification, editor regeneration workflow, room editing, ceiling visibility, runtime generation, and troubleshooting.

## 1.4.0

### Changed

- Redesigned all twelve 13×13 rooms from the supplied maze-floorplan references.
- Added asymmetric chambers, bent corridors, side rooms, loops, courtyards, and dead-end exploration spaces.
- Generated-structure versioning replaces only `JMGen_*` components while preserving user-authored Blueprint components.

## 1.3.0

### Changed

- Replaced generated room instance geometry with individually editable Blueprint Static Mesh Components.
- Floors and ceilings now exist only on walkable tiles; walls exist only around their boundary.
- Generated components use the configured `SM_Floor`, `SM_Wall`, and `SM_Ceiling` assets directly.

## 1.2.0

### Added

- Editable 13×13 room library with four variants for each junction type.
- Per-Blueprint `Custom Walkable Tiles` coordinates and automatic wall reconstruction.
- Instanced 169-floor/169-ceiling rendering to keep 25-room preview component counts manageable.
- Preconfigured `BP_GridMapGenerator13x13` with 5,200cm room spacing.

## 1.1.0

### Added

- 5×5 floor-tile room structure with 25 floors, 25 ceilings, and 60 tile-edge walls.
- Twelve distinct room Blueprints: four variants each for 2-way, 3-way, and 4-way junctions.
- Twelve matching Room Definitions and a preconfigured `BP_GridMapGenerator5x5`.
- Headless Unreal commandlet for reproducible create-missing-only asset generation.
- Layout tests for center traversal, required endpoints, uniqueness, topology, and rotation-only placement.

### Changed

- Room spacing is now 2,000cm; the full 5×5-room map spans 10,000cm (125×125 design units).

## 1.0.0

### Added

- Runtime room contract, directional ports, Room Definition and deterministic standard 5x5 generator.
- Developer Settings with soft prototype mesh references and tolerance-based bounds validation.
- Editor create-missing-only Blueprint/Data Asset tools and validation menu.
- Automation coverage for bounds, rotation, topology, placement, determinism and no-mirroring rules.

### Fixed

- Preserve configured derived Blueprint CDO values by avoiding a second compile after setting room defaults.
- Add a targeted Blueprint and Room Definition contract repair tool for assets created before the fix.
- Expose void `CallInEditor` wrappers so generator actions appear as Details-panel buttons while retaining result-returning Blueprint APIs.
- Expose canonical directions through Unreal's standard editable `int32` bitmask so multiple directions can be selected in Details panels.
- Repair all four prototype allowed rotations to guarantee every standard edge/corner orientation has an exact candidate.
- Validate RoomAnchor by root ownership instead of treating a placed root component's world-backed relative transform as a local offset.
- Include cell, class, yaw, expected mask, actual mask, and canonical mask in generated-map validation errors.
