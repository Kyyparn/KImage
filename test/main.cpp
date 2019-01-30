#include "BMPTester.h"

#include <cassert>

using namespace KImage::Tester;

int main(int argc, char* argv[])
{
	BMPTester bmpTester = BMPTester();
	bool bmpTesterResult = bmpTester.RunTests("");
	assert(bmpTesterResult);



	return 0;
}