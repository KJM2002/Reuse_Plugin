---
title: "Changelog"
status: ReviewRequired
authority: Historical
scope: "Plugin: JMPhysicalGrabber"
classified_on: 2026-08-19
owners:
  - "JMPhysicalGrabber Maintainers"
review_reason: "릴리스 및 Git 이력과 변경 항목의 누락 여부를 재대조하지 않음"
---

# Changelog

## Unreleased

### Fixed

- `TryGrab` now rejects missing/tearing-down Worlds before tracing or drawing debug geometry.
- Player Grapple now leaves Walking movement for every pull direction, preventing
  distance-driven footstep systems from treating winch velocity as rapid running.

## 1.8.0

### Added

- Crosshair visibility trace for close-range aim correction before deriving the muzzle shot direction.
- Short muzzle Sphere Sweep that converts an immediately blocked shot into a safe projectile impact.
- Dedicated sub-5 kg Light Pull model with distance-based target speed, acceleration clamp, tangential retention, angular damping, pull ramp, and automation coverage.
- `bUseLegacyKeyPolling` compatibility switch; project-owned Enhanced Input can call the existing Blueprint API without plugin asset dependencies.

### Changed

- `StartPlayerGrapple()` now arms the grapple while the projectile is flying, allowing direct Enhanced Input `Started` bindings.
- Light targets keep the projectile attached at the actual impact point while pull force and release braking operate at the center of mass.
- Light-target impact response uses an 80 cm/s center-of-mass velocity kick instead of the standard off-center impulse.
- Standard targets at or above 5 kg retain the existing impact-point spring pull and release-braking path.

### Fixed

- Prevented sub-5 kg targets from receiving extreme torque at impact, during recall, and at the soft-catch boundary.
- Reduced close-range crosshair/muzzle disagreement and handled muzzle-inside-geometry firing without relying on projectile movement to escape the overlap.

## 1.7.0

### Added

- Default contact-point Spline wire renderer with full-span Sphere Sweeps, up to three bounded surface contacts, contact lifetime hysteresis, and smoothed contact normals/positions.
- State-specific wire presentation: a taut flight line, slack-based embedded sag, and collision-routed recall.
- Automation coverage for outward surface offsets and deterministic sag endpoints/midpoint.

### Changed

- `UJMHarpoonGunComponent` now uses the Spline route by default while retaining `UCableComponent` as the `bUseSplineWire=false` fallback.
- Collision routing is capped at 25 Hz by default while render-point interpolation remains frame-rate driven.
- Visual collision radius and surface clearance are independent from the rendered wire width.

### Fixed

- Wire spans no longer depend on sparse Cable particles for ground and slope collision.
- Removed accumulated Verlet velocity from the default renderer, preventing jump-rope rotation after launch and explosive spinning after slope correction.
- Contact points are placed along the outward impact normal, keeping the rendered centerline above the surface instead of below it.

## 1.6.0

### Added

- Camera-independent cable-start proxy with a micro-jitter dead zone and bounded visual lag.
- State-driven visual winch length model with fixed slack limits and automation coverage.
- Recall-only WorldStatic cable collision, collision friction, tube-side count, world-space material tiling, and optional cable material settings.
- Hidden-cable tick suspension and tick ordering that updates the gun/proxy before CableComponent simulation.

### Changed

- The visual cable now feeds outward as needed, holds its rest length while flying or embedded, and reels inward only during recall.
- First-person defaults now use 16 segments, 12 solver iterations, 6 tube sides, reduced gravity, a thinner cable, and a 120 Hz simulation substep.
- Percentage slack is capped to a small fixed range so maximum-range shots do not become loose ropes.

### Fixed

- Reduced perpetual screen-space cable shimmer caused by camera micro-motion and bidirectional rest-length changes.
- Returning cable particles now sweep against WorldStatic geometry instead of passing through floors during recall.
- Prevented the launch-time jump-rope loop by reducing the hidden/initial rest length from 100 cm to 10 cm.
- Fast projectile endpoint motion now resets stale Verlet particle velocity after 25 cm instead of carrying rotational energy through the shot.

## 1.5.0

### Added

- Target-owned `IHarpoonInteractable` contract with embed, pull, reaction, and end callbacks.
- Data-driven `UJMHarpoonInteractableComponent` for Pull, Break, Extract, Activate, CreaturePart, and Anchor reactions.
- Sustained cable-force thresholds, pull resistance, fragile cargo condition, and generic AI-bridge noise events.
- Static-target tension reactions for removable obstacles without requiring rigid-body simulation.
- Editor automation coverage for extraction thresholds, fragile breakage, and pull-session reset.
- Korean step-by-step work-tool interaction guide with Blueprint recipes, test procedure, and troubleshooting.

### Changed

- `UJMHarpoonGunComponent` resolves target behavior through an interface while retaining legacy physics recall for targets that do not implement it.
- Interaction failure, reset, completion, and emergency recovery now terminate the target lifecycle explicitly.

## 1.4.1

### Added

- Camera-surface clearance and a predictive sphere sweep for player grappling, both exposed as Blueprint tuning values.

### Fixed

- Pulling toward ceilings, walls, and corners no longer allows the first-person camera to cross blocking geometry.
- Surface blocking removes only velocity into the hit normal, retaining useful tangential momentum.

## 1.4.0

### Added

- Optional player grappling feature with a Blueprint/runtime master switch and configurable input key.
- Right-mouse hold flow: arm while the projectile is flying, begin pulling on embed, and preserve release momentum.
- CharacterMovement-based acceleration, approach slowdown, tangential velocity retention, reduced grapple gravity, arrival braking, and FOV feedback.
- Static and optional dynamic physics anchors, blocked-progress cancellation, downward-speed limiting, maximum grapple duration, and Blueprint start/end events.

### Changed

- Harpoon recall, emergency recovery, invalid anchors, and feature disable now restore all temporarily overridden character movement values before continuing.

## 1.3.6

### Added

- Absolute recall deadline with an early emergency-return window and a final forced Ready-state fallback.

### Fixed

- Continuously falling or otherwise moving physics targets can no longer bypass the heavy-target progress timeout forever.
- Preserve the original recall elapsed time when emergency recreation occurs, preventing recovery from extending the deadline.

## 1.3.5

### Added

- Continuous harpoon fail-safe checks for invalid coordinates, excessive player distance, excessive vertical drop, and the world KillZ margin.
- Emergency return actor recreation in front of the player when the original projectile was already destroyed outside the world.

### Fixed

- A harpoon attached to a physics object that leaves the playable map can no longer be permanently lost with that object.

## 1.3.4

### Added

- Blueprint-visible `CableAnchor` on the projectile, positioned at the rear of the prototype harpoon.

### Fixed

- Attach the cable to `CableAnchor` with a zero end offset instead of attaching it to the front collision root.

## 1.3.3

### Added

- `MuzzleAssembly`, a shared Blueprint viewport transform for the muzzle mesh, loaded projectile preview, projectile spawn point, and cable origin.
- Blueprint viewport preview-class selection, assigned to `BP_JMHarpoonProjectile` in the sample visual Blueprint.

### Changed

- Scale authored on the muzzle assembly is transferred to the spawned projectile so loaded and flying presentation sizes remain consistent.

## 1.3.2

### Changed

- The loaded harpoon is now a non-gameplay child preview of `Projectile Class`, rather than separate loaded shaft and tip meshes.

### Fixed

- Projectile Blueprint mesh, material, location, rotation, and scale edits now appear identically in the loaded and fired states.
- The loaded preview has collision, movement, ticking, and impact light disabled so it cannot affect gameplay.

## 1.3.1

### Added

- Blueprint cable tuning for segment count, solver iterations, width, gravity, substep time, length interpolation, and slack.
- Ground height and normal response tuning for smoother uneven-floor following.
- Return separation distance that moves an embedded spear out of its hit surface before recall.

### Fixed

- Release close and overlapping physics targets using their nearest collision-surface distance instead of relying only on the off-center embedded point.
- Skip pendulum-like force pulling for a physics target that is already inside the release radius when recall starts.
- Detach the spear and perform a short final lift instead of destroying it immediately when a physics target reaches the player.
- Interpolate cable length, reduce cable gravity, reduce segment count, and increase solver iterations to suppress rope whipping.
- Smooth floor height and normal changes and complete return when the movement segment crosses the muzzle catch sphere, preventing projectile bounce and overshoot.

## 1.3.0

### Added

- Ground-aware free-harpoon recall with an airborne floor search, floor dragging, slope/step following, ledge falling, and a short final muzzle lift.
- Blueprint tuning for ground drag speed, responsiveness, clearance, probe distance, step height, lift distance, search timeout, and minimum floor normal.
- No-floor safety fallback that preserves guaranteed recall without enabling rigid-body simulation.
- Korean illustrated component poster distinguishing visible gun/projectile meshes from editor-only functional components.

### Changed

- Free harpoons now fall all the way to a usable floor and scrape back along it instead of curving directly through the air.
- Floor queries use WorldStatic, WorldDynamic, and PhysicsBody object types rather than depending on the Visibility response.

## 1.2.0

### Added

- Blueprint-editable `AJMHarpoonGunVisualActor` with exposed body, handle, barrel, muzzle, winch, loaded shaft, loaded tip, and muzzle point components.
- Blueprintable harpoon projectile with exposed shaft, tip, fins, collision, movement, and impact-light components.
- Project-side `BP_JMHarpoonGunVisual` and `BP_JMHarpoonProjectile` presentation assets, assigned to `BP_FirstPersonCharacter`.
- Complete Korean harpoon gun usage, tuning, visual-editing, API, and test guide.

### Changed

- Projectile basic meshes are native constructor defaults, so a Blueprint's mesh and material overrides are no longer replaced during `BeginPlay`.

## 1.1.0

### Added

- Fast swept harpoon projectile with embed and guaranteed recall behavior.
- Mass-aware physics-target pulling and heavy-target release timeout.
- Runtime Cable Component rope.
- First-person pirate harpoon prototype assembled from engine basic shapes.
- Fire, impact, recall, and return Blueprint events.

### Changed

- `BP_FirstPersonCharacter` integration uses the harpoon gun for left click and disables the legacy direct Grabber component.

### Fixed

- Configure Cable segment and solver counts before component registration so its internal particle array matches `NumSegments` during Tick.
- Stop the prototype winch at its current angle while the harpoon is embedded; it rotates only during flight and recall.
- Add a physics-target soft-catch radius and inward-velocity braking so recalled objects release in front of the player instead of overshooting behind them.
- Replace straight-line free return with a lightweight gravity-to-homing arc so the harpoon drops naturally before the winch pulls it back.

## 1.0.0

### Added

- Force-limited, mass-aware grab and release component.
- Toggle or hold input modes, safety break distance, optional mass cap, debug drawing, and Blueprint events.
