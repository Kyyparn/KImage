#pragma once

namespace GEI
{
	class ImageData
	{
		public:
			ImageData(char* data, unsigned int width, unsigned int height);
			
			char* GetData();
			unsigned int GetWidth();
			unsigned int GetHeight();
			
		protected:
			char* data;
			unsigned int width;
			unsigned int height;
	};
}