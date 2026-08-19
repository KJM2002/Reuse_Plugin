---
title: "JMThrowable Architecture"
status: ReviewRequired
authority: Canonical
scope: "Plugin: JMThrowable"
classified_on: 2026-08-19
owners:
  - "JMThrowable Maintainers"
review_reason: "2026-08-19 전체 감사 이후 문서 구조만 정비했으며 모든 세부를 현재 코드와 재대조하지 않음"
---

# JMThrowable Architecture

## Responsibility

`JMThrowable` owns the item-use state machine, local player-view aim calculation,
fixed-step ballistic solver, first-hit procedural preview, projectile movement, collision
classification, timer-driven fuse/bursts, standard AI hearing noise, and idempotent
cleanup. It does not own inventory, inventory UI, project characters/cameras, sprint,
AI investigate/chase policy, save data, or networking.

`JMThrowableGameplayIntegration` is the consumer-side bridge for InventorySystem,
Enhanced Input, and optional generic CharacterMovement restriction.

## Dependencies

- Core runtime: Engine, EnhancedInput/InputCore, DeveloperSettings, ProceduralMesh,
  Niagara, AIModule, and JMGameplayEvent.
- Gameplay integration: JMThrowable, InventorySystem, EnhancedInput.
- InventorySystem never references JMThrowable.

## State and lifetime

The actor component owns one GUID-scoped session:

`Idle -> Ready -> Aiming -> CommittingThrow -> Idle`

RMB release only returns `Aiming -> Ready`. Q calls `CancelItemUse`, clears the entire
session, and consumes nothing. Cleanup is shared by cancel, successful commit, owner
end play, inventory replacement/removal, and inventory-open notification.

## Aim and simulation

Aim comes only from the local `PlayerController::GetPlayerViewPoint`. A visibility
profile trace still produces the center AimPoint for diagnostics, while launch
velocity is shared explicitly as
`Normalize(ViewForward) * ThrowSpeed + Up * VerticalThrowBoost`.

Runtime and preview origins are intentionally separate. `RuntimeThrowOrigin` is an
explicit throw component or the configurable view-relative spawn offset.
`PreviewVisualOrigin` is always
`ViewLocation + Normalize(ViewForward) * PreviewStartDistance`; it never receives
runtime right/vertical hand offsets. The two simulations therefore share forward,
speed, vertical boost, gravity, fixed step, radius, and collision policy while the
local visual begins exactly on the screen-center ray.

Preview and projectile share `FJMThrowSolver::Step`, including the fixed time step,
sphere sweep, gravity integration, ignored actors, collision profile, and projectile
radius. `SimulatePreview` intentionally terminates at the first blocking hit and ends
its point list at the exact impact point. It never visualizes bounce, slide, or rest
motion. Runtime `Simulate` and `UJMThrowableMovementComponent` continue through the
authored floor and non-floor collision-response policy unchanged.

`PreviewPointSpacing` filters the first-hit point list after simulation from the
already centered `PreviewVisualOrigin`; the first visible point and exact final point
are preserved.
`PreviewSpline` is hidden path data used only for distance-along-path evaluation.

## Preview renderer

The local-only renderer creates its components once and reuses them throughout the
component lifetime:

- `PreviewRibbon`: broad camera-facing translucent base trajectory with zero-alpha
  outer vertices and a soft center-weighted feather.
- `PreviewFlowRibbon`: a brighter, shorter procedural segment rebuilt every frame as
  it travels from start to end, followed by a short invisible loop gap. It is
  narrower than the base and fades to zero at both head and tail.
- `PreviewFlowOrb`: an asset-free low-poly sphere moving with the flow segment.
- `PreviewGlow`: optional supporting point light at the orb, not the visible orb.
- `PreviewImpactMarker`: an asset-free low-poly sphere at the first impact, offset by
  its radius plus `PreviewMarkerSurfaceOffset`.

Trajectory sweeps update at `PreviewUpdateHz`; flow/orb animation updates every
Aiming frame. No Actor is spawned for preview rendering. The trajectory material is
loaded once per item-use session and reused through transient MIDs. A missing material
can degrade the cosmetic but never blocks item use or projectile commit.

## Projectile visual and runtime response

`SphereCollision` remains the public root component and the solver remains a
deterministic sphere sweep for Blueprint/API compatibility. Visual representation is
separate and collision-disabled: an optional Definition soft mesh is preferred, then
the native procedural 8.5 x 5.5 x 2.2 cm box fallback is used. Cosmetic rotation does
not affect the sphere sweep.

The default non-floor response keeps only 8% of normal speed and 50% of tangential
speed for one weak deflection. Gravity is integrated on every later fixed step.

Floor response is independent. While incoming normal speed is at least
`FloorBounceStopSpeed` and the authored count is not exhausted, the solver applies:

`-NormalVelocity * FloorRestitution * Pow(FloorBounceDecay, FloorBounceCount)
 + TangentialVelocity * FloorTangentialDamping`

Each successful floor rebound remains `Flying` and publishes the existing bounce
event. When the speed/count gate closes, floor contact projects velocity onto the
surface, applies `FloorFriction`, and rests below `FloorStopSpeed`. Preview remains
first-hit-only and never displays these runtime bounces.

The current procedural preview is the dependency-free runtime fallback. For
art-directed production visuals, the preferred next renderer is a Niagara System
fed with the solver's first-hit `TArray<FVector>` through a Niagara Vector Array Data
Interface. See `NIAGARA_PREVIEW_GUIDE_KO.md`.

## Transaction policy

The Inventory Use Effect only starts Ready and must be authored with
`bConsumeOnUse=false`. On LMB, spawn validation occurs first, the projectile spawns,
then the bridge validates slot index, stable `InstanceId`, definition, quantity and
session GUID. Exactly one is removed. If commit fails, the spawned projectile is
destroyed and Aiming is restored.

## Failure and scope

Missing local view, definition, class, origin, input subsystem, movement component,
or preview material fails safely. Input and preview are local-only. Replication, save,
and authoritative multiplayer inventory are intentionally outside the current scope.
Projectile fuse, burst, audio/noise, and runtime collision policy remain independent
of preview cosmetics.
