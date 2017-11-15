// объ€вление функций и классов дл€ вычислени€ арифметических выражений

#include <iostream>
#include "stack.h"

using namespace std;

 enum LexemType { NUMBER, OPERATOR, VARIABLE, LBRACKET, RBRACKET };

struct Lexem
{
	char str[10];
	LexemType type;
	double Var;

	Lexem(char* s); 
	Lexem(char* s, int k);
		
		//Lexem(const Lexem & l);
	//Lexem operator=(const Lexem & L);
	//void SetVar();
};