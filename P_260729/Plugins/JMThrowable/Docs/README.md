# JMThrowable

Portable UE 5.7 first-person throwable runtime plus an optional InventorySystem bridge.

Install both plugin folders when inventory integration is needed. For a player:

1. Add `JMThrowableInteractorComponent`.
2. Add `JMThrowableGameplayIntegrationComponent`.
3. Create a `JMThrowableDefinition` and select a projectile subclass.
4. On the Inventory Item Definition set `bCanUse=true`, `bConsumeOnUse=false`, and
   add an instanced `JMThrowableInventoryUseEffect` pointing at the throw definition.
5. Play: Use enters Ready, RMB aims, RMB release returns Ready, LMB throws, Q cancels.

While aiming, the thin white trajectory ends at the first blocking hit. A brighter
segment and visible orb travel along it, and a fixed marker shows the first impact.
This preview-only policy does not change the projectile's authored bounce/floor motion.

The integration installs a session-scoped Enhanced Input mapping dynamically, so
RMB/LMB/Q remain untouched while Idle. Call `NotifyInventoryOpening()` before opening
inventory during a session. Override `RequestCancelSprint` in Blueprint when the host
has a sprint API.
