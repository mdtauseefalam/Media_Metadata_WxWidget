/**********************************************************
File:CMainWindow.cpp
Description:handles GUI and the different panel and media.
Author: Md Tauseef Alam
**********************************************************/
#pragma once
#include "CImageMetadata.h"
#include "CMainWindow.h"
#include "CMediaMetadata.h"
#include "CMediaPreview.h"

//Default Constructor
CMainWindow::CMainWindow(){}

/************************************************************
Overloaded Constructor of CMainWindow
PARAMS:
title
***********************************************************/
CMainWindow::CMainWindow(const wxString& title)
	:wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(MWIDTH, MHEIGHT),
						wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION )
{
	wxPanel *m_panel = new wxPanel(this, wxID_ANY, ZERO_POINT, wxSize(MWIDTH, MHEIGHT), wxRAISED_BORDER);
	m_butPanelup = new wxPanel(m_panel, wxID_ANY, ZERO_POINT, BUT_PAN_SIZE, wxRAISED_BORDER);
	m_lfrot = new wxButton(m_butPanelup, ID_ROTATE_LEFT, wxT("Left Rotate"), ANTICLK_POINT, ANTICLK_SIZE);
	m_rtrot = new wxButton(m_butPanelup, ID_ROTATE_RIGHT, wxT("Right Rotate"), CLK_POINT, CLK_SIZE);

	m_imgPanel = new wxPanel(m_panel, wxID_ANY, IMGPANEL_POINT, IMGPANEL_SIZE, wxRAISED_BORDER);
	m_desPanel = new wxPanel(m_panel, wxID_ANY, DESPANEL_POINT, DESPANEL_SIZE, wxRAISED_BORDER);
	m_butPaneldown = new wxPanel(m_panel, wxID_ANY, BUT_PAN_DPOINT, BUT_PAN_DSIZE, wxRAISED_BORDER);
	m_button = new wxButton(m_butPaneldown, ID_BROWSE, wxT("Browse"), BROWSE_POINT, BROWSE_SIZE);
	m_clear = new wxButton(m_butPaneldown, ID_CLEAR, wxT("Clear"), CLEAR_POINT, CLEAR_SIZE);

	new wxStaticText(m_imgPanel, wxID_ANY, wxT("<<<<<<DRAG AND DROP FILE HERE>>>>>"), wxPoint(150, 200), wxSize(300, 100));
	m_text = new wxStaticText(m_desPanel, wxID_ANY, m_info, TEXT_POINT, TEXT_SIZE);

	m_imgPanel->DragAcceptFiles(true);
	m_imgPanel->Connect(wxEVT_DROP_FILES, wxDropFilesEventHandler(CMainWindow::onDropFiles), NULL, this);
	Connect(ID_BROWSE, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(CMainWindow::onBrowse));
	Connect(ID_ROTATE_LEFT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(CMainWindow::onRotateLeft));
	Connect(ID_ROTATE_RIGHT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(CMainWindow::onRotateRight));
	Connect(ID_CLEAR, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(CMainWindow::onClear));
}

/************************************************************
FUNCTION:onBrowse
DESCRIPTION: For Displaying the picture from system.
PARAMS:
event parameter
RETURN: Nothing
***********************************************************/
void CMainWindow::onBrowse(wxCommandEvent & WXUNUSED(event))
{
	wxFileDialog
		openFile(this, ("Preview Image"), "", "",
		"(jpg) files (*.jpg)|*.jpg|png files(*.png)|*.png|bmp files(*.bmp)|*.bmp|All files|*.*",
		wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFile.ShowModal() == wxID_CANCEL)
		return;
	wxFileInputStream input_stream(openFile.GetPath());
	if (!input_stream.IsOk())
	{
		wxMessageBox("Cannot open file '%s'.", openFile.GetPath());
		return;
	}
	m_path = openFile.GetPath();
	m_mainimage.LoadFile(input_stream, wxBITMAP_TYPE_ANY);
	if (m_mediaPreview != NULL)
	{
		delete m_mediaPreview;
		m_mediaPreview = NULL;
	}
	m_mediaPreview = new CMediaPreview(m_imgPanel, m_mainimage);

	delete m_text;
	m_text = NULL;
	wxString metadata = description();
	m_text = new wxStaticText(m_desPanel, wxID_ANY, metadata, TEXT_POINT, TEXT_SIZE);
}
/************************************************************
FUNCTION:description
DESCRIPTION: Handles the displaying of metadata.
PARAMS:
empty
RETURN: wxString metadata
***********************************************************/
wxString CMainWindow::description()
{
	CImageMetadata *objMetadata = new CImageMetadata(m_path);
	m_info = "IMAGE DETAILS\n";
	m_info += wxString::Format(objMetadata->imageType());
	m_info += wxString::Format("\nImage Width:\t%d pixel", objMetadata->getImageWidth());
	m_info += wxString::Format("\nImage Height:\t%d pixel", objMetadata->getImageHeight());
	m_info += wxString::Format("\nImage Resolution:\t%s ", objMetadata->getResolution());
	m_info += wxString::Format("\nImage Size:\t%d kB", objMetadata->getImageSize());
	m_info += wxString::Format("\nAlpha Chanel:\t%s", objMetadata->getImageAlpha());
	delete objMetadata;
	objMetadata = NULL;
	return m_info;
}

/************************************************************
FUNCTION:onRotateLeft
DESCRIPTION: Handles the rotation of picture anticlockwise 90 degree
PARAMS:
event parameter
RETURN: Nothing
***********************************************************/
void CMainWindow::onRotateLeft(wxCommandEvent& WXUNUSED(event))
{
	if (!m_mainimage.IsOk())
	{
		wxMessageBox("Rotation failed");
		return;
	}
	m_mainimage = m_mainimage.Rotate90(false);
	if (m_mediaPreview != NULL)
	{
		delete m_mediaPreview;
		m_mediaPreview = NULL;
	}
	m_mediaPreview = new CMediaPreview(m_imgPanel, m_mainimage);
}

/************************************************************
FUNCTION:onRotateRight
DESCRIPTION: Handles the rotation of picture clockwise 90 degree
PARAMS:
event parameter
RETURN: Nothing
***********************************************************/
void CMainWindow::onRotateRight(wxCommandEvent& WXUNUSED(event))
{
	if (!m_mainimage.IsOk())
	{
		wxMessageBox("Rotation failed");
		return;
	}
	m_mainimage = m_mainimage.Rotate90();
	if (m_mediaPreview != NULL)
	{
		delete m_mediaPreview;
		m_mediaPreview = NULL;
	}
	m_mediaPreview = new CMediaPreview(m_imgPanel, m_mainimage);
}
/************************************************************
FUNCTION:onClear
DESCRIPTION: For Displaying the picture from system.
PARAMS:
event parameter
RETURN: Nothing
***********************************************************/
void CMainWindow::onClear(wxCommandEvent& event)
{
	delete m_mediaPreview;
	m_mediaPreview = NULL;
	delete m_text;
	m_text = NULL;
	m_mainimage.Destroy();
	m_imgPanel->Refresh();
}
/************************************************************
FUNCTION: onDropFiles
DESCRIPTION: Used for dropping media file
PARAMS:
event : wxDropFilesEvent
RETURN : Nothing
***********************************************************/
void CMainWindow::onDropFiles(wxDropFilesEvent &event)
{
	if (event.GetNumberOfFiles() > 1)
	{
		wxMessageBox("Multiple files have been selected");
		return;
	}
	wxString* dropped = event.GetFiles();
	wxFileInputStream inputstream(dropped[0]);
	if (!inputstream.IsOk())
	{
		wxLogError("can not open file '%s' .", dropped[0]);
		return;
	}
	m_path = dropped[0];
	m_mainimage.LoadFile(inputstream, wxBITMAP_TYPE_ANY);
	if (!m_mainimage.IsOk())
	{
		return;
	}
	if (m_mainimage.GetType() != wxBITMAP_TYPE_BMP
		&& m_mainimage.GetType() != wxBITMAP_TYPE_PNG
		&& m_mainimage.GetType() != wxBITMAP_TYPE_JPEG)
	{
		wxMessageBox("Sorry! The image type is not supported.");
		return;
	}
	if (m_mediaPreview != NULL)
	{
		delete m_mediaPreview;
		m_mediaPreview = NULL;
	}
	m_mediaPreview = new CMediaPreview(m_imgPanel, m_mainimage);

	if (m_text != NULL)
	{
		delete m_text;
		m_text = NULL;
	}
	wxString metadata = description();
	m_text = new wxStaticText(m_desPanel, wxID_ANY, metadata, TEXT_POINT, TEXT_SIZE);
}
//Destructor of Class
CMainWindow::~CMainWindow()
{
	delete m_butPanelup;
	m_butPanelup = NULL;
	delete m_imgPanel;
	m_imgPanel = NULL;
	delete m_desPanel;
	m_desPanel = NULL;
	delete m_butPaneldown;
	m_butPaneldown = NULL;
}

