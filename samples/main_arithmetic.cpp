#include "arithmetic.h"

// реализация пользовательского приложения

int main()
{ 
	char s1[] = "(x+s+4575)";

	arithmetic A(s1); 

	A.CheckLetters();

	A = A.PolishEntry(); 
	double res = 0.0;
	res = A.CalculatePolishEntry();

	cout << res;

  return 0;

  cin.get();
}
