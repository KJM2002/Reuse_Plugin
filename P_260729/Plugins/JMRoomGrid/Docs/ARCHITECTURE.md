# JM Room Grid architecture

## Scope

`JMRoomGridRuntime` owns direction math, the editable native room contract, room definitions, deterministic 5x5 topology selection, spawning and runtime-safe validation. It does not modify Blueprint assets or assemble structure meshes in the generator.

`JMRoomGridEditor` owns Project Settings asset validation and create-missing-only Blueprint/Data Asset authoring through Unreal Editor APIs. It never overwrites an existing asset.

`JMRoomGridTests` owns editor automation coverage for direction rotation, prototype bounds, topology, determinism, placement and scale restrictions.

## Dependencies and lifetime

The plugin has no dependency on another JM plugin or host-project class/content. Runtime depends only on Engine modules. Soft mesh references live in `UJMRoomGridSettings`; missing or invalid references produce validation errors and block asset creation. Generated room actors are owned by the generator's world and tracked through transient object references. No generation or connection validation runs from Tick.

## Data flow

The generator computes the exact required direction mask for each standard cell, rotates every enabled room definition's canonical mask by each explicitly allowed quarter turn, filters exact matches, performs deterministic weighted selection using `FRandomStream`, then spawns the selected Blueprint class at the cell transform. Validation re-derives topology and checks count, scale, direction and adjacency contracts.

## Blueprint and content boundary

Room structure components are native default subobjects visible and editable in derived Blueprints. `ContentRoot`, `ItemSpawnRoot` and `AISpawnRoot` are user-owned extension roots. Neither generation nor asset validation deletes or reconstructs their children. Plugin-generated assets use the portable `/JMRoomGrid` mount point.

## Network, save and failure policy

The prototype is authority-agnostic and does not replicate generated actors or persist maps. Consumers can save stable room IDs, grid coordinates, yaw and seed. Invalid settings, missing definitions/classes, invalid rotations and spawn failures are reported without crashing; generation is aborted or rolled back when it cannot produce a complete map.
