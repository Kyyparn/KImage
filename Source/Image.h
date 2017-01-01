#pragma once

#include "Filetypes.h"

namespace GEI
{
	class Image
	{
	protected:
		char* fileName;
		char* filePath; //TODO: Fix this
		Filetype fileType;
		
		char* data;
	public:
		Image();
		~Image();

		bool Save();

		bool SaveAs(char* fileName);
		bool SaveAs(char* fileName, Filetype fileType);
		bool SaveAs(char* fileName, char* filePath);
		bool SaveAs(char* fileName, char* filePath, Filetype fileType);

		bool Load();
		bool Load(char* fileName, char* filePath);
		bool Load(char* fileName, char* filePath, Filetype fileType);

		//Get and set
		char* GetFileName();
		char* GetFilePath();
		Filetype GetFileType();
		char* GetData();

		void SetFileName(char* fileName);
		void SetFilePath(char* filePath);
		void SetFileType(Filetype fileType);
		void SetData(char* data);
	};
}