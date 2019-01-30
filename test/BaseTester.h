#pragma once

namespace KImage
{
	namespace Tester
	{
		class BaseTester
		{
		public:
			virtual bool RunTests(char* path) = 0;
		};
	}
}