// WowError.cpp : main project file.

#include "stdafx.h"

using namespace std;

bool main(int argc, char *argv[])
	{

	int i;
	for (i = 0; i < argc; i++)
		{
		printf ("argv[%d] is %s\n", i, argv[i]);
		}

	ofstream myfile;
	myfile.open("Errors\\WowError.exe.log");
		int il;
		for (il = 0; il < argc; il++)
			{
			myfile << ("argv[%d] is %s\n", il, argv[il]);
			}
		myfile.close();

	printf ("\n\n");
	printf ("World of Warcraft has crashed");
	printf ("\n\n");
	printf("A crash report has been saved in \"World of Warcraft\\Errors\"\n\nupload this file to mediafire if you are able to reproduce this bug\nand make a report,\nlinking this crashdump on our Marforius-Client github \"issues\" section.");
	printf ("\n\n");
	printf("This program does nothing but print these lines, as the default\nbugreporter(WowError.exe) carries a risk of reporting private server information to blizzard entertainment.");
	printf ("\n\n");
	system("PAUSE");
	return(0);
	}
