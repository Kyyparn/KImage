#include "FileData.h"
#include <string.h>

using namespace KImage;

FileData::FileData(char* data, int size) 
{
	this->data = data;
	this->size = size;
}

FileData::FileData(const FileData& fileData2)
{
	this->size = fileData2.GetSize();
	this->data = new char[this->size];
	memcpy(this->data, fileData2.GetData(), this->size);
}

FileData::~FileData()
{
	delete[] this->data;
}

char* FileData::GetData() const
{
	return this->data;
}

int FileData::GetSize() const
{
	return this->size;
}