﻿// WindowsProject1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WindowsProject1.h"

using namespace std;

#define MAX_LOADSTRING 100

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	const string X_SERVER_EXECUTABLE = "x410.exe /desktop";
	const string WSL_EXECUTABLE = "ubuntu.exe";

	system(("start /B "+ X_SERVER_EXECUTABLE).c_str());
	// start "x410.exe" or other X server, including "X410", "Xming", etc.
	system((WSL_EXECUTABLE + R"+*( run "if [ -z \"$(pidof xfce4-session)\" ]; then export DISPLAY=127.0.0.1:0.0; xfwm4& xfce4-session; pkill '(gpg|ssh)-agent'; taskkill.exe /IM )+*" + X_SERVER_EXECUTABLE + R"+*(; fi;")+*").c_str());
	// call WSL executable and run a simple bash script.  if xfce4 is not running, then export where is the display, start "xfwm4" as window manager and the actual "xfce4-session".
	// once logout, kill the gpg and ssh agent, then kill X server
}
