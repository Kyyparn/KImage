#include "Image.h"
#include "ImageLoader\ImageLoaderManager.h"
#include <iostream>

using namespace GEI;
using namespace Loader;

Image::Image()
{
	
}

Image::~Image()
{

}

//////////////////////////////////
/////	 SAVE FUNCTIONS		/////
////////////////////////////////

bool Image::Save()
{
	return ImageLoaderManager::Instance()->Save(this);
}

bool Image::SaveAs(char* filePath, Filetype fileType)
{
	this->filePath = filePath;
	this->fileType = fileType;

	return Save();
}

bool Image::SaveAs(char* filePath)
{
	this->filePath = filePath;

	return Save();
}

//////////////////////////////////
/////	 LOAD FUNCTIONS		/////
////////////////////////////////
bool Image::Load()
{
	return ImageLoaderManager::Instance()->Load(this);
}

bool Image::Load(char* filePath)
{
	this->filePath = filePath;

	//TODO: Parse filename to get filetype
	printf("Load(char* fileName, char* filePath) not implemented correctly");
	return false;

	Load();
}

bool Image::Load(char* filePath, Filetype fileType)
{
	this->filePath = filePath;
	this->fileType = fileType;

	return Load();
}

//////////////////////////////////
/////	 GET AND SET		/////
////////////////////////////////

char* Image::GetFilePath()
{
	return this->filePath;
}

Filetype Image::GetFileType()
{
	return this->fileType;
}

char* Image::GetData()
{
	return data;
}

void Image::SetFilePath(char* filePath)
{
	this->filePath = filePath;
}

void Image::SetFileType(Filetype fileType)
{
	this->fileType = fileType;
}

void Image::SetData(char* data)
{
	this->data = data;
}