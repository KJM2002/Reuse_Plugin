---
title: "JM Physical Grabber Architecture"
status: ReviewRequired
authority: Canonical
scope: "Plugin: JMPhysicalGrabber"
classified_on: 2026-08-19
owners:
  - "JMPhysicalGrabber Maintainers"
review_reason: "2026-08-19 전체 감사 이후 문서 구조만 정비했으며 모든 세부를 현재 코드와 재대조하지 않음"
---

# JM Physical Grabber Architecture

The runtime module contains two independent pawn components.

Version 1.5 adds a target-owned interaction layer without changing that ownership. `IJMHarpoonInteractable` exposes an interaction profile and lifecycle callbacks; `UJMHarpoonInteractableComponent` is the reusable data-driven implementation. The gun resolves the interface from the hit primitive, actor, or one of the actor's components in that order. It never casts to cargo, creature, door, portal, or project classes.

The profile controls embed/pull permission, pull resistance, reaction kind, sustained-force threshold, fragile-force budget, and generic impact/pull noise. `Break`, `Extract`, `Activate`, and `CreaturePart` complete only after their force threshold is sustained for the configured time. `Pull` preserves normal rigid-body recall, and `Anchor` can reserve a target for player grappling. Interface-free targets keep the pre-1.5 legacy behavior.

Noise is emitted as a Blueprint multicast signal rather than sent directly to an AI implementation. Inventory rewards, objective progress, monster state, door state, and portal state likewise subscribe to `OnReactionCompleted` in a game-side Blueprint or a separate integration plugin. This keeps the runtime module independent and prevents reverse dependencies.

`UJMPhysicalGrabberComponent` performs short-range direct grabbing. It stores a hit point in component-local space and pulls it toward a view-relative target with a damped spring and fixed force budget.

`UJMHarpoonGunComponent` owns a four-state harpoon lifecycle: `Ready`, `Flying`, `Embedded`, and `Retracting`. It spawns a configurable `AJMHarpoonProjectile` subclass, connects its muzzle to the projectile with a presentation-only wire route, and spawns a configurable `AJMHarpoonGunVisualActor` subclass for the first-person presentation. Both native actor classes use `/Engine/BasicShapes` defaults and expose their component parts to Blueprint children. No `/Game` content is referenced by the plugin.

The sample project supplies `BP_JMHarpoonGunVisual` and `BP_JMHarpoonProjectile` as data-only presentation overrides. Gameplay state remains in `UJMHarpoonGunComponent`; changing presentation Blueprints does not duplicate fire, embed, pull, or recall logic. `MuzzlePoint` is the shared source for spawning and the cable start, so presentation edits stay aligned with gameplay.

Every blocking primitive is a valid embed surface. Physics primitives receive an impact impulse and are pulled at the stored local hit point during recall. Static primitives release the projectile for a kinematic ground-return path. A physics target that makes insufficient progress within the heavy-target timeout also releases the projectile, guaranteeing that the harpoon can always return.

Physics-target release uses the nearest collision-surface distance as well as the embedded grab-point distance. This prevents large or close targets from overlapping the player while their off-center hit point remains outside the release radius. A released spear is moved backward out of the hit surface before its collision-free return begins. At close range it skips the floor-search phase and blends directly into the muzzle lift.

A free returning harpoon uses a three-phase kinematic path instead of rigid-body simulation. It first falls under procedural gravity and sphere-sweeps for a floor, then follows that floor with a short downward trace while being dragged toward the player, and finally lifts into the muzzle at close range. Small slopes, steps, and floor edges are supported; falling resumes after an edge. A search timeout switches to direct final homing when no usable floor exists, preserving guaranteed recovery.

The standard pull force is intentionally not multiplied by mass, so heavier bodies accelerate less. Public fire, recall, reset, grapple, state, and event APIs are independent from the optional legacy input path. Destroyed projectiles, destroyed targets, invalid owners, maximum range, component end play, and level teardown all fail into a safe reset or return path.

Version 1.8 makes direct key polling an opt-in compatibility path. The plugin does not reference project Input Action assets; a Character or Controller owns Enhanced Input and calls `FireHarpoon`, `RecallHarpoon`, `StartPlayerGrapple`, and `StopPlayerGrapple`. `StartPlayerGrapple` can arm during flight so the same public API covers both flight and embedding.

Aim direction now comes from a camera-center visibility trace when it hits within range, then converges from the actual muzzle to that point. A short muzzle sphere sweep handles an immediately blocking surface as a real projectile impact. The projectile remains authoritative for all other flight collision.

Physics recall has two explicit paths. Targets with mass strictly below the configurable 5 kg threshold keep their visual embed point but use center-of-mass velocity control: distance-based target speed, retained tangential velocity, clamped acceleration, a short output ramp, and bounded angular deceleration. Their impact and release impulses are center-of-mass velocity changes. Targets at or above the threshold retain the original off-center impact impulse, `AddForceAtLocation` spring, mass-dependent response, soft catch, and heavy-target timeout.

The version 1.7 default is `UJMHarpoonWireRouteComponent`, not a particle rope. It sphere-sweeps each complete route span, stores at most three surface contacts, and renders a bounded pool of Spline Mesh segments. Contacts use an outward collision-radius-plus-clearance offset, minimum lifetime, wider release sweep, smoothed normals and positions, and a per-update correction cap. This removes the sparse-particle gaps and stored rotational velocity responsible for ground penetration and jump-rope motion.

Route collision runs at a bounded 25 Hz by default and only when the route moves or has live contacts. Large endpoint teleports force an immediate rebuild. Render points interpolate every frame. Flight clears contacts and renders taut; embedding permits a small slack-derived parabolic sag; recall enables surface routing. The renderer is visual only and never owns pull forces.

`UCableComponent` remains instantiated as a compatibility fallback selected with `bUseSplineWire=false`. Its particle counts and solver properties are configured before registration. Runtime cable length changes are interpolated, with reduced cable gravity and a shorter, more strongly solved segment chain to suppress whipping during ground drag.

Version 1.6 routes the cable start through an unattached world-space proxy. The gun updates this proxy before CableComponent tick, filters sub-centimeter camera jitter, and limits lag during fast turns. A pure winch-length model feeds out monotonically during flight/embedding and reels inward only during recall, preventing endpoint jitter from alternately changing the Verlet rest length. Percentage slack is clamped to fixed world-space bounds.

Fallback Cable collision remains presentation-only and is enabled solely during the bounded recall window. The default Spline route and fallback Cable both query WorldStatic; WorldDynamic is opt-in to avoid feedback against the pulled target. Hidden fallback simulation is disabled. Gameplay tension and target forces remain independent from either renderer, so visual collision cannot alter authoritative pull behavior.

The module depends only on Unreal runtime modules and the built-in Cable Component plugin. Interaction and wire contacts are local and transient; server-authoritative multiplayer and save ownership are outside version 1.7.0. The bounded route intentionally does not simulate knots, frictional rope tension, or a full XPBD rope. Invalid or destroyed targets fall back to guaranteed harpoon recovery.
