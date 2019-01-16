#include "ImageLoader.h"
#include "../Image.h"
#include <stdio.h>
#include <string.h>

using namespace GEI;
using namespace Loader;

bool ImageLoader::IsCorrectFileType(char* data, char* fileTypeIdentifier, int numberOfBytes)
{
	if (memcmp(data, fileTypeIdentifier, numberOfBytes) == 0)
	{
		return true;
	}

	return false;
}

char* ImageLoader::LoadFileData(Image* image, int size)
{
	FILE* file = fopen(image->GetFilePath(), "r");
	char* data = NULL;

	if (file != NULL)
	{
		data = new char[size]; //Create buffer

		size_t result = fread(data, 1, size, file);
		
		//If it's not correct size, clear buffer and set pointer to 0
		if (result != size)
		{
			delete[] data;
			data = NULL;
		}

		fclose(file);
	}

	if (data == NULL) printf("Failed to open file \n");

	return data;
}

bool ImageLoader::SaveDataToFile(Image* image, char* data, int size)
{
	FILE* file = fopen(image->GetFilePath(), "wb");

	if (file != NULL)
	{
		fwrite(data, 1, size, file);

		fclose(file);
	}
	else
	{
		return false;
	}

	return true;
}