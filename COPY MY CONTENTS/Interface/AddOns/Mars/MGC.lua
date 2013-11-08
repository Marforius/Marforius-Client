--[[
ArcAddons
Copyright (C) 2012 Marforius

This file is part of ArcAddons.

ArcAddons is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, version 3.

ArcAddons is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with ArcAddons. If not, see <http://www.gnu.org/licenses/>.

This code is also released under the Attribution-Noncommercial-Share Alike 3.0 United States License its terms overwrite the GNU licence where applicable.
http://creativecommons.org/licenses/by-nc-sa/3.0/us/
]]

local pairs, wipe, select, pcall = pairs, wipe, select, pcall
local GetFramesRegisteredForEvent = GetFramesRegisteredForEvent
local enteredOnce, listenForUnreg

local occured = {}
local events = {
	SPELLS_CHANGED = {},
	USE_GLYPH = {},
	PET_TALENT_UPDATE = {},
	WORLD_MAP_UPDATE = {},
	UPDATE_WORLD_STATES = {},
	CRITERIA_UPDATE = {},
	RECEIVED_ACHIEVEMENT_LIST = {},
	ACTIONBAR_SLOT_CHANGED = {},
}

local t = {GetFramesRegisteredForEvent("PLAYER_ENTERING_WORLD")}
for i, frame in ipairs(t) do
    frame:UnregisterEvent("PLAYER_ENTERING_WORLD")
end

local f = CreateFrame("Frame")
f:RegisterEvent("PLAYER_ENTERING_WORLD")

for i, frame in ipairs(t) do
    frame:RegisterEvent("PLAYER_ENTERING_WORLD")
end
wipe(t)
t = nil

local function unregister(event, ...)
	for i = 1, select("#", ...) do
		local frame = select(i, ...)
		frame:UnregisterEvent(event)
		events[event][frame] = 1
	end
end

if PetStableFrame then
	PetStableFrame:UnregisterEvent("SPELLS_CHANGED")
end

f:SetScript("OnEvent", function(self, event)
		if event == "PLAYER_ENTERING_WORLD" then
		collectgarbage("restart")
			if not enteredOnce then
				f:RegisterEvent("PLAYER_LEAVING_WORLD")

				hooksecurefunc(getmetatable(f).__index, "UnregisterEvent", function(frame, event)
						if listenForUnreg then
							local frames = events[event]
							if frames then
								frames[frame] = nil
							end
						end
				end)
				enteredOnce = 1
			else
				listenForUnreg = nil
				for event, frames in pairs(events) do
					for frame in pairs(frames) do
						frame:RegisterEvent(event)
						local OnEvent = occured[event] and frame:GetScript("OnEvent")
						if OnEvent then
							local arg1
							if event == "ACTIONBAR_SLOT_CHANGED" then
								arg1 = 0
							end
							local success, err = pcall(OnEvent, frame, event, arg1)
							if not success then
								geterrorhandler()(err, 1)
							end
						end
						frames[frame] = nil
					end
				end
				wipe(occured)
			end
		elseif event == "PLAYER_LEAVING_WORLD" then
			wipe(occured)
			for event in pairs(events) do
				unregister(event, GetFramesRegisteredForEvent(event))
				f:RegisterEvent(event)
			end
			listenForUnreg = 1
			collectgarbage("stop")
		else
			occured[event] = 1
			f:UnregisterEvent(event)
		end
end)

-- Improves loading time by 40-70%
-- stops garbage collection during loading screens & tweaks events
