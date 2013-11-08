
function OptionsSelectFrame_Hide()
	PlaySound("gsLoginChangeRealmCancel");
	--OptionsSelectFrame:Hide();
	GlueFrameFadeOut(OptionsSelectFrame, VX_FADE_REFRESH, "HIDE");
end

function OptionsSelectResetSettingsButton_OnClick_Reset(self)
	PlaySound("igMainMenuOptionCheckBoxOn");
	GlueDialog_Show("RESET_SERVER_SETTINGS");
end

function OptionsSelectResetSettingsButton_OnClick_Cancel(self)
	PlaySound("igMainMenuOptionCheckBoxOn");
	GlueDialog_Show("CANCEL_RESET_SETTINGS");
end
