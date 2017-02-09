#pragma once

namespace GEI 
{

	class Image;

	namespace Loader
	{
		class ImageLoader
		{
		public:
			virtual bool Save(Image* image) = 0;
			virtual bool Load(Image* image) = 0;
		protected:
			virtual bool IsCorrectFileType(char* data, char* fileTypeIdentifier, int numberOfBytes);
			virtual char* LoadFileData(Image* image, int size);
		};
	}
}
