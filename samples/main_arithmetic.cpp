#include "arithmetic.h"

// реализация пользовательского приложения

int main()
{ 
	setlocale(LC_ALL, "Russian");

	char s1[] = "(6+10-4)/(1+1*2)+1";

	arithmetic A(s1), B; 

	A.CheckLetters();
	A.CheckBracket();
	A.CheckOperator();
	A.CheckPoint();

	B = A.PolishEntry(); 
	double res = 0.0;
	res = B.CalculatePolishEntry();

	cout << res;

  return 0;

  cin.get();
}
