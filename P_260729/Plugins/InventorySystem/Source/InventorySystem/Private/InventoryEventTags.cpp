#include "InventoryEventTags.h"

namespace JMInventoryEventTags
{
    UE_DEFINE_GAMEPLAY_TAG(Item, "Event.Item");
    UE_DEFINE_GAMEPLAY_TAG(Acquired, "Event.Item.Acquired");
    UE_DEFINE_GAMEPLAY_TAG(Used, "Event.Item.Used");
    UE_DEFINE_GAMEPLAY_TAG(Dropped, "Event.Item.Dropped");
    UE_DEFINE_GAMEPLAY_TAG(Removed, "Event.Item.Removed");
    UE_DEFINE_GAMEPLAY_TAG(UIOpened, "Event.UI.Inventory.Opened");
    UE_DEFINE_GAMEPLAY_TAG(UIClosed, "Event.UI.Inventory.Closed");
}
