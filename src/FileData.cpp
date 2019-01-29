#include "FileData.h"

using namespace GEI;

FileData::FileData(char* data, int size) 
{
	this->data = data;
	this->size = size;
}

char* FileData::GetData() const
{
	return this->data;
}

int FileData::GetSize() const
{
	return this->size;
}