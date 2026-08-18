# JM Monster Framework

`JMMonsterFramework` is a standalone Unreal Engine 5.7 runtime plugin for composing data-driven enemy AI.

## Phase 7 surface

- `AJMEnemyBase`: minimal framework container
- `UJMEnemyDefinition`: identity, baseline stats, and initial state
- `UJMEnemyStateComponent`: GameplayTag state ownership and transition delegate
- `JM.Enemy.State.*`: native core state tags
- `AJMEnemyAIController`: thin Unreal AI Perception adapter
- `UJMEnemyPerceptionComponent`: normalized Vision, Hearing, Player Gaze, and Damage stimuli
- `UJMEnemyMemoryComponent`: explicit target ownership and event-driven sensory history
- `UJMEnemyLocomotionComponent`: event-driven ground navigation command facade
- `UJMEnemyMovementSet`: named, reusable CharacterMovement profiles
- `UJMEnemyActionComponent`: runtime action lookup, execution, cancellation, and cooldown facade
- `UJMEnemyAction`: timer-safe, opt-in lifecycle base
- `UJMEnemyAction_Melee` / `UJMEnemyAction_Scream`: reference actions
- `UJMEnemyStateTreeComponent`: controller-owned, possession-scoped StateTree runner
- StateTree tasks: state, movement, facing, profile, escape, action, and encounter commands
- StateTree conditions: target, sight, hearing, gaze, distance, encounter, and state queries
- `FJMStateTreeContextEvaluator`: lightweight binding snapshot for behavior assets
- reusable target-policy, explicit target assignment/clear, action-readiness, target-hearing, and random NavMesh building blocks
- `JM.Enemy.Event.Stimulus`: event-driven wake-up bridge from normalized perception to StateTree
- `BP_Enemy_Listener`, `DA_Enemy_Listener`, `ST_Listener`, and definition-local movement/melee assets under Plugin Content

The plugin does not depend on the host game's `P_060715` module or any other JM gameplay plugin. It does not modify or replace existing monsters, controllers, Behavior Trees, or `/Game` assets.

## Engine dependencies

- AI Module
- Gameplay Tags
- Navigation System
- StateTree
- Gameplay StateTree

The Listener reference is a hearing-first vertical slice: Patrol, investigate evidence without assigning a combat
target, explicitly confirm an eligible player pawn, Chase, Melee Attack, Search last-known space, and return to
Patrol. It is assembled from generic framework nodes rather than a Listener-specific C++ enemy class or branch.

Phase 7 does not add surface crawling, enemy-specific runtime rules, audio playback, or debug systems. Player Gaze
is the only periodic perception query and its timer exists only when the definition enables it; other memory updates
and StateTree stimulus wake-ups are event-driven.
