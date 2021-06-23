#include "pch.h"
#include "CppUnitTest.h"
#include "BinaryTree.h"
#include "DoubleLinkedList.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestBinaryTree)
	{
	public:
		
		TEST_METHOD(BinaryTreeTest)
		{

		}
	};

	TEST_CLASS(UnitTestDoubleLinkedList)
	{
	public:
		TEST_METHOD(DoubleLinkedList)
		{
			CDDS::DoubleLinkedList list;
			Assert::IsTrue(list.isEmpty());
			Assert::IsTrue(list.count() == 0);

			list.pushFront(1);
			Assert::IsTrue(list.count() == 1);
			Assert::IsFalse(list.isEmpty());


			list.pushFront(2);
			Assert::IsTrue(list.count() == 2);
			Assert::IsTrue(list.first() == 2);
			Assert::IsTrue(list.last() == 1);

			list.pushBack(5);
			Assert::IsTrue(list.count() == 3);
			Assert::IsTrue(list.first() == 2);
			Assert::IsTrue(list.last() == 5);
		}
	};
}
