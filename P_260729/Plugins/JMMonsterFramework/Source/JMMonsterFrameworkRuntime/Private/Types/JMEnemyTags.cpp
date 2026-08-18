#include "Types/JMEnemyTags.h"

namespace JMEnemyTags
{
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State, "JM.Enemy.State", "Root tag for mutually exclusive enemy states.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Idle, "JM.Enemy.State.Idle", "Enemy is idle.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Patrol, "JM.Enemy.State.Patrol", "Enemy is patrolling.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Investigate, "JM.Enemy.State.Investigate", "Enemy is investigating evidence.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Chase, "JM.Enemy.State.Chase", "Enemy is chasing a target.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Search, "JM.Enemy.State.Search", "Enemy is searching for a lost target.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Attack, "JM.Enemy.State.Attack", "Enemy is attacking.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Flee, "JM.Enemy.State.Flee", "Enemy is fleeing.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Hide, "JM.Enemy.State.Hide", "Enemy is hiding.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Enraged, "JM.Enemy.State.Enraged", "Enemy is enraged.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Stunned, "JM.Enemy.State.Stunned", "Enemy is stunned.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Dead, "JM.Enemy.State.Dead", "Enemy is dead.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Watcher_Frozen, "JM.Enemy.State.Watcher.Frozen", "Watcher is frozen while observed.");

    UE_DEFINE_GAMEPLAY_TAG_COMMENT(Action, "JM.Enemy.Action", "Root tag for reusable enemy actions.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(Action_Melee, "JM.Enemy.Action.Melee", "Standard melee action.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(Action_Scream, "JM.Enemy.Action.Scream", "Standard scream action.");

    UE_DEFINE_GAMEPLAY_TAG_COMMENT(Event, "JM.Enemy.Event", "Root tag for reusable enemy StateTree events.");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(Event_Stimulus, "JM.Enemy.Event.Stimulus", "A normalized perception stimulus changed enemy memory.");

    bool IsConcreteState(const FGameplayTag& Tag)
    {
        return Tag.IsValid() && Tag != State && Tag.MatchesTag(State);
    }

    bool IsConcreteAction(const FGameplayTag& Tag)
    {
        return Tag.IsValid() && Tag != Action && Tag.MatchesTag(Action);
    }
}
