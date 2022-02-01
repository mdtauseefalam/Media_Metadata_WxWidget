/**********************************************************
File:CMediaPreview.h
Description:handles image display
Author: Md Tauseef Alam
**********************************************************/
#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include "wx/wfstream.h"
#include "vld.h"

/**********************************************************
CLASS: CMediaPreview
DESCRIPTION: Handles the preview of an image.
***********************************************************/
class CMediaPreview :public wxPanel
{
	wxImage m_img;
	wxBitmap bitmap;
public:
	CMediaPreview(wxPanel* p, wxImage im);
	~CMediaPreview();
	void display();
};