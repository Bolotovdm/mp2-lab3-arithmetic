// ����� ��� �����

#include "stack.h"
#include <gtest.h>

// �������������� �����

// �������������� �����
template <class ValType>
class StackTest : public testing::Test {
	protected:
		Stack<T> s1;
		Stack<T> s2;
		Stack<T> s3;

	public:
		StackTest() : s1(5), s2(5), m3(10)
		{
			for (int i = 0; i < 5; i++)
				s1.pStack[i] = (T)(i*5);
			for (int i = 0; i < 5; i++)
				s2.pStack[i] = (T)(i*5);
			for (int i = 0; i < 10; i++)
				s3.pStack[i] = (T)(i*5);
		}

		virtual ~StackTest() {}

};

// ������ �����, ������� ����� ��������������
typedef ::testing::Types<int, double> MyTypes;

// ��������� ����� � ����
TYPED_TEST_CASE(StackTest, MyTypes);

// �����
TYPED_TEST(StackTest, can_create_stack)
{
  ASSERT_NO_THROW(s1);
}
