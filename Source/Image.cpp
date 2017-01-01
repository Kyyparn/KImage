#include "Image.h"
#include <iostream>

using namespace GEI;

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
	return false;
}

bool Image::SaveAs(char* fileName)
{
	this->fileName = fileName;
	
	return Save();
}

bool Image::SaveAs(char* fileName, Filetype fileType)
{
	this->fileName = fileName;
	this->fileType = fileType;

	return Save();
}

bool Image::SaveAs(char* fileName, char* filePath)
{
	this->fileName = fileName;
	this->filePath = filePath;

	return Save();
}

bool Image::SaveAs(char* fileName, char* filePath, Filetype fileType)
{
	this->fileName = fileName;
	this->filePath = filePath;
	this->fileType = fileType;

	return Save();
}

//////////////////////////////////
/////	 LOAD FUNCTIONS		/////
////////////////////////////////
bool Image::Load()
{
	return false;
}

bool Image::Load(char* fileName, char* filePath)
{
	this->fileName = fileName;
	this->filePath = filePath;

	//TODO: Parse filename to get filetype
	printf("Load(char* fileName, char* filePath) not implemented correctly");
	return false;

	Load();
}

bool Image::Load(char* fileName, char* filePath, Filetype fileType)
{
	this->fileName = fileName;
	this->filePath = filePath;
	this->fileType = fileType;

	return Load();
}

//////////////////////////////////
/////	 GET AND SET		/////
////////////////////////////////
char* Image::GetFileName()
{
	return this->fileName;
}

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

void Image::SetFileName(char* fileName)
{
	this->fileName = fileName;
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