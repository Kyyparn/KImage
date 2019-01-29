#pragma once

namespace GEI
{
	class Image;

	namespace Loader
	{
		class BMPImageLoader;

		class ImageLoaderManager
		{
		private:
			static ImageLoaderManager* m_instance;
			ImageLoaderManager();
			~ImageLoaderManager();

			BMPImageLoader* bmpLoader;
		public:
			static ImageLoaderManager* Instance();

			bool Save(GEI::Image* image);
			bool Load(GEI::Image* image);

		};
	}
}