# JM Physical Grabber Architecture

The runtime module contains two independent pawn components.

Version 1.5 adds a target-owned interaction layer without changing that ownership. `IJMHarpoonInteractable` exposes an interaction profile and lifecycle callbacks; `UJMHarpoonInteractableComponent` is the reusable data-driven implementation. The gun resolves the interface from the hit primitive, actor, or one of the actor's components in that order. It never casts to cargo, creature, door, portal, or project classes.

The profile controls embed/pull permission, pull resistance, reaction kind, sustained-force threshold, fragile-force budget, and generic impact/pull noise. `Break`, `Extract`, `Activate`, and `CreaturePart` complete only after their force threshold is sustained for the configured time. `Pull` preserves normal rigid-body recall, and `Anchor` can reserve a target for player grappling. Interface-free targets keep the pre-1.5 legacy behavior.

Noise is emitted as a Blueprint multicast signal rather than sent directly to an AI implementation. Inventory rewards, objective progress, monster state, door state, and portal state likewise subscribe to `OnReactionCompleted` in a game-side Blueprint or a separate integration plugin. This keeps the runtime module independent and prevents reverse dependencies.

`UJMPhysicalGrabberComponent` performs short-range direct grabbing. It stores a hit point in component-local space and pulls it toward a view-relative target with a damped spring and fixed force budget.

`UJMHarpoonGunComponent` owns a four-state harpoon lifecycle: `Ready`, `Flying`, `Embedded`, and `Retracting`. It spawns a configurable `AJMHarpoonProjectile` subclass, connects its muzzle to the projectile with Unreal's `UCableComponent`, and spawns a configurable `AJMHarpoonGunVisualActor` subclass for the first-person presentation. Both native actor classes use `/Engine/BasicShapes` defaults and expose their component parts to Blueprint children. No `/Game` content is referenced by the plugin.

The sample project supplies `BP_JMHarpoonGunVisual` and `BP_JMHarpoonProjectile` as data-only presentation overrides. Gameplay state remains in `UJMHarpoonGunComponent`; changing presentation Blueprints does not duplicate fire, embed, pull, or recall logic. `MuzzlePoint` is the shared source for spawning and the cable start, so presentation edits stay aligned with gameplay.

Every blocking primitive is a valid embed surface. Physics primitives receive an impact impulse and are pulled at the stored local hit point during recall. Static primitives release the projectile for a kinematic ground-return path. A physics target that makes insufficient progress within the heavy-target timeout also releases the projectile, guaranteeing that the harpoon can always return.

Physics-target release uses the nearest collision-surface distance as well as the embedded grab-point distance. This prevents large or close targets from overlapping the player while their off-center hit point remains outside the release radius. A released spear is moved backward out of the hit surface before its collision-free return begins. At close range it skips the floor-search phase and blends directly into the muzzle lift.

A free returning harpoon uses a three-phase kinematic path instead of rigid-body simulation. It first falls under procedural gravity and sphere-sweeps for a floor, then follows that floor with a short downward trace while being dragged toward the player, and finally lifts into the muzzle at close range. Small slopes, steps, and floor edges are supported; falling resumes after an edge. A search timeout switches to direct final homing when no usable floor exists, preserving guaranteed recovery.

The fixed pull force is intentionally not multiplied by mass, so heavier bodies accelerate less. Input is polled only for the owning local player; Blueprint callers can instead use the public fire, recall, reset, state, and event API. Destroyed projectiles, destroyed targets, invalid owners, maximum range, component end play, and level teardown all fail into a safe reset or return path.

Cable particle counts and solver properties are configured before registration. Runtime cable length changes are interpolated, with reduced cable gravity and a shorter, more strongly solved segment chain to suppress whipping during ground drag.

The module depends only on Unreal runtime modules and the built-in Cable Component plugin. Interaction state is local and transient; server-authoritative multiplayer, save ownership, and rope/world collision are outside version 1.5.0. Invalid or destroyed targets fall back to guaranteed harpoon recovery.
