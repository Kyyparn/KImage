#pragma once
#include "Filetypes.h"

namespace GEI
{
	class Image
	{
	protected:
		char* filePath; //TODO: Fix this
		Filetype fileType;
		
		char* data;
	public:
		Image();
		~Image();

		bool Save();

		bool SaveAs(Filetype fileType);
		bool SaveAs(char* filePath);
		bool SaveAs(char* filePath, Filetype fileType);

		bool Load();
		bool Load(char* filePath);
		bool Load(char* filePath, Filetype fileType);

		//Get and set
		char* GetFilePath();
		Filetype GetFileType();
		char* GetData();

		void SetFilePath(char* filePath);
		void SetFileType(Filetype fileType);
		void SetData(char* data);
	};
}