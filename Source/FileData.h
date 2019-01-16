#pragma once

namespace GEI
{
	class FileData
	{
		public:
			FileData(char* data, int size);

			char* GetData() const;
			int GetSize() const;
			
		protected:
			char* data;
			int size;
	};
}