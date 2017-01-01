#pragma once

namespace GEI
{
	class Image;

	namespace Loader
	{
		class ImageLoaderManager
		{
		protected:
			static ImageLoaderManager* _instance;
		public:
			static ImageLoaderManager* Instance();

			ImageLoaderManager();
			~ImageLoaderManager();

			bool Save(GEI::Image* image);
			bool Load(GEI::Image* image);

		};
	}
}