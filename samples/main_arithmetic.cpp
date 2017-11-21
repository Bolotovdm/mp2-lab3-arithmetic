#include "arithmetic.h"

// реализация пользовательского приложения

int main()
{ 
	char s1[] = "(x+s+45)";
	char s2[] = "(";

	arithmetic A(s1); 

	Lexem l1(s1 , 1);
	Lexem l2(s1 + 1, 1);
	Lexem l3(s1 + 2, 1);
	Lexem l4(s1 + 3, 1);
	Lexem l5(s1 + 4, 1);
	Lexem l6(s1 + 5, 2);
	Lexem l7(s1 + 7, 1);

	Lexem l8 = l2;

	l8.SetVar();

	l2 = l8;

  return 0;
}
