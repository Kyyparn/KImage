//#pragma once
//#include "Filetypes.h"
//
//namespace KImage
//{
//	class Image
//	{
//	protected:
//		char* filePath; //TODO: Fix this
//		Filetype fileType;
//		
//		char* data;
//		unsigned int dataSize;
//
//		unsigned int imageWidth;
//		unsigned int imageHeight;
//	public:
//		Image();
//		~Image();
//
//		bool Save();
//
//		bool SaveAs(Filetype fileType);
//		bool SaveAs(char* filePath);
//		bool SaveAs(char* filePath, Filetype fileType);
//
//		bool Load();
//		bool Load(char* filePath);
//		bool Load(char* filePath, Filetype fileType);
//
//		//Get and set
//		char* GetFilePath();
//		Filetype GetFileType();
//		char* GetData();
//		unsigned int GetDataSize();
//		unsigned int GetImageWidth();
//		unsigned int GetImageHeight();
//
//		void SetFilePath(char* filePath);
//		void SetFileType(Filetype fileType);
//		void SetData(char* data);
//		void SetData(char* data, unsigned int dataSize);
//		void SetImageWidth(unsigned int imageWidth);
//		void SetImageHeight(unsigned int imageHeight);
//	};
//}