#include "stdafx.h"
#include "CppUnitTest.h"

#include "../birary_search/binary_search.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ms_tests
{		
	TEST_CLASS(UnitTest1)
	{
	  public:
		
		TEST_METHOD(Below_minimal_even)
		{
      Binary_search<double> bs( {1.0, 2.0, 3.0, 4.0} );
      size_t res;

      Assert::AreEqual(bs.Find(0, res), false);
		}

    TEST_METHOD(One_even)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0, 4.0 });
      size_t res;

      Assert::AreEqual(bs.Find(1, res), true);
      Assert::AreEqual<size_t>(res, 0);
    }

    TEST_METHOD(Two_even)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0, 4.0 });
      size_t res;

      Assert::AreEqual(bs.Find(2, res), true);
      Assert::AreEqual<size_t>(res, 1);
    }

    TEST_METHOD(Three_even)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0, 4.0 });
      size_t res;

      Assert::AreEqual(bs.Find(3, res), true);
      Assert::AreEqual<size_t>(res, 2);
    }

    TEST_METHOD(Four_even)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0, 4.0 });
      size_t res;

      Assert::AreEqual(bs.Find(4, res), true);
      Assert::AreEqual<size_t>(res, 3);
    }

    TEST_METHOD(Above_minimal_even)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0, 4.0 });
      size_t res;

      Assert::AreEqual(bs.Find(5, res), false);
    }

    TEST_METHOD(Below_minimal_odd)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0 });
      size_t res;

      Assert::AreEqual(bs.Find(0, res), false);
    }

    TEST_METHOD(One_odd)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0 });
      size_t res;

      Assert::AreEqual(bs.Find(1, res), true);
      Assert::AreEqual<size_t>(res, 0);
    }

    TEST_METHOD(Two_odd)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0 });
      size_t res;

      Assert::AreEqual(bs.Find(2, res), true);
      Assert::AreEqual<size_t>(res, 1);
    }

    TEST_METHOD(Three_odd)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0 });
      size_t res;

      Assert::AreEqual(bs.Find(3, res), true);
      Assert::AreEqual<size_t>(res, 2);
    }

    TEST_METHOD(Above_minimal_odd)
    {
      Binary_search<double> bs({ 1.0, 2.0, 3.0 });
      size_t res;

      Assert::AreEqual(bs.Find(4, res), false);
    }

	};
}