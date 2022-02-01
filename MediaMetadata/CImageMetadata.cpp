/**********************************************************
File:CImageMetadata.cpp
Description:handles image metadata
Author: Md Tauseef Alam
**********************************************************/
#pragma once
#include "CImageMetadata.h"
#include "CMediaMetadata.h"

/************************************************************
Overloaded Constructor of CImageMetadata
PARAMS:
f
***********************************************************/
CImageMetadata::CImageMetadata(wxString f)
{
	this->path = f;
	wxFileInputStream input(f);
	img.LoadFile(input, wxBITMAP_TYPE_ANY);
}
//Destructor of class
CImageMetadata::~CImageMetadata()
{}

//setter method
void CImageMetadata::setImage(wxImage image)
{
	img = image;
}
//setter method
void CImageMetadata::setPath(wxString str)
{
	path = str;
}
//getter method
wxImage CImageMetadata::getImage()
{
	return img;
}
//getter method
wxString CImageMetadata::getPath()
{
	return path;
}
/************************************************************
FUNCTION:imageType
DESCRIPTION: For returning the image type.
PARAMS:
no parameter
RETURN: wxString type of image.
***********************************************************/
wxString CImageMetadata::imageType()
{
	wxBitmapType type = img.GetType();
	if (type == wxBITMAP_TYPE_JPEG)
		return "Image Type:\tJPEG";
	else if (type == wxBITMAP_TYPE_PNG)
		return "Image Type:\tPNG";
	else if (type == wxBITMAP_TYPE_BMP)
		return "Image Type:\tBMP";
	else
		return "Image Type:\tNOT SUPPORTED";
}
/************************************************************
FUNCTION:getResolution
DESCRIPTION: For returning the image resolution.
PARAMS:
no parameter
RETURN: resolution of image.
***********************************************************/
wxString CImageMetadata::getResolution()
{
	wxString info = "";
	int xres = img.GetOptionInt(wxIMAGE_OPTION_RESOLUTIONX);
	if (xres)
	{
		info += wxString::Format("%d", xres);
		switch (img.GetOptionInt(wxIMAGE_OPTION_RESOLUTIONUNIT))
		{
		default:
			info += "unknown image resolution units";
			break;

		case wxIMAGE_RESOLUTION_NONE:
			info += " in default units";
			break;

		case wxIMAGE_RESOLUTION_INCHES:
			info += " in";
			break;

		case wxIMAGE_RESOLUTION_CM:
			info += " cm";
			break;
		}
	}
	return info;
}
/************************************************************
FUNCTION:getImageWidth
DESCRIPTION: For returning the image width.
PARAMS:
no parameter
RETURN: int width of image.
***********************************************************/
int CImageMetadata::getImageWidth()
{
	return img.GetWidth();
}
/************************************************************
FUNCTION:getImageHeight
DESCRIPTION: For returning the image height.
PARAMS:
no parameter
RETURN: int height of image.
***********************************************************/
int CImageMetadata::getImageHeight()
{
	return img.GetHeight();
}
/************************************************************
FUNCTION:getImageHeight
DESCRIPTION: For returning the image size in kB.
PARAMS:
no parameter
RETURN: float size of image.
***********************************************************/
int CImageMetadata::getImageSize()
{
	wxFileInputStream inp_stream(path);
	return inp_stream.GetSize() / 1024;
}
/************************************************************
FUNCTION:getImageAlpha
DESCRIPTION: For checking the image Alpha Channel.
PARAMS:
no parameter
RETURN: wxString alpha of image.
***********************************************************/
wxString CImageMetadata::getImageAlpha()
{
	bool alpha = img.HasAlpha();
	if (alpha == true)
		return "Yes";
	else
		return "No";
}