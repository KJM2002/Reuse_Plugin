import unreal


for map_path in (
    "/Game/Prototype/Maps/Level_Prototype",
    "/Game/Level/Level_Mapgenerate",
):
    unreal.EditorLoadingAndSavingUtils.load_map(map_path)
    for actor in unreal.EditorLevelLibrary.get_all_level_actors():
        if "BP_PrototypeLevelPortal" not in actor.get_class().get_name():
            continue
        effect = actor.get_editor_property("portal_effect")
        focus = actor.get_editor_property("transition_focus")
        bounds_origin, bounds_extent, _ = unreal.SystemLibrary.get_component_bounds(effect)
        unreal.log(
            "PORTAL_FOCUS_INSPECT map={} actor={} actor_location={} effect_location={} "
            "effect_bounds_origin={} effect_bounds_extent={} focus_location={}".format(
                map_path,
                actor.get_name(),
                actor.get_actor_location(),
                effect.get_world_location(),
                bounds_origin,
                bounds_extent,
                focus.get_world_location(),
            )
        )
