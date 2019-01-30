#pragma once

namespace KImage
{
	class FileData
	{
		public:
			FileData(char* data, int size);
			FileData(const FileData& fileData2);

			~FileData();

			char* GetData() const;
			int GetSize() const;
			
		protected:
			char* data;
			int size;
	};
}