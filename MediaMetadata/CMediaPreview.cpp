/**********************************************************
File:CMediaPreview.cpp
Description:handles image display
Author: Md Tauseef Alam
**********************************************************/
#pragma once
#include "CMediaPreview.h"
#include "CImageMetadata.h"
#include "CMainWindow.h"

/************************************************************
Overloaded Constructor of CMediaPreview
PARAMS:
p,im
***********************************************************/
CMediaPreview::CMediaPreview(wxPanel* p, wxImage im) :wxPanel(p, wxID_ANY, wxDefaultPosition, IMG_SIZE)
{
	m_img = im;
	display();
	new wxStaticBitmap(this, wxID_ANY, bitmap);
}
//Destructor of class
CMediaPreview::~CMediaPreview()
{
	m_img.Destroy();
}

/************************************************************
FUNCTION: display
DESCRIPTION: Used to display image on panel
PARAMS:
nothing
RETURN : Nothing
***********************************************************/
void CMediaPreview::display()
{
	wxSize s = IMG_SIZE;
	m_img = m_img.Rescale(s.x, s.y, wxIMAGE_QUALITY_HIGH);
	bitmap = wxBitmap(m_img);
}