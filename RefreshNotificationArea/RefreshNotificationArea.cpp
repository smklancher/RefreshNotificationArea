// RefreshNotificationArea.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define FW(x,y) FindWindowEx(x, NULL, y, L"")

int _tmain(int argc, _TCHAR* argv[])
{
	HWND hNotificationArea;
    RECT r;

	//WinXP
    GetClientRect(
        hNotificationArea = FindWindowEx(
            FW(FW(FW(NULL, L"Shell_TrayWnd"), L"TrayNotifyWnd"), L"SysPager"),
            NULL,
            L"ToolbarWindow32",
            L"Notification Area"),
        &r);
    
    for (LONG x = 0; x < r.right; x += 5)
        for (LONG y = 0; y < r.bottom; y += 5)
            SendMessage(
                hNotificationArea,
                WM_MOUSEMOVE,
                0,
                (y << 16) + x);
	

	//Visible icons
    GetClientRect(
        hNotificationArea = FindWindowEx(
            FW(FW(FW(NULL, L"Shell_TrayWnd"), L"TrayNotifyWnd"), L"SysPager"),
            NULL,
            L"ToolbarWindow32",
            L"User Promoted Notification Area"),
        &r);
    
    for (LONG x = 0; x < r.right; x += 5)
        for (LONG y = 0; y < r.bottom; y += 5)
            SendMessage(
                hNotificationArea,
                WM_MOUSEMOVE,
                0,
                (y << 16) + x);


	//Hidden icons
	GetClientRect(
        hNotificationArea = FindWindowEx(
            FW(NULL, L"NotifyIconOverflowWindow"),
            NULL,
            L"ToolbarWindow32",
            L"Overflow Notification Area"),
        &r);
    
    for (LONG x = 0; x < r.right; x += 5)
        for (LONG y = 0; y < r.bottom; y += 5)
            SendMessage(
                hNotificationArea,
                WM_MOUSEMOVE,
                0,
                (y << 16) + x);


	return 0;
}



//http://malwareanalysis.com/CommunityServer/blogs/geffner/archive/2008/02/15/985.aspx
//void RefreshTaskbarNotificationArea()
//{
//    HWND hNotificationArea;
//    RECT r;
//
//    GetClientRect(
//        hNotificationArea = FindWindowEx(
//            FW(FW(FW(NULL, L"Shell_TrayWnd"), L"TrayNotifyWnd"), L"SysPager"),
//            NULL,
//            L"ToolbarWindow32",
//            L"Notification Area"),
//        &r);
//    
//    for (LONG x = 0; x < r.right; x += 5)
//        for (LONG y = 0; y < r.bottom; y += 5)
//            SendMessage(
//                hNotificationArea,
//                WM_MOUSEMOVE,
//                0,
//                (y << 16) + x);
//}