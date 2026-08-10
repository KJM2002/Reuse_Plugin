# JM Physical Grabber and Harpoon Gun

작살총의 전체 한글 사용 및 튜닝 문서는 [HARPOON_GUN_KO.md](HARPOON_GUN_KO.md)를 참고하세요.

## Harpoon Gun

Add `JM Harpoon Gun Component` to a locally controlled pawn. Left click fires; left click again recalls. The projectile embeds in every blocking primitive. Physics targets are pulled toward the muzzle, while static or immovable targets release the projectile and return only the harpoon.

The optional Player Grapple mode uses right-mouse hold after firing. Pressing it during flight arms the grapple; an embedded projectile then pulls an `ACharacter` toward the anchor through CharacterMovement while retaining sideways momentum. A predictive camera sphere sweep stops inward velocity before ceilings and walls can clip the first-person view. Disable `Enable Player Grapple` to keep the original harpoon-only behavior.

The component creates a prototype gun from the engine Cube, Cylinder, and Cone meshes. It also creates a built-in Cable Component between the muzzle and projectile. No project content is required.

The sample project exposes both presentations as editable Blueprint children:

- `/Game/FirstPerson/Blueprints/BP_JMHarpoonGunVisual`: edit `Body`, `Handle`, `Barrel`, `Muzzle`, and `Winch` in the Components panel or viewport. Select `MuzzleAssembly` to move, rotate, or scale the muzzle, loaded projectile, projectile spawn point, and cable origin together. `MuzzlePoint` remains available as a fine local offset.
- `/Game/FirstPerson/Blueprints/BP_JMHarpoonProjectile`: edit `Shaft`, `Tip`, `FinA`, `FinB`, `CableAnchor`, `Collision`, and `ImpactLight`. Move `CableAnchor` to the rear end of a customized projectile mesh. Meshes, materials, transforms, collision size, and light values can be changed without rebuilding C++. The same complete visual is used while loaded and after firing.

`BP_FirstPersonCharacter`'s `JMHarpoonGun` component references both classes through `Visual Actor Class` and `Projectile Class`. `Gun Visual Offset` moves the complete gun relative to the first-person camera.

Recommended test objects use `Movable`, `Simulate Physics`, and the `PhysicsActor` collision preset. Compare mass overrides of 5 kg, 75 kg, and 300 kg. Default `Max Pull Force` is 200000 kg*cm/s^2, and targets that make less than 100 cm of progress over 1.5 seconds release the harpoon.

Important tuning values:

- `Fire Speed` and `Max Range`: projectile speed and automatic recall distance.
- `Impact Impulse` and `Embed Depth`: impact response.
- `Max Pull Force`, `Pull Strength`, and `Pull Damping`: mass-aware recall feel.
- `Physics Release Distance`: soft-catch radius that keeps recalled objects in front of the player.
- `Release Braking`: removes inward momentum at the soft-catch radius to prevent overshoot behind the player.
- `Return Gravity` and `Return Initial Drop Speed`: control how the free harpoon falls until it reaches a usable floor.
- `Return Ground Drag Speed` and `Return Ground Drag Responsiveness`: tune the floor-scraping recall.
- `Return Ground Clearance`, probe distance, step height, and minimum normal Z: tune floor detection and slope following.
- `Return Ground Lift Distance`: controls where the harpoon leaves the floor and lifts into the muzzle.
- `Return Ground Search Timeout`: guarantees recovery in maps with no floor below the harpoon.
- `Return Gravity Fade Time` and `Return Homing Responsiveness`: tune the final lift from the floor into the muzzle.
- `Cable Num Segments`, solver iterations, gravity scale, and length interpolation: tune rope stability without changing Cable settings after registration.
- `Player Grapple Camera Clearance` and `Player Grapple Camera Probe Radius`: tune first-person camera clearance near ceilings, walls, and corners.
- `Return Separation Distance`: pulls the spear out of an overlapped hit surface before recall.
- `Heavy Target Timeout`: guarantees recovery from immovable targets.
- `Muzzle Offset` and `Gun Visual Offset`: first-person placement.
- `Draw Debug`: displays aim and impact markers.

## Direct Grabber

`JM Physical Grabber Component` remains available for short-range direct grabbing. Its fixed force budget is not multiplied by mass, so heavy bodies lag or can only be dragged.

The plugin requires the built-in Unreal Cable Component plugin and has no dependency on project content or other JM plugins. The two sample Blueprints are optional project-side overrides; deleting them and selecting the native classes restores the built-in prototype.
