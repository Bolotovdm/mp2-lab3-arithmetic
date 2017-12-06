#include "arithmetic.h"

// реализация пользовательского приложения

int main()
{ 
	char s1[] = "(.x+s+4.5)";

	arithmetic A(s1), B; 

	A.CheckLetters();

	B = A.PolishEntry(); 
	double res = 0.0;
	res = B.CalculatePolishEntry();

	cout << res;

  return 0;

  cin.get();
}
