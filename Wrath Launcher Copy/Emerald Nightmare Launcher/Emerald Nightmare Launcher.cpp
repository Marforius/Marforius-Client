// Emerald Nightmare Launcher.cpp : main project file.

#include "stdafx.h"
#include "Main_Window.h"

using namespace EmeraldNightmareLauncher;

[STAThreadAttribute]

int main()
	{

#if !(_DEBUG)
	// these may seem redundant but these are here to force different methods of editing just to look at what happens in the code
	while( IsDebuggerPresent() == TRUE )
		{
		FatalExit(8256);
		}
#endif

	// For people that are going to use this with private code in it.
	// I am not going to sponsor your usage and will remove your legally licensed rights to my code
	// as well as warn the general public if you attempt to add ANY malicious code to the generic launcher
	// 
	// For those that can't read this
	// If debug build is selected then skip all security checks
	// If release build is selected then add wow.exe existence check and check if a debugger is present
	// I won't give away the other checks
	//
	// This won't give you much security but combined with an obfuscater and packer (UPX + UPX Scrambler)
	// you will be a little more secure then just releasing this with a simple reloc

	bool Is_Debug;

#if (_DEBUG)
	Is_Debug = TRUE;
#endif

#if !(_DEBUG)
	Is_Debug = FALSE;
#endif


#if (!_DEBUG)
	if (IsDebuggerPresent())
		{
		MessageBoxEx( NULL, TEXT("This program will not run under a debugger"), TEXT("ERROR"), MB_OK, MB_ICONERROR );
		FatalExit(8256);
		}

	ifstream my_file("wow.exe");

	if( my_file.bad())
		{
		MessageBoxEx( NULL, TEXT("This program MUST be in your World of Warcraft directory"), TEXT("ERROR"), MB_OK, MB_ICONERROR );
		exit(0);
		}

	if (my_file.good() && !IsDebuggerPresent() && !Is_Debug)
		{

#endif

		// Enabling Windows XP visual effects before any controls are created
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false); 

		// Create the main window and run it
		Application::Run(gcnew Main_Window());
		return 0;

#if (!_DEBUG && !Is_Debug)
		}

	if(!IsDebuggerPresent())
		{
		FatalExit(8256);
		}	
	FatalExit(1);
#endif

#if (!_DEBUG)
	return 0;
#endif

	}
