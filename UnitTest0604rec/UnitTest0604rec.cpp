#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_04rec/Lab_06_04rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0604rec
{
	TEST_CLASS(UnitTest0604rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 0;
			int a[6] = { -5, 0, 3, -2, 6, 0 };
			k = Multiple(a, 6, 0, 1);

			Assert::AreEqual(k, 18);
		}
	};

}
