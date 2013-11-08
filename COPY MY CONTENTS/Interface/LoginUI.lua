--\\\\\\\\\\\\\\\\\\\\\\\\\\\\
--|||| Serveralert |||||||

SERVER_ALERT_URL = "http://marforius.99k.org/alert.txt";

--SERVER_ALERT_URL = change if you want (Needs to point to a alert.txt file or directory)
-- PROPER FORMATTING:
-- SERVERALERT: WhatEverYouWantHere
-- Links are clickable

--\\\\\\\\\\\\\\\\\\\\\\\\\\\\
--|||| list of servers |||||||
vx = {
["ServerList"] = {
-- 1 server
{
	["Host"] = "marforius.no-ip.org",   -- required
	["Portal"] = "us",               -- bnet, required?
	["Description"] = "Marforius's server", -- not required
	["AccountList"] = {
	-- 1 server account
	{
		["Login"] = "accountname",
		["Password"] = "password",
		}
		-- end of server accountlist
	},
},
-- 2 server
{
	["Host"] = "localhost",
	["Portal"] = "us",
	["Description"] = "Localhost",
	["AccountList"] = {
	-- 1 server account
	{
		["Login"] = "my_username",
		["Password"] = "my_pass",
	},
	-- 2 server account
	{
		["Login"] = "my_username",
		["Password"] = "my_pass",
	},
	-- end of server accountlist
},
},
-- 3 server
{
	["Host"] = "127.0.0.1",
	["Description"] = "localhost",
},
-- 4 server
{
	["Host"] = "realm.private1.com",
	["Description"] = "private server 1",
	["AccountList"] = {
	-- 1 server account
	{
		["Login"] = "private1_log_1",
		["Password"] = "private1_pass_1",
	},
	-- 2 server account
	{
		["Login"] = "private1_log_2",
		["Password"] = "private1_pass_2",
	},
	-- end of server accountlist
},
},
-- end of serverlist
-- global account list
},
["AccountList"] = {
-- 1 global account
{
	["Login"] = "general_log_1",
	["Password"] = "general_pass_1",
},
-- 2 global account
{
	["Login"] = "general_log_2",
	["Password"] = "general_pass_2",
},
-- end of general accountlist
},
["SceneList"] = {
-- basic scenes. scene is set randomly from this list
"cl", -- classic
"bc", -- burning crusade
"lk", -- lich king
"be", -- blood elf
"dk", -- death knight
"dr", -- draenei
"dg", -- dwarf/gnome
"hm", -- human
"ne", -- night elf
"ot", -- orc/trol
"ud", -- undead
"tr", -- tauren
"cs", -- caracterselect
--"blank", -- black clear screen

-- you can set your own texture (internal or external)
-- it's must be blp, but do not set extension, and use double slashes in path
-- image must be square (default 1024x1024), or you get green screen.
--"Interface\\GLUES\\loading",
--"Interface\\GLUES\\LOADINGSCREENS\\LoadScreenChamberBlack",
--"Interface\\GLUES\\LOADINGSCREENS\\LoadScreenRuinedCity",
--"Interface\\Pictures\\11733_bldbank_256",
--"Interface\\Pictures\\11733_ungoro_256",

-- if you have your own "m2" scene, you can set it here too
-- but ambience anyway will be "GlueScreenIntro". extension requaired.
--"Interface\\Glues\\Models\\UI_MainMenu\\UI_MainMenu.m2",
},
["LoginMusic"] ={
{["Track"] = "cl"}, -- duration for basic tracks is not required
--{["Track"] = "bc"}, -- if you don't want random selection after time of track is finished,
--{["Track"] = "lk"}, -- keep only one string
-- use your own internal or external. you can use more - just add string like below
-- duration required and must be in seconds, path must be with double slashes.
-- like playlist x)
--{["Duration"] = "197", ["Track"] = "Sound\\11-AudioTrack 11.mp3"}, -- i.e. "Sound" folder in wow root folder
--{["Duration"] = "185", ["Track"] = "Sound\\Apocaliptica - Path.mp3"},
}
}

--////////////////////////////

-- Don't increase these without testing or you will cause certain frames to clip on fade, it looks horrible.
VX_FADE_LOAD = 0.25; -- time in seconds
VX_FADE_UNLOAD = 0; -- time in seconds
VX_FADE_REFRESH = 0.25; -- time in seconds

VX_SERVERLIST_SERVER_SELECTION = "Server Selection";
VX_SERVERLIST_SERVER_NAME = "Server Name";
VX_SERVERLIST_SERVER_DESCRIPTION = "Server Description";
VX_FORCE_LOGIN = "Bypass authentication bug";
--VX_AUTOMATIC_LOGIN = "Enable Automatic Login";
VX_ACCOUNT_SEPARATOR = "  "

