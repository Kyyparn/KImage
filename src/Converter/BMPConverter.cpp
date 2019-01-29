#include "BMPConverter.h"

#include "../ImageData.h"
#include "../FileData.h"

//#include <stdio.h>
#include <string.h>

using namespace GEI;

ImageData BMPConverter::ConvertToImageData(const FileData& fileData)
{
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

	char* rawData = fileData.GetData();

	//Read Bitmap file header
	//if (!IsCorrectFileType(rawData + 0x00, "BM", 2)) return false;
	memcpy(&fileSize, rawData + 0x02, 4); //copy 4 bytes from position rawData + 0x02
	memcpy(&imageDataOffset, rawData + 0x0A, 4); //copy 4 bytes from position rawData + 0x0A

	//rawData = this->LoadFileData(image, fileSize); //Load the first 10 bytes to get the file header, the full filesize and the imageDataOffset
	//if (rawData == NULL)	return false;

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

	char* imageData = new char[imageSize];
	memcpy(imageData, rawData + imageDataOffset, imageSize);

	return ImageData(imageData, imageWidth, imageHeight);
}

FileData BMPConverter::ConvertToFileData(const ImageData& imageData)
{

}