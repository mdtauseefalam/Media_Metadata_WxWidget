/**********************************************************
File:CMainWindow.h
Description:handles GUI and the different panel and media.
Author: Md Tauseef Alam
**********************************************************/
#pragma once
#include <wx/wx.h>
#include "CApp.h"
#include "CMediaPreview.h"
#include "vld.h"

const int MWIDTH = 800;
const int MHEIGHT = 600;

#define ANTICLK_POINT  wxPoint(250, 10)
#define CLK_POINT wxPoint(350, 10)
#define IMGPANEL_POINT wxPoint(0,51)
#define DESPANEL_POINT wxPoint(601, 51)
#define BROWSE_POINT  wxPoint(250, 7)
#define CLEAR_POINT wxPoint(350, 7)
#define ZERO_POINT wxPoint(0,0)
#define TEXT_POINT wxPoint(10, 10)
#define BUT_PAN_DPOINT wxPoint(0, 501)

#define BUT_PAN_SIZE wxSize(600,50)
#define ANTICLK_SIZE wxSize(80, 20)
#define CLK_SIZE wxSize(80, 20)
#define IMGPANEL_SIZE wxSize(600, 450)
#define DESPANEL_SIZE wxSize(200, 450)
#define BROWSE_SIZE wxSize(80, 20)
#define CLEAR_SIZE wxSize(80, 20)
#define IMG_SIZE wxSize(590,440)
#define TEXT_SIZE wxSize(200,450)
#define BUT_PAN_DSIZE wxSize(MWIDTH, 75)

enum enMyEnum
{
	ID_ROTATE_LEFT = wxID_HIGHEST + 1,
	ID_ROTATE_RIGHT,
	ID_BROWSE,
	ID_CLEAR,
};
/*************************************************************
class : CMainWindow
Description: Creates a frame inside which a main panel is
created and it is divided into 3 sub panels and buttons are also
there to handle different function.
***************************************************************/
class CMainWindow :public wxFrame
{
	wxString m_info = "\nDESCRIPTION\n";
	wxString m_path;
	wxStaticText* imgtext;
	wxStaticText* m_text;
	wxButton* m_button;
	wxButton* m_clear;
	wxButton* m_lfrot;
	wxButton* m_rtrot;
	wxPanel* m_butPanelup;
	wxPanel* m_butPaneldown;
	wxPanel* m_imgPanel;
	wxPanel* m_desPanel;
	CMediaPreview* m_mediaPreview = NULL;
	wxImage m_mainimage;

public:
	CMainWindow(const wxString &title);
	CMainWindow();
	~CMainWindow();
	void onBrowse(wxCommandEvent &WXUNUSED(event));
	void onClear(wxCommandEvent& event);
	void onRotateLeft(wxCommandEvent &WXUNUSED(event));
	void onRotateRight(wxCommandEvent &WXUNUSED(event));
	void onDropFiles(wxDropFilesEvent &event);
	wxString description();
};