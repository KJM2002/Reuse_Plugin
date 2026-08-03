# JMThrowableGameplayIntegration

Bridge from InventorySystem Use Effects to JMThrowable. It tracks the stable inventory
slot `InstanceId`, installs session-only Enhanced Input, validates commit, consumes
exactly one on success, and restores input/movement on every exit path.
