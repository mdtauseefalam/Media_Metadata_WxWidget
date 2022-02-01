/**********************************************************
File: CApp.h
Description: Starts the Application and create object of
CMainWindow to handle the working of image viewer.
Author: Md Tauseef Alam
**********************************************************/
#pragma once

#ifndef WX_PRECOMP
#define WX_PRECOMP
#include <wx/wx.h>
#include "CMainWindow.h"
#include "vld.h"
#endif

/**********************************************************
CLASS: CApp
DESCRIPTION: Handles the working as an Application by making
object of CMainWindow class and inherits wxApp class.
***********************************************************/
class CApp :public wxApp
{
public:
	virtual bool OnInit();
	~CApp();
};