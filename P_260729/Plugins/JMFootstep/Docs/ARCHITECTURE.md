# JMFootstep Architecture

## Responsibility boundary

JMFootstep owns actual 2D movement measurement, distance-based step timing, automatic
Walk/Run/CrouchWalk classification, grounded validation, floor tracing, physical
material and physical surface resolution, data-driven profile lookup, one-shot
spatial audio selection/playback, locomotion-specific sound variants,
immediate-repeat avoidance, result reporting,
logical left/right alternation, delegates, and opt-in debug output.

It does not own input, character movement, animation, AI hearing, camera effects,
inventory, UI, landing/jump audio, footprints, VFX, persistence, or replication.

## Modules and dependencies

- `JMFootstepRuntime`: Runtime-only component, settings, data assets, and public contracts.
- `JMFootstepTests`: Editor-only automation tests.

The Runtime module depends only on `Core`, `CoreUObject`, `Engine`,
`DeveloperSettings`, and `PhysicsCore`. It has no JM plugin dependency and no
Editor-only dependency. `JMGameplayEvent` is intentionally not required; consumers
subscribe to the component delegate.

## Lifetime and flow

`UJMFootstepComponent` is an Actor Component intended for `ACharacter`. It stores
only per-owner transient state: previous location, accumulated distance, logical
foot, and last sound index per profile/selected variant.

```text
actual XY delta -> accumulator -> state step threshold
-> grounded check -> floor trace -> physical material -> physical surface
-> footstep set -> surface profile -> locomotion variant
-> sound selection -> world one-shot audio
-> result -> OnFootstepPlayed
```

Tick performs only position/state/distance work. Trace, profile lookup, random
selection, and audio playback occur only when a step threshold is crossed.
Falling/non-walking movement clears pending distance. A delta over the teleport
threshold resets the accumulator. Per-frame processing is capped.

## Locomotion detection

Automatic state uses actual 2D displacement speed, not input:

- below minimum speed: Idle
- crouched Character: CrouchWalk
- at/above configured run threshold: Run
- otherwise: Walk

Only Character Movement `Walking` and `NavWalking` modes are grounded. Manual
locomotion override takes priority, but it does not bypass grounded validation.
Automatic Idle never creates a request. A manual request that resolves to Idle
returns `NotMoving`; it never silently substitutes Walk.

## Trace and surface resolution

For Characters, trace origin is calculated from capsule bottom plus the configured
start offset. The query ignores the owner and enables physical-material return.
A manual request may provide an explicit trace origin.

If the hit has no Physical Material, the set's default profile is attempted.
If a known surface has no mapping, the same default profile is attempted. Missing
trace, profile, or sound returns a structured failure and never crashes.

## Data and loading policy

`UJMFootstepSettings` stores a config-safe soft reference to the default
`UJMFootstepSet`; the component resolves it synchronously when needed. A set maps arbitrary
`EPhysicalSurface` values to `UJMFootstepSurfaceProfile` assets and has a default
fallback. Profiles hold Walk/Run/CrouchWalk sound variants and shared Attenuation.

## Locomotion sound variants and compatibility

`FJMFootstepSoundVariant` owns a sound array plus its natural volume/pitch random
range. `UJMFootstepSurfaceProfile` owns `WalkVariant`, `RunVariant`, and
`CrouchWalkVariant`.

The v1.0 profile fields (`Sounds`, `VolumeMin`, `VolumeMax`, `PitchMin`, and
`PitchMax`) remain serialized and editable as a Legacy fallback. They are not
removed or renamed, so existing profile assets continue to load. Resolution is:

```text
Walk:       WalkVariant -> Legacy
Run:        RunVariant -> WalkVariant -> Legacy
CrouchWalk: CrouchWalkVariant -> WalkVariant -> Legacy
Idle:       NotMoving
```

A variant is usable when it contains at least one non-null sound. Null entries are
ignored. Result reports both requested locomotion state and the variant state
actually selected, plus whether fallback occurred. Legacy selection reports
`bUsedLegacyVariant`.

Variant selection does not replace the requested locomotion state. Automatic
distance accumulation resolves the step threshold from the detected/requested
state before playback, and final volume resolves its state multiplier from that
same requested state. Therefore Run/CrouchWalk using a Walk sound fallback still
uses Run/CrouchWalk step distance and volume settings.

Immediate-repeat history is keyed by Profile plus selected variant state. Legacy
uses its own history slot. Switching Walk -> Run -> Walk therefore preserves the
previous Walk choice without allowing Run history to interfere.

Final volume is:

```text
variant random volume
* locomotion state volume multiplier
* component/project base volume
* request context volume
```

Final pitch is variant random pitch multiplied by component/project and request
context pitch multipliers. Variant ranges describe recording variation; Settings
state multipliers describe the relative loudness of each gait.

## Surface Profile editor layout

Each state Variant remains a serialized `FJMFootstepSoundVariant` property. The
Details panel keeps the outer `Footstep|Walk`, `Footstep|Run`, and
`Footstep|Crouch Walk` groups and displays a nested, collapsible Variant row.
Variant child fields share the neutral `Footstep` category metadata.

`ShowOnlyInnerProperties` is intentionally not used: flattening the structure while
its child fields used independent `Audio`/`Variation` categories caused those
children to be promoted into duplicate top-level categories. This is an editor
metadata-only correction. Property names, types, ownership, and serialized data
remain unchanged.

Version 1 uses a soft settings reference for the root Set and hard references from
the Set to profiles/sounds because a step must resolve synchronously and the
configured table is expected to be small and always-ready during play. This avoids
asynchronous stale-callback complexity. Projects with very large sound libraries
should add a separate preloading/streaming integration rather than changing the
Core command contract implicitly.

## Settings precedence

Request context multipliers -> enabled Component overrides -> Project Settings
-> safe C++ defaults.

The request context can override trace origin and multiply volume/pitch. Component
overrides cover movement thresholds/distances, trace configuration, teleport cap,
and base volume/pitch. Project Settings appear under `JM Plugins > Footstep`.

## Context, result, and delegate

`FJMFootstepContext` carries instigator, optional trace origin, requested locomotion
state/logical foot, volume/pitch multipliers, and an optional name tag.
`FJMFootstepResult` exposes success/failure, resolved state/foot/surface/material,
selected sound, impact geometry, and final volume/pitch.

Both automatic and manual entry points use the same request path. Only successful
playback broadcasts `OnFootstepPlayed`; callers receive failures directly as Result.
Delegates run synchronously on the game thread after one-shot playback is requested.

## Performance and cleanup

No timer, async load, persistent Audio Component, or external delegate subscription
is created. EndPlay resets transient state. Inactive/invalid components do no work.
Debug drawing/logging is opt-in and compiled out of Shipping/Test debug paths.

## Network, AI, and extension scope

Version 1 is local single-player cosmetic detection/audio. It provides no RPC,
authority validation, or replication. AI hearing is deliberately outside Core;
an adapter may consume `OnFootstepPlayed`. The Result's logical foot and impact
data are extension points for decals, dust, splashes, camera feedback, or other
consumer-owned effects.
