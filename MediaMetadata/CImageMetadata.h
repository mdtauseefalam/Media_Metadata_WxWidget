/**********************************************************
File:CImageMetadata.h
Description:handles image metadata
Author: Md Tauseef Alam
**********************************************************/
#pragma once
#include <wx/wx.h>
#include "wx/wfstream.h"
#include "vld.h"
/**********************************************************
CLASS: CImageMetadata
DESCRIPTION: Handles the metadata information of an image.
***********************************************************/
class CImageMetadata:public wxPanel
{
	wxImage img;
	wxString path;
public:
	CImageMetadata(wxString f);
	~CImageMetadata();
	void setImage(wxImage img);
	wxImage getImage();
	void setPath(wxString str);
	wxString getPath();

	wxString imageType();
	int getImageWidth();
	wxString getResolution();
	int getImageHeight();
	int getImageSize();
	wxString getImageAlpha();
};