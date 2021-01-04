#pragma once

#include "HEMAX_ParameterWidget.h"

class HEMAX_3dsmaxHda;
class HEMAX_Plugin;

class HEMAX_MaxHoudiniAssetWidget : public HEMAX_ParameterWidget
{
    Q_OBJECT

    public:

	HEMAX_MaxHoudiniAssetWidget(HEMAX_Plugin* ActivePlugin);
	~HEMAX_MaxHoudiniAssetWidget();

	void SetSelection(HEMAX_3dsmaxHda* Hda, bool ForceUnlock);

	void RefreshParameterUI(bool DeleteLater = true);
	HEMAX_3dsmaxHda* GetCurrentHdaSelection();

	bool IsSelectionLocked();
	void HandleLockSelectionButtonChanged(int Locked);

    private:
        
        HEMAX_Plugin* Plugin;
	HEMAX_3dsmaxHda* Selection;
	void UpdateWidget();
	void PushSubnetworkInputNames();
	void PushParameterInputNames();

    private:

	QWidget* HdaActionButtons;
	QGridLayout* HdaActionButtonsLayout;

	QPushButton* RecookHdaButton;
	QPushButton* ReloadHdaButton;

	QPushButton* BakeHdaButton;
	QPushButton* CloneHdaButton;
	QPushButton* CopyToNodeButton;

	QGroupBox* MHAOptionsBox;
	QGridLayout* MHAOptionsBoxLayout;
	QCheckBox* MHAOptions_PushTransformToHAPI;
	QCheckBox* MHAOptions_ApplyHAPITransformToNode;

	// Advanced Options Box //

	QGroupBox* AdvancedOptionsBox;
	QGridLayout* AdvancedOptionsLayout;
	QCheckBox* AdvancedOptionsEnabledCheckbox;

	QWidget* AdvancedOptions_Widget;
	QGridLayout* AdvancedOptions_WidgetLayout;
	QLabel* AdvancedOptions_HDAPathLabel;
	QLineEdit* AdvancedOptions_HDAPath;
	QPushButton* AdvancedOptions_HDAPathSave;

	//////////////////////////

	void CreateMHAOptionsUI();
	void CreateAdvancedOptionsUI();

	void UpdateAdvancedOptionsUI();
	void HideHdaActionButtonsUI();
	void UpdateHdaActionButtonsUI(HEMAX_HdaType HdaType);

    private slots:

	void Slot_LockSelectionButton_Clicked() override;

	void Slot_RecookHdaButton();
	void Slot_ReloadHdaButton();
	void Slot_BakeHdaButton();
	void Slot_CloneHdaButton();
	void Slot_CopyToNodeButton();

	void Slot_MHAOptions_PushTransformToHAPI(int State);
	void Slot_MHAOptions_ApplyHAPITransformToNode(int State);

	void Slot_AdvancedOptionsCheckbox(int State);
	void Slot_AdvancedOptionsHdaPathSave();
};
