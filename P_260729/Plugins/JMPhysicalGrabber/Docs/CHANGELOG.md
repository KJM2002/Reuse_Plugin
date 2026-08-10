# Changelog

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
