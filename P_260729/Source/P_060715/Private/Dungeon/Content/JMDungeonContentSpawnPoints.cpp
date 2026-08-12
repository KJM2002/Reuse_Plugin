#include "Dungeon/Content/JMDungeonContentSpawnPoints.h"

#include "AI/Common/JMDungeonMonster.h"
#include "Engine/Texture2D.h"
#include "UObject/ConstructorHelpers.h"

namespace
{
#if WITH_EDITORONLY_DATA
	UTexture2D* LoadEditorSprite(const TCHAR* Path)
	{
		return LoadObject<UTexture2D>(nullptr, Path);
	}

	void ConfigureEditorBillboard(UBillboardComponent& Billboard, UTexture2D* Texture, const FText& DisplayName)
	{
		Billboard.SetSprite(Texture);
		Billboard.SetIsVisualizationComponent(true);
		Billboard.SpriteInfo.Category = TEXT("Dungeon Content");
		Billboard.SpriteInfo.DisplayName = DisplayName;
		Billboard.ScreenSize = 0.0025f;
		Billboard.bIsScreenSizeScaled = true;
	}
#endif
}

UJMDungeonItemSpawnPointComponent::UJMDungeonItemSpawnPointComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetHiddenInGame(true);
#if WITH_EDITORONLY_DATA
	ConfigureEditorBillboard(*this, LoadEditorSprite(TEXT("/Engine/EditorResources/Spawn_Point.Spawn_Point")),
		NSLOCTEXT("JMDungeonContent", "ItemSpawnPoint", "Dungeon Item Spawn Point"));
#endif
}

UJMDungeonAIEntryPointComponent::UJMDungeonAIEntryPointComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetHiddenInGame(true);
#if WITH_EDITORONLY_DATA
	ConfigureEditorBillboard(*this, LoadEditorSprite(TEXT("/Engine/EditorResources/Ai_Spawnpoint.Ai_Spawnpoint")),
		NSLOCTEXT("JMDungeonContent", "AIEntryPoint", "Dungeon AI Entry Point"));
#endif
}

bool UJMDungeonAIEntryPointComponent::AllowsMonsterClass(TSubclassOf<AJMDungeonMonster> MonsterClass) const
{
	if (!MonsterClass)
	{
		return false;
	}
	if (AllowedMonsterClasses.IsEmpty())
	{
		return true;
	}
	for (const TSubclassOf<AJMDungeonMonster> AllowedClass : AllowedMonsterClasses)
	{
		if (AllowedClass && MonsterClass->IsChildOf(AllowedClass))
		{
			return true;
		}
	}
	return false;
}

UJMDungeonAIRoutePointComponent::UJMDungeonAIRoutePointComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetHiddenInGame(true);
#if WITH_EDITORONLY_DATA
	ConfigureEditorBillboard(*this, LoadEditorSprite(TEXT("/Engine/EditorResources/S_TargetPoint.S_TargetPoint")),
		NSLOCTEXT("JMDungeonContent", "AIRoutePoint", "Dungeon AI Route Point"));
#endif
}
