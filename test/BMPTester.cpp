#include "BMPTester.h"
#include "IO/FileHandler.h"
#include "FileData.h"

using namespace KImage::Tester;
using namespace KImage::IO;
using namespace KImage;

bool BMPTester::RunTests(char* path)
{
	FileHandler fileHandler = FileHandler();

	FileData file = fileHandler.ReadFromFile(path);
}