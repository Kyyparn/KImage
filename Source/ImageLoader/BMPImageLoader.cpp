#include "BMPImageLoader.h"
#include "../Image.h"
#include <iostream>
#include <fstream>

using namespace GEI;
using namespace Loader;

BMPImageLoader::BMPImageLoader()
{

}

BMPImageLoader::~BMPImageLoader()
{

}

bool BMPImageLoader::Save(Image* image)
{
	return false;
}

bool BMPImageLoader::Load(Image* image)
{
	char* rawData;

	//Bitmap header info
	unsigned int fileSize;
	unsigned int imageDataOffset;

	//DIB header info
	unsigned int dibSize;
	signed int pixelWidth;
	signed int pixelHeight;
	signed short colorPlanes;
	signed short colorDepth; //Bits per pixel
	signed int compression;
	unsigned int imageSize;
	signed int horizontalPPM; //PPM = Pixels per meter
	signed int verticalPPM;
	unsigned int paletteSize;
	unsigned int importantColorSize;

	rawData = this->LoadFileData(image, 14); //Load the first 14 bytes to get the file header, the full filesize and the imageDataOffset
	if (rawData == NULL)	return false;

	//Read Bitmap file header
	if (!IsCorrectFileType(rawData + 0x00, "BM", 2)) return false;
	memcpy(&fileSize, rawData + 0x02, 4); //copy 4 bytes from position rawData + 0x02
	memcpy(&imageDataOffset, rawData + 0x0A, 4); //copy 4 bytes from position rawData + 0x0A

	rawData = this->LoadFileData(image, fileSize); //Load the first 10 bytes to get the file header, the full filesize and the imageDataOffset
	if (rawData == NULL)	return false;

	//Read DIB header
	memcpy(&dibSize, rawData + 0x0E, 4);
	memcpy(&pixelWidth, rawData + 0x12, 4);
	memcpy(&pixelHeight, rawData + 0x16, 4);
	memcpy(&colorPlanes, rawData + 0x1A, 2);
	memcpy(&colorDepth, rawData + 0x1C, 2);
	memcpy(&compression, rawData + 0x1E, 4);
	memcpy(&imageSize, rawData + 0x22, 4);
	memcpy(&horizontalPPM, rawData + 0x26, 4);
	memcpy(&verticalPPM, rawData + 0x2A, 4);
	memcpy(&paletteSize, rawData + 0x2E, 4);
	memcpy(&importantColorSize, rawData + 0x32, 4);

	//Create buffer
	char* imageData = new char[imageSize];
	//Copy imagedata from the raw data into the buffer
	memcpy(imageData, rawData + imageDataOffset, imageSize);

	//Set data in image
	image->SetData(imageData);

	return true;
}