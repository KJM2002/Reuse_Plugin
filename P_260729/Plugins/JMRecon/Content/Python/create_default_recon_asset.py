import os
import unreal

asset_path = "/JMRecon/Data/DA_JMRecon_Default"
asset_file = os.path.join(
    unreal.Paths.convert_relative_path_to_full(unreal.Paths.project_plugins_dir()),
    "JMRecon",
    "Content",
    "Data",
    "DA_JMRecon_Default.uasset",
)
asset = unreal.load_asset(asset_path) if os.path.isfile(asset_file) else None

if asset is None:
    factory = unreal.DataAssetFactory()
    factory.set_editor_property("data_asset_class", unreal.JMReconDefinition)
    asset = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
        "DA_JMRecon_Default",
        "/JMRecon/Data",
        unreal.JMReconDefinition,
        factory,
    )

if asset is None:
    raise RuntimeError("Unable to create DA_JMRecon_Default")

asset.set_editor_property("entering_duration", 0.3)
asset.set_editor_property("exiting_duration", 0.2)
asset.set_editor_property("allow_listen", True)
asset.set_editor_property("allow_peek", True)
asset.set_editor_property("allow_illuminate", True)
asset.set_editor_property("peek_open_fraction", 0.1)
asset.set_editor_property("camera_yaw_limit", 45.0)
asset.set_editor_property("camera_pitch_limit", 30.0)
asset.set_editor_property("peek_blend_time", 0.2)

if not unreal.EditorAssetLibrary.save_loaded_asset(asset, only_if_is_dirty=False):
    raise RuntimeError("Unable to save DA_JMRecon_Default")

unreal.log("JMRecon default preset created: " + asset_path)
