#include "arithmetic.h"

// реализация пользовательского приложения

int main()
{ 
	char s1[] = "(s+4)";
	char s2[] = "(";

	Lexem l(s1); 
	Lexem l2(s2); 

	Lexem l3(s1, 1);
	Lexem l4(s1 + 4, 1);

  return 0;
}
