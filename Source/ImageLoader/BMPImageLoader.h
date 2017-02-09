#pragma once
#include "ImageLoader.h"

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