#pragma once

#include "FileData.h"

namespace KImage
{
	namespace IO
	{
		class FileHandler
		{
		public:
			FileHandler();

			void WriteToFile(char* path, const KImage::FileData& fileData);
			KImage::FileData ReadFromFile(char* path);
		};
	}
}