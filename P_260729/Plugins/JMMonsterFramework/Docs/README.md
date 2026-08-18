# JMMonsterFramework

Reusable, data-driven enemy AI building blocks for Unreal Engine 5.7. The plugin is standalone: it does not depend
on the host `P_060715` module, legacy JM AI plugins, or `/Game` content.

An enemy is a Definition plus Perception, Memory, StateTree, Locomotion, Actions, and optional Presentation. New
behavior normally means composing existing nodes in a new StateTree; C++ is reserved for a genuinely new sense,
movement backend, action capability, or reusable node.

## Architecture

```text
UJMEnemyDefinition ───────────────> immutable system configuration
        │
AJMEnemyBase
├─ UJMEnemyStateComponent          one GameplayTag state
├─ UJMEnemyPerceptionComponent     normalized sensory facts
├─ UJMEnemyMemoryComponent         event-driven history and explicit target
├─ UJMEnemyLocomotionComponent     movement intent and request lifecycle
├─ UJMEnemyActionComponent         runtime action instances and cooldowns
├─ UJMEnemyAudioComponent          optional event-to-sound presentation
└─ UJMEnemyDebugComponent          opt-in runtime inspection

Skeletal Mesh
└─ UJMEnemyAnimInstance            cached, read-only animation data provider

AJMEnemyAIController
├─ UAIPerceptionComponent          Unreal sensing adapter
└─ UJMEnemyStateTreeComponent      possession-scoped behavior runner

World -> Perception -> Memory -> StateTree -> State / Locomotion / Action -> Presentation
```

Perception and Memory never choose behavior. Locomotion does not know why a destination was selected. Actions do
not change State automatically. Enemy-specific rules remain in StateTree assets, and DataAssets never hold runtime
state.

## Quick Start

1. Enable the plugin and show Plugin Content in the Content Browser.
2. Create a Blueprint derived from `AJMEnemyBase` (or `AJMSurfaceCrawlerEnemyBase` only for surface crawling).
3. Create a `UJMEnemyDefinition` and assign it to the Blueprint's Enemy Definition property.
4. Enable the required Vision, Hearing, and/or Player Gaze configuration.
5. Create/select a `UJMEnemyMovementSet` and a valid default profile.
6. Add the required `UJMEnemyActionDefinition` assets.
7. Create a StateTree and compose the provided tasks and conditions.
8. Optionally assign a `UJMEnemyAudioSet`, validate the assets, and Play.

The editor categories group authoring properties under `JM Monster|Identity`, `Perception`, `Movement`, `Actions`,
`Behavior`, `Audio`, and `Debug`.

## Creating a New Enemy

Start with the closest reference, identify its senses, movement, actions, and state flow, then compose a new
Definition and StateTree. If existing building blocks express the design, add no C++.

```text
new behavior pattern or state flow -> StateTree
new tuning value                 -> DataAsset/profile
new sensing capability           -> Perception extension
new movement capability          -> Locomotion subclass
new performed capability         -> Action subclass + Definition
```

Examples: “player gaze causes fleeing” belongs in StateTree; “second encounter enrages” is StateTree plus Memory;
“crawl on walls” requires a Locomotion backend.

## Perception

`UJMEnemyPerceptionComponent` normalizes Unreal Vision/Hearing, Player Gaze, Damage, and externally submitted
observations into `FJMStimulus`. Vision and Hearing are engine-event driven. Gaze runs on the configured interval
only when enabled. `SubmitPlayerGazeObservation` is the adapter boundary for VR, cameras, tests, or custom viewers.

To add a sense, translate its result into `FJMStimulus` at the Perception boundary. Do not place target selection or
state transitions in the sense adapter.

## Memory

`UJMEnemyMemoryComponent` stores last seen/heard/known positions and times, current visibility, explicit current
target, and encounter count. It updates from stimuli and emits target changes; StateTree decides how facts are used.

## State

`UJMEnemyStateComponent` owns one concrete `JM.Enemy.State.*` tag and emits `OnStateChanged`. State tags are
observable runtime state, not a replacement behavior graph.

## Locomotion

`UJMEnemyLocomotionComponent` exposes MoveToActor, MoveToLocation, MoveAway, Stop, facing, random reachable point,
and named profile operations with Started/Succeeded/Failed/Aborted results. Ground movement delegates to UE AI
navigation and does not tick.

`UJMEnemyLocomotion_SurfaceCrawler` preserves the same intent API while tracing connected static geometry. It ticks
only during an active request, normally performs a forward transition trace and one support trace, aligns Actor Up
to the surface normal, and uses bounded surface-loss recovery before failing safely into Falling.

To add Flying or another backend, subclass the locomotion seam and preserve request identity and completion
semantics so generic StateTree tasks remain reusable.

## Actions

`UJMEnemyActionComponent` creates one runtime `UJMEnemyAction` per immutable Definition and enforces one primary
action. Windup, Active, Recovery, cancellation, and cooldown are timer-driven; component Tick is enabled only for
actions that explicitly request updates. Melee and Scream are references. A new performed capability belongs in a
new Action subclass and immutable Action Definition, not in an enemy class.

## StateTree

The controller owns and starts the tree for the possession lifetime. Generic tasks cover state, move, facing,
movement profile, escape, action, encounter, wait, and target commands. Generic conditions query target, recent
stimuli, sight, gaze, distance, encounter, state, and action readiness. `JM.Enemy.Event.Stimulus` wakes event-driven
transitions. Add a new node only when a reusable query or command is missing; do not duplicate engine scheduling.

## Audio

`UJMEnemyAudioSet` maps presentation events to zero or more sound variants with volume and pitch ranges.
`UJMEnemyAudioComponent` subscribes to State and Action delegates; AI code and Scream actions contain no Sound
assets. An empty event entry is a valid placeholder contract.

Current mappings include Investigate, Chase, Flee, Frozen, Enrage, Frenzy, AttackWindup, Attack, Death, and Scream.
Listener demonstrates Investigate/Chase/Attack, Watcher Frozen/Attack, and Crawler Enrage/Scream/Frenzy. Assign
sounds to the variants in each reference Audio Set for playback. No Audio Set means no binding or runtime work.

## Animation / Presentation

`UJMEnemyAnimInstance` is the skeleton-independent bridge from framework runtime data to an Animation Blueprint.
It caches the Enemy, State, Locomotion, and Action references during animation initialization. Each animation update
only reads lightweight values: world velocity, Actor-local direction, speed, moving/falling flags, current State,
movement profile, current Action, and Action phase. It performs no component search, sensing, trace, navigation,
StateTree query, or asset lookup per frame.

```text
StateTree -> State / Locomotion / Action -> UJMEnemyAnimInstance -> AnimBP -> Skeletal Mesh
```

Animation is read-only presentation. An AnimBP must not choose targets or write AI State. GameplayTag state data lets
Listener express Patrol/Investigate/Chase/Search, Watcher select a Frozen pose, and Crawler express Stalk/Flee/
ReApproach/Enrage/Frenzy without enemy-type booleans or specialized runtime brains.

Ground and SurfaceCrawler use the same local-space locomotion contract. SurfaceCrawler rotates Actor Up to the
surface normal, so an in-place crawl animation can remain in Actor local space on floors, walls, and ceilings.
Crawler locomotion should not use general root motion because surface attachment owns the Actor transform.

One-shot animation can bind once to the existing Action Component delegates and select a Montage by Action tag.
`OnActionStarted`, `OnActionPhaseChanged`, `OnActionFinished`, and `OnActionCancelled` remain the event contract;
there is no duplicate animation lifecycle. The current policy remains:

```text
Action timer lifecycle -> gameplay timing and damage
Montage/AnimBP          -> visual synchronization
```

Future Notify-driven gameplay timing is possible as a separate extension, but this plugin does not move the stable
Action timeline or damage ownership into AnimNotify. No `UJMEnemyAnimationSet` is included yet because there are no
shared Montage assets to deduplicate; an optional Definition-owned set can be added when real content requires it.

New Enemy animation workflow:

1. Prepare any Skeletal Mesh/Skeleton; no framework bone names are required.
2. Create an AnimBP based on `UJMEnemyAnimInstance`.
3. Build locomotion from Speed and Direction.
4. Select special poses from CurrentState GameplayTags.
5. Bind Action lifecycle events and select optional Montages by CurrentAction/phase.
6. Keep normal locomotion in-place; treat special root-motion Actions as a future explicit integration.

Animation is completely optional. A cube/static placeholder with Definition, StateTree, Locomotion, Actions, and
Debug can develop and validate the entire AI before a Skeletal Mesh, AnimBP, sequence, Montage, or AnimationSet exists.

## Debug

Every enemy owns an opt-in `UJMEnemyDebugComponent`. It is disabled and non-ticking by default. In PIE, select one
enemy and call `SetDebugEnabled(true)`, enable **Enable On Begin Play**, or use the console command:

```text
JM.AI.Debug 1
JM.AI.Debug 0
```

The overlay shows enemy/state/target, seen-heard-known memory, visibility and gaze, encounter count, movement
profile/status/destination/target/request, current action/phase/cooldown, and StateTree status. World primitives show
vision, hearing, gaze, memory points, move destination, and Crawler attachment/normal/direction. Shipping builds
force the component off and compile out its drawing path.

When a mesh uses `UJMEnemyAnimInstance`, the same overlay also shows AnimInstance class, animation Speed/Direction,
CurrentAction, and Action phase. A placeholder without an AnimInstance reports `Anim: None` without warning or failure.

## Reference Enemies

- **Listener** validates Hearing, evidence investigation without premature targeting, Memory, Chase, Melee, Search,
  and return to Patrol.
- **Watcher** validates Vision, Player Gaze, Frozen, movement/action cancellation, gaze release, Chase, and Attack.
- **Crawler** validates connected static floor/wall/ceiling locomotion, persistent encounter count, shared Gaze,
  first-gaze Flee, second-gaze Enrage, Scream, Frenzy, and Attack.

Reference content is consistently located in `Content/Reference/Listener`, `Watcher`, and `Crawler`. Each folder
contains `BP_Enemy_*`, `DA_Enemy_*`, `ST_*`, Definition-local movement/action assets, and `DA_*_Audio`.

## Testing

Run the `JM.MonsterFramework` automation group. Tests are grouped as:

- Unit: Core state/defaults/validation, stimulus and memory policy, profile lookup, action lifecycle, audio mapping.
- Animation contract: initialization without assets, State/Frozen data, Action lifecycle data, and local-space
  SurfaceCrawler displacement data.
- Integration: Perception-to-Memory composition, StateTree ownership/event bridges, locomotion safe failure.
- Asset Composition: each Reference Definition, Blueprint, StateTree, profiles/actions, and audio contract.
- World Vertical Slice: Listener, Watcher, and Crawler building-block behavior flows in transient game worlds.
- Surface Locomotion: Collision ON capsule traversal across Floor→Wall→Ceiling→Wall→Floor, orientation, request
  replacement/abort, transition count, and NaN safety against actual static cube geometry.

Automation directly steps some StateTree and transient-world fixtures. It verifies component contracts and graph
composition; it does not reproduce the full PIE scheduler, animation, player gameplay, sound-mix quality, packaged
build, moving platforms, multiplayer authority, or a production level's collision complexity. Verify those items in
the target project's PIE and packaged build.

Reference/test assets can be regenerated in the Editor commandlet environment with:

```text
UnrealEditor-Cmd.exe <Project>.uproject -run=JMMonsterFrameworkBuildReferenceAssets
```

The builder lives in the Editor-only Tests module and is not a shipping Runtime dependency.

## Tick and Performance Policy

```text
EnemyBase / State / Memory / Ground Locomotion / Audio   OFF
Perception Vision/Hearing/Damage                          event driven
Player Gaze                                               configured timer only
Action                                                     normally OFF; opt-in active action only
SurfaceCrawler                                             active move only
StateTree                                                  engine managed
AnimInstance                                               engine animation update; cached references/value reads
Debug                                                      OFF unless explicitly enabled
```

There are no per-frame logs. Invalid required runtime configuration logs actionable warnings; detailed inspection
belongs to the opt-in Debug layer.

## Data Validation

Validation rejects non-positive health, negative damage, invalid state/action tags, invalid enabled sense ranges,
invalid gaze interval/distance, incomplete/missing default movement profile, invalid or duplicate movement
profiles, null/invalid/duplicate Action Definitions, and invalid/duplicate Audio events or variants. Missing
authoring identity or StateTree is a warning because headless building blocks are supported. Validation does not
parse StateTree graphs to infer cross-system intent.

## Known Limitations

- Single-player reference scope; production replication, authority, and network smoothing are not validated.
- SurfaceCrawler supports connected static geometry, not arbitrary-surface path planning or moving platforms.
- `ACharacter` retains its capsule/CharacterMovement assumptions. Collision ON reference geometry is validated,
  but complex concave corners, narrow passages, dynamic obstacles, and arbitrary capsule orientation require
  project-specific PIE testing. A custom Pawn/movement solution is the recommended future path if truly arbitrary
  surface collision is required.
- Crawler uses placeholder presentation; production Animation Blueprint, root-motion policy, leg IK, and visual
  corner polish are not included. The common data provider is implemented, but no Montage/sequence is bundled.
- Audio event contracts are wired, but high-quality sounds/mixing are project content.
- Legacy `AJMDungeonMonster`, Listener/Hoarder/Blackout implementations are not migrated.

## Future Extensions

Consider Flying Locomotion, advanced target selection/EQS, multiplayer replication, Gameplay Debugger integration,
and richer editor tooling only when a concrete project needs them. A Rule layer was an early candidate, but
Listener, Watcher, and Crawler are fully expressible with StateTree. Add `UJMEnemyRule`/Rule Component only when a
real global constraint cannot be cleanly represented there.

## Migration Strategy

Migrate legacy AI one enemy at a time: analyze behavior; split senses, movement, and actions; create the Definition;
compose the StateTree; run the new and old enemy in parallel; then decide whether to retire the old implementation.
Do not replace all legacy AI in one step.
