/**********************************************************
File:CMediaMetadata.cpp
Description:handles media metadata
Author: Md Tauseef Alam
**********************************************************/
#include "CMediaMetadata.h"
//setter function
void CMediaMetadata::setFilepath(wxString str)
{
	filepath = str;
}
//setter function
void CMediaMetadata::setInfo(wxString inf)
{
	info = inf;
}
//getter function
wxString CMediaMetadata::getFilepath()
{
	return filepath;
}
//getter function
wxString CMediaMetadata::getInfo()
{
	return info;
}