#include "FileHandler.h"
#include <stdio.h>
#include <fstream>

using namespace KImage;
using namespace KImage::IO;

void FileHandler::WriteToFile(char* path, const FileData& fileData) 
{
	std::ofstream outStream(path, std::ifstream::binary);

	if (outStream)
	{
		outStream.write(fileData.GetData(), fileData.GetSize());
		outStream.close();
	}
}

FileData FileHandler::ReadFromFile(char* path)
{
	std::ifstream inStream(path, std::ifstream::binary);

	if (inStream)
	{
		inStream.seekg(0, inStream.end);
		int fileSize = inStream.tellg();
		inStream.seekg(0, inStream.beg);

		char* buffer = new char[fileSize];

		inStream.read(buffer, fileSize);
		inStream.close();

		FileData fileData(buffer, fileSize);
		return fileData;
	}

	return FileData(0, -1);
}