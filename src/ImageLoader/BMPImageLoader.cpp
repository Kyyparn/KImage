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
	char* data;
	char* header;

	__int32 fileSize = BMPHeaderSize + DIBHeaderSize + image->GetDataSize();
	__int32 headerSize = BMPHeaderSize + DIBHeaderSize;

	data = new char[fileSize];
	header = new char[headerSize];
	
	//Data to insert into header
	int imageWidth = image->GetImageWidth();
	int imageHeight = image->GetImageHeight();
	signed short colorPlanes = 1;
	signed short colorDepth = 8; //Bits per pixel
	signed int compression = 0;
	unsigned int imageSize = image->GetDataSize();
	signed int horizontalPPM = 2835; //PPM = Pixels per meter
	signed int verticalPPM = 2835;
	unsigned int paletteSize = 0;
	unsigned int importantColorSize = 0;

	//Write bmp header
	memcpy(header, "BM", 2);
	memcpy(header + 0x02, &fileSize, 4);
	memcpy(header + 0x0A, &headerSize, 4);

	//Write dib header
	*(int*)(header + 0x0E) = DIBHeaderSize;
	*(int*)(header + 0x12) = imageWidth;
	*(int*)(header + 0x16) = imageHeight;
	*(short*)(header + 0x1A) = colorPlanes;
	*(short*)(header + 0x1C) = colorDepth;
	*(int*)(header + 0x1E) = compression;
	*(int*)(header + 0x22) = imageSize;
	*(int*)(header + 0x26) = horizontalPPM;
	*(int*)(header + 0x2A) = verticalPPM;
	*(int*)(header + 0x2E) = paletteSize;
	*(int*)(header + 0x32) = importantColorSize;

	memcpy(data, header, headerSize);
	memcpy(data + headerSize, image->GetData(), image->GetDataSize());
	
	return SaveDataToFile(image, data, fileSize);
}

bool BMPImageLoader::Load(Image* image)
{
	char* rawData;

	//Bitmap header info
	unsigned int fileSize;
	unsigned int imageDataOffset;

	//DIB header info
	unsigned int dibSize;
	unsigned int imageWidth;
	unsigned int imageHeight;
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
	memcpy(&imageWidth, rawData + 0x12, 4);
	memcpy(&imageHeight, rawData + 0x16, 4);
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
	image->SetData(imageData, imageSize);
	image->SetImageWidth(imageWidth);
	image->SetImageHeight(imageHeight);

	return true;
}