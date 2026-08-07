import unreal


MAP_PATH = "/Game/Level/Level_Mapgenerate"
unreal.EditorLoadingAndSavingUtils.load_map(MAP_PATH)

updated = False
for actor in unreal.EditorLevelLibrary.get_all_level_actors():
    if "BP_PrototypeLevelPortal" not in actor.get_class().get_name():
        continue
    focus = actor.get_editor_property("transition_focus")
    actor.modify()
    focus.modify()
    actor_location = actor.get_actor_location()
    focus.set_world_location(
        unreal.Vector(actor_location.x, actor_location.y, actor_location.z + 40.0),
        False,
        False,
    )
    updated = True
    unreal.log(
        "PORTAL_FOCUS_CONFIGURED actor={} world_z={}".format(
            actor.get_name(), actor_location.z + 40.0
        )
    )

if not updated:
    raise RuntimeError("BP_PrototypeLevelPortal was not found in Level_Mapgenerate")

unreal.EditorLoadingAndSavingUtils.save_current_level()
