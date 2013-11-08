--SERVER_BUTTON_HEIGHT = 16;
--MAX_SERVERS_DISPLAYED = 10;

function ServerList_OnShow()
	AccountLoginUI:Hide();
	local numServers = #vx.ServerList;
	local name, onhighlit, Description, ServerTooltip, ServerIndex;

	ServerListOkButton:Disable();
	ServerListHighlight:Hide();
	for i=1, 10, 1 do
		ServerIndex = ServerList.offset + i;
		local button = _G["ServerListServerButton"..i];
		if ( ServerIndex > numServers ) then
			button:Hide();
		else
			name = vx.ServerList[ServerIndex].Host;
			Description = vx.ServerList[ServerIndex].Description;
			ServerTooltip = nil;

			if ( not name ) then
				button:Hide();
			else
				DescriptionText = _G["ServerListServerButton"..i.."Description"];
				if ( Description ) then
					DescriptionText:SetText(Description);
				else
					DescriptionText:SetText("");
				end

				if (vx.ServerList[ServerIndex].Portal) then
					ServerTooltip = "Portal:''"..vx.ServerList[ServerIndex].Portal.."''";
				end
				-- TODO
				--if ServerTooltip then
				--	ServerTooltip = ServerTooltip.."  ";
				--else
				--	ServerTooltip = "";
				--end
				--if (vx.ServerList[ServerIndex].Patchlist) then
				--	ServerTooltip = ServerTooltip.."Patchlist:''"..vx.ServerList[ServerIndex].Patchlist.."''";
				--else
				--	ServerTooltip = ServerTooltip.."Patchlist:"..VX_EMPTY_PATCHLIST;
				--end
				if ServerTooltip then
					button.tooltip = ServerTooltip;
				end

				button:SetText(name);
				button:Show();
				button:SetID(ServerIndex);
				button.name = name;

				onhighlight = nil;
				if ( ServerList.selectedName ) then
					if ( name == ServerList.selectedName ) then
						onhighlight = 1;
					end
				elseif ( name == GetCVar("realmlist") ) then
					onhighlight = 1;
				else
					if ( numServers == 1 ) then
						onhighlight = 1;
					end
				end

				if onhighlight then
					ServerList.selectedServer = ServerIndex;
					button:LockHighlight();
					ServerListHighlight:Show();
					ServerListOkButton:Enable();
					ServerListHighlight:SetPoint("TOPLEFT", button, "TOPLEFT", 0, 0);
				else
					button:UnlockHighlight();
				end
			end
		end
	end
	GlueScrollFrame_Update(ServerListScrollFrame, numServers, 10, 16, ServerListHighlight, 557,  587);
end

function ServerListScrollFrame_OnVerticalScroll(self, offset)
	local scrollbar = _G[self:GetName().."ScrollBar"];
	scrollbar:SetValue(offset);
	ServerList.offset = floor((offset / 16) + 0.5);
end

function ServerSelectButton_OnClick(self, id)
	ServerList.selectedServer = id;
	ServerList.selectedName = self.name;
	ServerList_OnShow();
end

function ServerList_OnOk()
	if vx.ServerList[ServerList.selectedServer].Host ~= nil then
	SetCVar("realmlist", vx.ServerList[ServerList.selectedServer].Host);
    end

	AccountLoginRealmName:SetText("");
	SetCVar("realmName", "");
	AccountServerListButton:SetText(GetCVar("realmlist"));
	AccountServerListButton:SetWidth(AccountServerListButton:GetTextWidth());
	GlueFrameFadeOut(ServerList, VX_FADE_REFRESH, "HIDE");

	AccountListDropDown_Initialize();
	AccountLoginUI:Show();
end

function ServerList_OnHide()
	GlueFrameFadeOut(ServerList, VX_FADE_REFRESH, "HIDE");
end

function ServerSelectButton_OnDoubleClick(self, id)
	ServerList.selectedServer = id;
	ServerList.selectedName = self.name;
	ServerList_OnOk();
end

function ServerList_OnCancel()
	ServerList:Hide();
	AccountLoginUI:Show();
end

function ServerList_OnKeyDown(key)
	if ( key == "ESCAPE" ) then
		ServerList_OnCancel();
	elseif ( key == "ENTER" ) then
		ServerList_OnOk();
	elseif ( key == "PRINTSCREEN" ) then
		Screenshot();
	end
end
