/**********************************************************
File:CMediaMetadata.h
Description:handles media metadata
Author: Md Tauseef Alam
**********************************************************/
#pragma once
#include <wx/wx.h>
#include "vld.h"

/**********************************************************
CLASS: CMediaMetadata
DESCRIPTION: Handles the metadata information of a media.
***********************************************************/

class CMediaMetadata:public wxPanel
{
	wxString filepath;
	wxString info;
public:
	void setFilepath(wxString str);
	void setInfo(wxString inf);
	wxString getFilepath();
	wxString getInfo();
};