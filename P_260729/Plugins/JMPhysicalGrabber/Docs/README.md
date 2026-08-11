# JM Physical Grabber and Harpoon Gun

작살총의 전체 한글 사용 및 튜닝 문서는 [HARPOON_GUN_KO.md](HARPOON_GUN_KO.md)를 참고하세요. 화물, 파손, 추출, 소음, 포탈 코어 설정은 [WORK_TOOL_INTERACTIONS_KO.md](WORK_TOOL_INTERACTIONS_KO.md)에 단계별로 정리되어 있습니다.

## Harpoon Gun

Add `JM Harpoon Gun Component` to a locally controlled pawn. Left click fires; left click again recalls. The projectile embeds in every blocking primitive. Physics targets are pulled toward the muzzle, while static or immovable targets release the projectile and return only the harpoon.

The optional Player Grapple mode uses right-mouse hold after firing. Pressing it during flight arms the grapple; an embedded projectile then pulls an `ACharacter` toward the anchor through CharacterMovement while retaining sideways momentum. A predictive camera sphere sweep stops inward velocity before ceilings and walls can clip the first-person view. Disable `Enable Player Grapple` to keep the original harpoon-only behavior.

The component creates a prototype gun from engine basic meshes. Its default wire uses full-span Sphere Sweeps, bounded surface contacts, and Spline Mesh rendering; the built-in Cable Component remains an optional fallback. No project content is required.

## Data-driven work-tool interactions

Add `JM Harpoon Interactable Component` to a target actor. Configure its `Profile`; the gun discovers it automatically and does not need a target-class branch. The component exposes `On Reaction Completed`, `On Harpoon Noise`, and `On Condition Changed` for game-side Blueprint integration.

Recommended Vertical Slice profiles:

| Target | Reaction and important values |
| --- | --- |
| Ordinary cargo | `Pull`, Can Pull; use rigid-body mass for the speed difference |
| Fragile cargo | `Pull`, Fragile Safe Force > 0; condition falls only above the safe force |
| Creature resource part | `Extract`, Can Extract, Reaction Force/Hold Time |
| Removable obstacle | `Break`, Can Break, Reaction Force/Hold Time; static meshes are supported |
| Metal noise prop | `Pull`, Impact/Pull Noise Loudness; bridge the noise event to AI |
| Portal core | `Pull`, high physics mass/Pull Resistance, high Pull Noise Loudness |

`Activate` supports levers and valves, `CreaturePart` supports non-lethal creature disruption, and `Anchor` with `Can Pull=false` describes player-movement anchors. Targets can instead implement `IHarpoonInteractable` in C++ or Blueprint when their response needs custom state.

The sample project exposes both presentations as editable Blueprint children:

- `/Game/FirstPerson/Blueprints/BP_JMHarpoonGunVisual`: edit `Body`, `Handle`, `Barrel`, `Muzzle`, and `Winch` in the Components panel or viewport. Select `MuzzleAssembly` to move, rotate, or scale the muzzle, loaded projectile, projectile spawn point, and cable origin together. `MuzzlePoint` remains available as a fine local offset.
- `/Game/FirstPerson/Blueprints/BP_JMHarpoonProjectile`: edit `Shaft`, `Tip`, `FinA`, `FinB`, `CableAnchor`, `Collision`, and `ImpactLight`. Move `CableAnchor` to the rear end of a customized projectile mesh. Meshes, materials, transforms, collision size, and light values can be changed without rebuilding C++. The same complete visual is used while loaded and after firing.

`BP_FirstPersonCharacter`'s `JMHarpoonGun` component references both classes through `Visual Actor Class` and `Projectile Class`. `Gun Visual Offset` moves the complete gun relative to the first-person camera.

Recommended test objects use `Movable`, `Simulate Physics`, and the `PhysicsActor` collision preset. Compare mass overrides of 5 kg, 75 kg, and 300 kg. Default `Max Pull Force` is 200000 kg*cm/s^2, and targets that make less than 100 cm of progress over 1.5 seconds release the harpoon.

Input can be project-owned without plugin asset dependencies. Bind Enhanced Input actions in the Character or Controller to `FireHarpoon`, `RecallHarpoon`, `StartPlayerGrapple`, and `StopPlayerGrapple`, then disable `Use Legacy Key Polling`. The compatibility option remains enabled by default in 1.8 so existing prototype controls continue to work until those bindings are added.

Important tuning values:

- `Fire Speed` and `Max Range`: projectile speed and automatic recall distance.
- `Impact Impulse` and `Embed Depth`: impact response.
- `Crosshair Aim Trace` and muzzle obstruction probe settings: align close targets and safely resolve a blocked muzzle.
- `Light Object Mass Threshold` and the Light Pull settings: stabilize targets strictly below 5 kg without changing standard cargo behavior.
- `Max Pull Force`, `Pull Strength`, and `Pull Damping`: mass-aware recall feel.
- `Physics Release Distance`: soft-catch radius that keeps recalled objects in front of the player.
- `Release Braking`: removes inward momentum at the soft-catch radius to prevent overshoot behind the player.
- `Return Gravity` and `Return Initial Drop Speed`: control how the free harpoon falls until it reaches a usable floor.
- `Return Ground Drag Speed` and `Return Ground Drag Responsiveness`: tune the floor-scraping recall.
- `Return Ground Clearance`, probe distance, step height, and minimum normal Z: tune floor detection and slope following.
- `Return Ground Lift Distance`: controls where the harpoon leaves the floor and lifts into the muzzle.
- `Return Ground Search Timeout`: guarantees recovery in maps with no floor below the harpoon.
- `Return Gravity Fade Time` and `Return Homing Responsiveness`: tune the final lift from the floor into the muzzle.
- `Use Spline Wire`: keep enabled for stable full-span ground and slope routing; disable only to compare the legacy Cable fallback.
- `Wire Route Settings`: tune collision radius, surface clearance, 25 Hz route updates, contact hysteresis, correction limits, render density, and embedded sag.
- `Cable Num Segments`, solver iterations, and gravity scale: tune only the legacy Cable fallback.
- `Cable Start Jitter Dead Zone`, stabilization speed, and maximum lag: filter first-person camera shimmer without visibly disconnecting the line from the muzzle.
- `Cable Minimum/Maximum Slack`: cap long-range looseness while preserving a small natural sag.
- `Enable Ground Cable Collision` and collision friction: apply only to the legacy Cable fallback; WorldDynamic collision is optional in both renderers.
- `Cable Material` and `Cable Width`: shared visual inputs; `Cable Num Sides` and material tile length apply to the legacy Cable fallback.
- `Player Grapple Camera Clearance` and `Player Grapple Camera Probe Radius`: tune first-person camera clearance near ceilings, walls, and corners.
- `Return Separation Distance`: pulls the spear out of an overlapped hit surface before recall.
- `Heavy Target Timeout`: guarantees recovery from immovable targets.
- `Muzzle Offset` and `Gun Visual Offset`: first-person placement.
- `Draw Debug`: displays aim and impact markers.

## Direct Grabber

`JM Physical Grabber Component` remains available for short-range direct grabbing. Its fixed force budget is not multiplied by mass, so heavy bodies lag or can only be dragged.

The plugin requires the built-in Unreal Cable Component plugin and has no dependency on project content or other JM plugins. AI, inventory, objective, monster, door, and portal integration is intentionally event-driven outside this plugin. The two sample Blueprints are optional project-side overrides; deleting them and selecting the native classes restores the built-in prototype.
