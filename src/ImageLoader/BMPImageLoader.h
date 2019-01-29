#pragma once
#include "ImageLoader.h"

#define BMPHeaderSize 14
#define DIBHeaderSize 40

namespace GEI
{
	class Image;

	namespace Loader
	{
		class BMPImageLoader : public ImageLoader
		{
		public:
			BMPImageLoader();
			~BMPImageLoader();

			bool Save(Image* image);
			bool Load(Image* image);
		};
	}
}