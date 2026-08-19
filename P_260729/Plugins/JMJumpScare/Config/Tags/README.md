---
title: "Gameplay Tags"
status: ReviewRequired
authority: Supporting
scope: "Plugin: JMJumpScare"
classified_on: 2026-08-19
owners:
  - "JMJumpScare Maintainers"
review_reason: "공존 위치를 유지했으며 현재 Config 및 런타임 등록 결과와 재검증하지 않음"
---

# Gameplay Tags

JMJumpScare event tags are registered as native tags in `JMJumpScareEventTags.cpp`. Project-specific JumpScare and Trigger IDs should be declared by the consuming project under `JumpScare.*` and `JumpScare.Trigger.*`.
