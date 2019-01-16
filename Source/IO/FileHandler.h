#pragma once

#include "../FileData.h"

class FileHandler
{
public:
	FileHandler();

	void WriteToFile(char* path, const GEI::FileData& fileData);
	GEI::FileData ReadFromFile(char* path);
};