#pragma once

#include "../ImageData.h";
#include "../FileData.h";

class BMPConverter
{
public:
	static GEI::ImageData ConvertToImageData(const GEI::FileData& fileData);
	static GEI::FileData ConvertToFileData(const GEI::ImageData& imageData);
};