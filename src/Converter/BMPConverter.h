#pragma once

#include "ImageData.h";
#include "FileData.h";

namespace KImage
{
	namespace Converters
	{
		class BMPConverter
		{
		public:
			static ImageData ConvertToImageData(const FileData& fileData);
			static FileData ConvertToFileData(const ImageData& imageData);
		};
	}
}