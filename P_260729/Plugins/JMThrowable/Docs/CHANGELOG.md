# Changelog

## 1.3.0

- Added an independent, strongly damped floor-bounce policy to the fixed-step solver.
- Added configurable maximum floor bounces, restitution, tangential damping,
  per-bounce decay, and incoming-speed stop threshold.
- Preserved the wall response and first-hit-only preview behavior.
- Floor bounces now publish the existing `OnBounced` event; the final settle still
  publishes `OnRested` once.
- Migrated `DA_Throwable` to three maximum floor bounces with 0.20 restitution,
  0.60 tangent retention, 0.60 decay, and an 80 cm/s incoming-speed threshold.
- Added floor-bounce decay and finite-settle automation coverage.
- Added a Niagara trajectory migration guide while retaining the current native
  procedural renderer as the working fallback.

## 1.2.0

- Split the runtime throw origin from the camera-centered preview visual origin.
- Added shared camera-forward launch velocity with configurable vertical throw boost.
- Reworked the base/flow ribbons with broad feathered edges and exact flow head/tail fade.
- Reduced the flow orb, impact marker, and optional glow to unobtrusive defaults.
- Added low-energy wall deflection and floor settle defaults while retaining the
  deterministic fixed-step sphere solver.
- Added optional soft visual mesh/material settings and an asset-free
  8.5 x 5.5 x 2.2 cm native box fallback with cosmetic spin.
- Migrated `DA_Throwable` to the new preview, launch, and collision defaults.
- Rebuilt `M_ThrowableTrajectory` as Translucent/Unlit/Two-Sided with
  `VertexColor.RGB -> Emissive` and `VertexColor.A -> Opacity`.
- Added centered-origin, flow-width, low-restitution, post-wall gravity, and floor
  settle automation coverage.

## 1.1.0

- Changed preview simulation to stop at the first blocking hit while preserving the
  existing runtime projectile bounce and floor policies.
- Added an animated procedural white flow highlight and visible asset-free flow orb.
- Added an asset-free first-impact marker using `PreviewEndMarkerSize`.
- Applied `PreviewPointSpacing` and added configurable preview start, flow, loop-gap,
  orb-size, and marker-offset settings.
- Split trajectory recomputation at `PreviewUpdateHz` from frame-rate animation.
- Cached trajectory material resources for each item-use session.
- Extended centralized cleanup to every new preview renderer and animation state.
- Added first-hit, single-impact, no-hit, and runtime-bounce regression tests.

## 1.0.0

- Added GUID-scoped Ready/Aiming/Committing item-use state machine.
- Added player-view center aim, fixed-step solver, spline preview and solver-driven projectile.
- Added floor stop, one non-floor bounce, blocked-spawn validation and centralized cleanup.
- Added configurable settings, Blueprint events and automation coverage.
- Replaced expiring debug preview strokes with a stable, thin white world-space line batch.
- Explicitly ignores the throwing actor for projectile collision.
- Fixed the solver sweep colliding with the projectile itself on its first movement step.
- Added tapered dual-layer white trajectory strokes and a landing marker.
- Replaced final debug rendering with a translucent procedural ribbon and moving glow light.
- Added configurable floor slide/stop, surface offset, surface classification and dynamic-object impulse.
- Added timer-driven fuse, repeated Niagara/sound/light/noise bursts, AI Hearing reports and gameplay events.
