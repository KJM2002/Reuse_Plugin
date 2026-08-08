#pragma once

#include "IDetailCustomization.h"
#include "Styling/SlateColor.h"
#include "Types/JMRoomGridTypes.h"

class AJMCustomGridMapGenerator;
class IDetailLayoutBuilder;
struct FAssetData;
struct FJMCustomGridCell;

class FJMCustomGridMapGeneratorDetails final : public IDetailCustomization
{
public:
    static TSharedRef<IDetailCustomization> MakeInstance();
    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
    enum class EDesignerMode : uint8
    {
        Shape,
        Connections
    };

    TWeakObjectPtr<AJMCustomGridMapGenerator> Generator;
    FJMGridCoordinate SelectedCoordinate = FJMGridCoordinate(0, 0);
    EDesignerMode Mode = EDesignerMode::Shape;

    FReply HandleCellClicked(int32 X, int32 Y);
    FReply HandleModeClicked(EDesignerMode NewMode);
    FReply HandleWayPresetClicked(int32 WayCount);
    FReply HandleAutoConnectClicked();
    FReply HandleClearShapeClicked();
    FReply HandleSetRoleClicked(bool bEntrance, bool bExit);
    FReply HandleValidateClicked();
    FReply HandleDrawClicked();
    FReply HandleGenerateClicked();
    void HandleDirectionChanged(ECheckBoxState NewState, EJMRoomDirection Direction);
    void HandleSpecialRoomChanged(const FAssetData& AssetData);

    FJMCustomGridCell* FindSelectedCell() const;
    void SetDirectionMirrored(EJMRoomDirection Direction, bool bOpen);
    void SetSelectedMask(int32 NewMask);
    FText GetCellLabel(int32 X, int32 Y) const;
    FSlateColor GetCellColor(int32 X, int32 Y) const;
    FText GetSelectedSummary() const;
    FString GetSpecialRoomObjectPath() const;
};
