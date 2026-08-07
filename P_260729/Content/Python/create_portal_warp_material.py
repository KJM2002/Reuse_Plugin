import unreal


ASSET_PATH = "/Game/Prototype/Materials/M_PP_PortalWarp"
PORTAL_BP_PATH = "/Game/Prototype/Blueprints/BP_PrototypeLevelPortal"


def expression(material, expression_class, x, y):
    return unreal.MaterialEditingLibrary.create_material_expression(material, expression_class, x, y)


def connect(source, output_name, target, input_name):
    if not unreal.MaterialEditingLibrary.connect_material_expressions(source, output_name, target, input_name):
        raise RuntimeError(f"Could not connect {source.get_name()}:{output_name} to {target.get_name()}:{input_name}")


def create_material():
    material = unreal.EditorAssetLibrary.load_asset(ASSET_PATH)
    if material:
        unreal.EditorAssetLibrary.delete_asset(ASSET_PATH)

    tools = unreal.AssetToolsHelpers.get_asset_tools()
    material = tools.create_asset(
        "M_PP_PortalWarp",
        "/Game/Prototype/Materials",
        unreal.Material,
        unreal.MaterialFactoryNew(),
    )
    if not material:
        raise RuntimeError("Failed to create portal warp material")

    material.set_editor_property("material_domain", unreal.MaterialDomain.MD_POST_PROCESS)

    uv = expression(material, unreal.MaterialExpressionScreenPosition, -1500, -50)
    center = expression(material, unreal.MaterialExpressionConstant2Vector, -1500, 180)
    center.set_editor_property("r", 0.5)
    center.set_editor_property("g", 0.5)

    direction = expression(material, unreal.MaterialExpressionSubtract, -1260, 100)
    connect(center, "", direction, "A")
    connect(uv, "ViewportUV", direction, "B")

    strength = expression(material, unreal.MaterialExpressionScalarParameter, -1260, 300)
    strength.set_editor_property("parameter_name", "WarpStrength")
    strength.set_editor_property("default_value", 0.0)

    direction_strength = expression(material, unreal.MaterialExpressionMultiply, -1030, 100)
    connect(direction, "", direction_strength, "A")
    connect(strength, "", direction_strength, "B")

    samples = []
    for index, factor_value in enumerate((0.0, 0.25, 0.5, 0.75, 1.0)):
        sample_y = -450 + index * 190
        coords = uv
        if factor_value > 0.0:
            factor = expression(material, unreal.MaterialExpressionConstant, -820, sample_y + 65)
            factor.set_editor_property("r", factor_value)
            scaled = expression(material, unreal.MaterialExpressionMultiply, -620, sample_y + 65)
            connect(direction_strength, "", scaled, "A")
            connect(factor, "", scaled, "B")
            warped_uv = expression(material, unreal.MaterialExpressionAdd, -410, sample_y)
            connect(uv, "ViewportUV", warped_uv, "A")
            connect(scaled, "", warped_uv, "B")
            coords = warped_uv

        scene = expression(material, unreal.MaterialExpressionSceneTexture, -150, sample_y)
        scene.set_editor_property("scene_texture_id", unreal.SceneTextureId.PPI_POST_PROCESS_INPUT0)
        scene.set_editor_property("filtered", True)
        connect(coords, "" if factor_value > 0.0 else "ViewportUV", scene, "UVs")
        samples.append(scene)

    summed = samples[0]
    summed_output = "Color"
    for index, scene in enumerate(samples[1:]):
        add = expression(material, unreal.MaterialExpressionAdd, 100 + index * 180, -40)
        connect(summed, summed_output, add, "A")
        connect(scene, "Color", add, "B")
        summed = add
        summed_output = ""

    average = expression(material, unreal.MaterialExpressionMultiply, 860, -40)
    one_fifth = expression(material, unreal.MaterialExpressionConstant, 650, 160)
    one_fifth.set_editor_property("r", 0.2)
    connect(summed, summed_output, average, "A")
    connect(one_fifth, "", average, "B")
    if not unreal.MaterialEditingLibrary.connect_material_property(
        average, "", unreal.MaterialProperty.MP_EMISSIVE_COLOR
    ):
        raise RuntimeError("Failed to connect final portal color")

    unreal.MaterialEditingLibrary.layout_material_expressions(material)
    unreal.MaterialEditingLibrary.recompile_material(material)
    unreal.EditorAssetLibrary.save_loaded_asset(material, False)
    return material


def assign_to_portal(material):
    blueprint = unreal.EditorAssetLibrary.load_asset(PORTAL_BP_PATH)
    if not blueprint:
        raise RuntimeError(f"Portal Blueprint not found: {PORTAL_BP_PATH}")
    generated_class = blueprint.generated_class()
    default_object = unreal.get_default_object(generated_class)
    default_object.set_editor_property("warp_material", material)
    unreal.BlueprintEditorLibrary.compile_blueprint(blueprint)
    unreal.EditorAssetLibrary.save_loaded_asset(blueprint, False)


portal_material = create_material()
assign_to_portal(portal_material)
unreal.log("Created and assigned M_PP_PortalWarp to BP_PrototypeLevelPortal")
