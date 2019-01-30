#include "ImageData.h"

using namespace KImage;

ImageData::ImageData(char* data, unsigned int width, unsigned int height)
{
	this->data = data;
	this->width = width;
	this->height = height;
}

char* ImageData::GetData()
{
	return this->data;
}

unsigned int ImageData::GetWidth()
{
	return this->width;
}

unsigned int ImageData::GetHeight()
{
	return this->height;
}