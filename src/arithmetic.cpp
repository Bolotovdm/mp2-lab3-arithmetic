// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"

const char AllOperators[] = "+-*/";

Lexem::Lexem(char* s)
{
	strcpy (str, s);
	if (strcmp(s, "(") == 0)
		{
			type = LBRACKET;
		}
	else 
		if (strcmp(s, ")") == 0)
		{
			type = RBRACKET;
		}
		else // прописать для +=/-
		{
		}

//		isalpha(s[0]); // буква ли это
//		isdigit(s[0]); // цифра ли это
}


Lexem::Lexem(char* s, int k)
{
	if (k == 1)
	{
		switch(s[0])
		{
		case '(': {type = LBRACKET; }
		case ')': {type = RBRACKET; }

		}
	}
	else // это число
	{}
}