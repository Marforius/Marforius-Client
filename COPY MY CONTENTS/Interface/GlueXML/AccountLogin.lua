FADE_IN_TIME = 2;
DEFAULT_TOOLTIP_COLOR = {0.8, 0.8, 0.8, 0.09, 0.09, 0.09};
MAX_PIN_LENGTH = 10;

function AccountLogin_OnLoad(self)

	self:RegisterEvent("SHOW_SERVER_ALERT");

	AccountLoginVersion:SetText(RELEASE_BUILD);

	-- Color edit box backdrops
	local backdropColor = DEFAULT_TOOLTIP_COLOR;
	AccountLoginAccountEdit:SetBackdropBorderColor(backdropColor[1], backdropColor[2], backdropColor[3]);
	AccountLoginAccountEdit:SetBackdropColor(backdropColor[4], backdropColor[5], backdropColor[6]);
	AccountLoginPasswordEdit:SetBackdropBorderColor(backdropColor[1], backdropColor[2], backdropColor[3]);
	AccountLoginPasswordEdit:SetBackdropColor(backdropColor[4], backdropColor[5], backdropColor[6]);

	ShowScene(AccountLogin);
end

function AccountLogin_OnShow(self)

	if VX_SOUNDBG then
		SetCVar("Sound_EnableSoundWhenGameIsInBG", VX_SOUNDBG);
		VX_SOUNDBG = nil;
	end

	self:SetSequence(0);
	
	-- Note to developers:
	-- You can implement a custom scan.dll here, however please note
	-- THIS IS USELESS, THIS IS USELESS, THIS IS USELESS
	-- it detects cheatengine and things that warden should/does detect, including some trojans
	-- It is easily bypassed by making scan.dll read only in the directory, the client will not load or change to the next "scan.dll.new"
	-- it is so easily bypassed you can even take the contents out of scan.dll, and the client will skip running it for that next session
	-- YOU HAVE BEEN WARNED
	-- ALSO if you WANT this useless device added, you will have to readd the code protecting the sequence of logging in to it from standard GlueXML files.
	-- it is only here because this next code block is UNREMOVABLE, as it is programatically required for the login function to WORK.
	
	
		--local dllURL = "SCANDLL_URL_WIN32_SCAN_DLL";
		if ( IsWindowsClient() ) then dllURL = SCANDLL_URL_WIN32_SCAN_DLL; end
		ScanDLLStart(SCANDLL_URL_LAUNCHER_TXT, dllURL);
		AccountLoginUI:Show();
		
		
	
	local serverName = GetServerName();
	if(serverName) then
		AccountLoginRealmName:SetText(serverName);
		AccountServerListButton:SetText(GetCVar("realmlist"));
		AccountServerListButton:SetWidth(AccountServerListButton:GetTextWidth());
	else
		AccountLoginRealmName:Hide()
	end

	local accountName = GetSavedAccountName();
	
	if AccountLoginAccountEdit:GetText() == "" then AccountLoginAccountEdit:SetText(accountName); end

	AccountLogin_SetupAccountListDDL();
	
	if ( accountName == "" ) then
		AccountLogin_FocusAccountName();
	else
		AccountLogin_FocusPassword();
	end
end

function AccountLogin_OnHide(self)
	--Stop the sounds from the login screen (like the dragon roaring etc)
	StopAllSFX( 1.0 );
	if ( not AccountLoginSaveAccountName:GetChecked() ) then
		SetSavedAccountList("");
	end
end

function AccountLogin_FocusPassword()
	AccountLoginPasswordEdit:SetFocus();
end

function AccountLogin_FocusAccountName()
	AccountLoginAccountEdit:SetFocus();
end

function AccountLogin_OnKeyDown(key)
	if ( key == "ESCAPE" ) then
		if ( ConnectionHelpFrame:IsShown() ) then
			ConnectionHelpFrame:Hide();
			AccountLoginUI:Show();
		else
			AccountLogin_Exit();
		end
	elseif ( key == "ENTER" ) then
		AccountLogin_Login();
	elseif ( key == "PRINTSCREEN" ) then
		Screenshot();
	end
end

function AccountLogin_OnEvent(event, arg1, arg2, arg3)
	if ( event == "SHOW_SERVER_ALERT" ) then
		ServerAlertText:SetText(arg1);
		ServerAlertFrame:Show();
	end
AccountLoginUI:Show();
end

function AccountLogin_Login()
	DefaultServerLogin(AccountLoginAccountEdit:GetText(), AccountLoginPasswordEdit:GetText());
	
	if ( AccountLoginSaveAccountName:GetChecked() ) then
		SetSavedAccountName(AccountLoginAccountEdit:GetText());
	else
		SetSavedAccountName("");
	end

	if AccountLoginForceLogin:GetChecked() then
		if not VX_SOUNDBG then
			VX_SOUNDBG = GetCVar("Sound_EnableSoundWhenGameIsInBG");
		end
		SetCVar("Sound_EnableSoundWhenGameIsInBG",0);
	end
end

-- /flex
function TempRealmlistWindowbox()
        TRLWB = CreateFrame("EditBox", nil, UIParent);
        TRLWB:SetWidth(300);
        TRLWB:SetHeight(100);
        TRLWB:SetPoint("CENTER");
        TRLWB:SetNumeric(false);
        TRLWB:SetAutoFocus(true);
        TRLWB:SetFontObject("GlueFontHighlight");
        TRLWB:SetScript("OnEnterPressed", EnterPressedHandler);
        TRLWB:SetScript("OnEscapePressed", EscapePressedHandler);
        TRLWB:SetScript("OnEditFocusLost", EditBox_ClearHighlight);
        TRLWB:SetScript("OnEditFocusGained", EditBox_HighlightText);
        TRLWB:SetJustifyH("CENTER");
        TRLWB:SetJustifyV("CENTER");
        local searchBackdrop  = {
                bgFile = "Interface/Tooltips/UI-Tooltip-Background",
                edgeFile = "Interface/Tooltips/UI-Tooltip-Border",
                tile = true, tileSize = 16, edgeSize = 16,
                insets = { left = 4, right = 4, top = 4, bottom = 4 }
            };
        TRLWB:SetBackdrop(TRLWB, searchBackdrop);
        TRLWB:SetText("Put your new realmlist here, then press enter");
        TRLWB:SetMaxLetters(50);
		AccountLogin:Hide();
		TRLWB:HighlightText();
		TRLWB:Show();
end
		
local function EnterPressedHandler()
		local text = TRLWB:GetText();
		ConsoleExec("realmlist "..text.."");
		AccountLogin:Show();
		TRLWB:Hide();
end

local function EscapePressedHandler()
	AccountLogin:Show();
	TRLWB:Hide();
end

function AccountLogin_Options()
	PlaySound("gsTitleOptions");
end

function AccountLogin_Exit()
--	PlaySound("gsTitleQuit");
	QuitGame();
end

function ChangedOptionsDialog_OnShow(self)
	if ( not ShowChangedOptionWarnings() ) then
		self:Hide();
		return;
	end

	local options = ChangedOptionsDialog_BuildWarningsString(GetChangedOptionWarnings());
	if ( options == "" ) then
		self:Hide();
		return;
	end

	-- set text
	ChangedOptionsDialogText:SetText(options);

	-- resize the background to fit the text
	local textHeight = ChangedOptionsDialogText:GetHeight();
	local titleHeight = ChangedOptionsDialogTitle:GetHeight();
	local buttonHeight = ChangedOptionsDialogOkayButton:GetHeight();
	ChangedOptionsDialogBackground:SetHeight(26 + titleHeight + 16 + textHeight + 8 + buttonHeight + 16);
	self:Raise();
end

function ChangedOptionsDialog_OnKeyDown(self,key)
	if ( key == "PRINTSCREEN" ) then
		Screenshot();
		return;
	end

	if ( key == "ESCAPE" or key == "ENTER" ) then
		ChangedOptionsDialogOkayButton:Click();
	end
end

function ChangedOptionsDialog_BuildWarningsString(...)
	local options = "";
	for i=1, select("#", ...) do
		if ( i == 1 ) then
			options = select(1, ...);
		else
			options = options.."\n\n"..select(i, ...);
		end
	end
	return options;
end

-- WOW Account selection
function WoWAccountSelect_OnLoad(self)
	self:RegisterEvent("GAME_ACCOUNTS_UPDATED");
	self:RegisterEvent("OPEN_STATUS_DIALOG");
	WoWAccountSelectDialogBackgroundContainerScrollFrame.offset = 0
	CURRENT_SELECTED_WOW_ACCOUNT = 1;
end

function WoWAccountSelect_OnShow (self)
	AccountLoginAccountEdit:SetFocus();
	AccountLoginAccountEdit:ClearFocus();
	CURRENT_SELECTED_WOW_ACCOUNT = 1;
	WoWAccountSelect_Update();
end

function WoWAccountSelectButton_OnClick(self)
	CURRENT_SELECTED_WOW_ACCOUNT = self:GetID();
	WoWAccountSelect_Update();
end

function WoWAccountSelectButton_OnDoubleClick(self)
	WoWAccountSelect_SelectAccount(self:GetID());
end

function WoWAccountSelect_OnEvent(self, event)
	if ( event == "GAME_ACCOUNTS_UPDATED" ) then
		local str, selectedIndex, selectedName = ""
		for i = 1, GetNumGameAccounts() do
			local name = GetGameAccountInfo(i);
			if ( name == GlueDropDownMenu_GetText(AccountLoginDropDown) ) then
				selectedName = name;
				selectedIndex = i;
			end
			str = str .. name .. "|";
		end
		
		if ( str == strreplace(GetSavedAccountList(), "!", "") and selectedIndex ) then
			WoWAccountSelect_SelectAccount(selectedIndex);
			return;
		else
			self:Show();
		end
	else
		self:Hide();
	end
end

function WoWAccountSelect_SelectAccount(index)
	if ( AccountLoginSaveAccountName:GetChecked() ) then
		WowAccountSelect_UpdateSavedAccountNames(index);
	else
		SetSavedAccountList("");
	end
	WoWAccountSelectDialog:Hide();
	SetGameAccount(index);
end

function WowAccountSelect_UpdateSavedAccountNames(selectedIndex)
	local count = GetNumGameAccounts();
	
	local str = ""
	for i = 1, count do
		local name = GetGameAccountInfo(i);
		if ( i == selectedIndex ) then
			str = str .. "!" .. name .. "|";
		else
			str = str .. name .. "|";
		end
	end
	SetSavedAccountList(str);
end

ACCOUNTNAME_BUTTON_HEIGHT = 20;

function WoWAccountSelect_OnVerticalScroll (self, offset)
	local scrollbar = _G[self:GetName().."ScrollBar"];
	scrollbar:SetValue(offset);
	WoWAccountSelectDialogBackgroundContainerScrollFrame.offset = floor((offset / ACCOUNTNAME_BUTTON_HEIGHT) + 0.5);
	WoWAccountSelect_Update();
end

MAX_ACCOUNTS_DISPLAYED = 8;
function WoWAccountSelect_Update()
    local count = GetNumGameAccounts();
	
	local offset = WoWAccountSelectDialogBackgroundContainerScrollFrame.offset;
	for index=1, MAX_ACCOUNTS_DISPLAYED do
		local button = _G["WoWAccountSelectDialogBackgroundContainerButton" .. index];
		local name, regionID = GetGameAccountInfo(index + offset);
		button:SetButtonState("NORMAL");
		button.BG_Highlight:Hide();
		if ( name ) then
			button:SetID(index + offset);
			button:SetText(name);
			button.regionID = regionID;
			button:Show();
			if ( index == CURRENT_SELECTED_WOW_ACCOUNT) then
				button.BG_Highlight:Show();
			end
		else
			button:Hide();
		end
	end
	
	GlueScrollFrame_Update(WoWAccountSelectDialogBackgroundContainerScrollFrame, count, MAX_ACCOUNTS_DISPLAYED, ACCOUNTNAME_BUTTON_HEIGHT);
end

function WoWAccountSelect_AccountButton_OnClick(self, button)
	CURRENT_SELECTED_WOW_ACCOUNT = self:GetID();
	WoWAccountSelect_Accept();
end

function WoWAccountSelect_OnKeyDown(self, key)
	if ( key == "ESCAPE" ) then
		WoWAccountSelect_OnCancel(self);
	elseif ( key == "UP" ) then
		CURRENT_SELECTED_WOW_ACCOUNT = max(1, CURRENT_SELECTED_WOW_ACCOUNT - 1);
		WoWAccountSelect_Update()
	elseif ( key == "DOWN" ) then
		CURRENT_SELECTED_WOW_ACCOUNT = min(GetNumGameAccounts(), CURRENT_SELECTED_WOW_ACCOUNT + 1);
		WoWAccountSelect_Update()
	elseif ( key == "ENTER" ) then
		WoWAccountSelect_SelectAccount(CURRENT_SELECTED_WOW_ACCOUNT);
	elseif ( key == "PRINTSCREEN" ) then
		Screenshot();
	end
end

function WoWAccountSelect_OnCancel (self)
	self:Hide();
	GlueDialog:Hide();
	CancelLogin();
end

function WoWAccountSelect_Accept()
	WoWAccountSelect_SelectAccount(CURRENT_SELECTED_WOW_ACCOUNT);
end



function AccountListDropDown_OnClick(self)
	--GlueDropDownMenu_SetSelectedValue(AccountLoginDropDown, self.value);
	if strsub(self.value, 1, 3) == "rlm" then
		for i = 1, #vx.ServerList, 1 do
			if vx.ServerList[i].Host then
				if vx.ServerList[i].Host == GetCVar("realmlist") then
					AccountLoginAccountEdit:SetText(strrev(strsub(vx.ServerList[i].AccountList[tonumber(strsub(self.value, 4))].Login, 16)));
					AccountLoginPasswordEdit:SetText(strrev(strsub(vx.ServerList[i].AccountList[tonumber(strsub(self.value, 4))].Password, 19)));
				end
			end
		end
	elseif strsub(self.value, 1, 3) == "all" then
		AccountLoginAccountEdit:SetText(strrev(strsub(vx.AccountList[tonumber(strsub(self.value, 4))].Login, 16)));
		AccountLoginPasswordEdit:SetText(strrev(strsub(vx.AccountList[tonumber(strsub(self.value, 4))].Password, 19)));
	end
end

function AccountListDropDown_Initialize()
	local info = {};
	local count = 0;

	if vx.ServerList then
		for i = 1, #vx.ServerList, 1 do
			if vx.ServerList[i].Host then
				if vx.ServerList[i].Host == GetCVar("realmlist") then
					if vx.ServerList[i].AccountList then
						for j = 1, #vx.ServerList[i].AccountList, 1 do
							info.text = strrev(strsub(vx.ServerList[i].AccountList[j].Login, 16));
							info.value = "rlm"..j
							info.func = AccountListDropDown_OnClick;
							GlueDropDownMenu_AddButton(info);
							count = count + 1;
						end
					end
				end
			end
		end
	end

	if (vx.AccountList) and (#vx.AccountList>0) then
		if info.text then
			info.text = VX_ACCOUNT_SEPARATOR;
			info.disabled = 1;
			info.func = nil;
			GlueDropDownMenu_AddButton(info);
		end

		info={};

		for i = 1, #vx.AccountList do
			info.text = strrev(strsub(vx.AccountList[i].Login,16))
			info.value = "all"..i
			info.func = AccountListDropDown_OnClick;
			GlueDropDownMenu_AddButton(info);
			count = count + 1;
		end
	end
	if count > 0 then
		AccountListDropDown:Show();
	else
		AccountListDropDown:Hide();
	end
end



function AccountLoginDropDown_OnClick(self)
	GlueDropDownMenu_SetSelectedValue(AccountLoginDropDown, self.value);
end

function AccountLoginDropDown_Initialize()
	local selectedValue = GlueDropDownMenu_GetSelectedValue(AccountLoginDropDown);
	local info;

	for i = 1, #AccountList do
		AccountList[i].checked = (AccountList[i].text == selectedValue);
		GlueDropDownMenu_AddButton(AccountList[i]);
	end
end

AccountList = {};
function AccountLogin_SetupAccountListDDL()
	if ( GetSavedAccountName() ~= "" and GetSavedAccountList() ~= "" ) then
		AccountLoginPasswordEdit:SetPoint("BOTTOM", 0, 255);
		AccountLoginLoginButton:SetPoint("BOTTOM", 0, 150);
		AccountLoginDropDown:Show();
	else
		AccountLoginPasswordEdit:SetPoint("BOTTOM", 0, 275);
		AccountLoginLoginButton:SetPoint("BOTTOM", 0, 170);
		AccountLoginDropDown:Hide();
		return;
	end
	
	AccountList = {};
	local i = 1;
	for str in string.gmatch(GetSavedAccountList(), "([%w!]+)|?") do
		local selected = false;
		if ( strsub(str, 1, 1) == "!" ) then
			selected = true;
			str = strsub(str, 2, #str);
			GlueDropDownMenu_SetSelectedName(AccountLoginDropDown, str);
			GlueDropDownMenu_SetText(str, AccountLoginDropDown);
		end
		AccountList[i] = { ["text"] = str, ["value"] = str, ["selected"] = selected, func = AccountLoginDropDown_OnClick };
		i = i + 1;
	end
end
