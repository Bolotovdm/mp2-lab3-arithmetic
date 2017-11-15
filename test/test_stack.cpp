// тесты для стека

#include "stack.h"
#include <gtest.h>

// ТИПИЗИРОВАННЫЕ ТЕСТЫ

// типизированный класс
template <class T>
class StackTest : public testing::Test {
	protected:
		Stack<T> s1;
		Stack<T> s2;
		Stack<T> s3;

	public:
		StackTest() : s1(5), s2(5), s3(10)
				{

			for (int i = 0; i < 5; i++)
				s1.Push((T)i) ;
			for (int i = 0; i < 5; i++)
				s2.Push((T)i);
			for (int i = 0; i < 10; i++)
				s3.Push((T)i);
				}

		virtual ~StackTest() {}
		
};

// список типов, которые хотим протестировать
typedef ::testing::Types<int, double, char> MyTypes;

// связываем класс и типы
TYPED_TEST_CASE(StackTest, MyTypes);

// тесты
TYPED_TEST(StackTest, can_create_stack)
{
  ASSERT_NO_THROW(s1);
}
