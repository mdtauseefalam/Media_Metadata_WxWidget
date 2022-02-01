/**********************************************************
File: CApp.cpp
Description: Starts the Application and create object of
CMainWindow to handle the working of image viewer.
Author: Md Tauseef Alam
**********************************************************/

#include "CApp.h"

IMPLEMENT_APP(CApp)

bool CApp::OnInit()
{
	wxInitAllImageHandlers();
	CMainWindow* frame = new CMainWindow(wxT("Media Metadata!!"));
	frame->SetMinSize(wxSize(MWIDTH, MHEIGHT));
	frame->SetMaxSize(wxSize(MWIDTH, MHEIGHT));
	frame->Center();
	frame->Show(true);
	return true;
}
//Destructor of CApp
CApp::~CApp()
{
}
