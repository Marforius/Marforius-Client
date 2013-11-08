-- These would be the same as specifying a RunOnce.WTF, except these are applied every time the client starts.
-- This would not be a good place to put a setting that the user MIGHT WANT TO change.

 -- supposed bugfix for multiple processor machines
 ConsoleExec("set processAffinityMask 21845");

 -- Alternative timing code
 ConsoleExec("set timingmethod 0");
 
 ConsoleExec("set cameraDistanceMax 50");
 
 -- Bugfix (confirmed) CharacterAmbient not turning on by default
 ConsoleExec("characterambient")
 
 -- Sets camera to the old traditional movement (only adjust when moving, only horizontal)
 ConsoleExec("set cameraSmoothStyle 1");
 
 -- Bugfixes for things that cant be changed in Lua
 ConsoleExec("set readTOS 1");
 ConsoleExec("set readEULA 1");
 ConsoleExec("set movie 0");
 ConsoleExec("set showToolsUI 0");
 
 
 -- Preformance fix
SetCVar( "gxFixLag", 0)
 
 -- d3d9ex has better preformance in general over default d3d, cache tweaks are just that
 -- on 64 bit machines, assuming it would take advantage of more memory
if ( IsWindowsClient() ) then
	ConsoleExec("gxapi d3d9ex");
	ConsoleExec("gxtexturecachesize 0"); -- Put this here to let the client dynamically decide whats going on with caching
	ConsoleExec("texturecachesize 64"); -- This will revert to 32 on 32 bit systems, obvious
end
