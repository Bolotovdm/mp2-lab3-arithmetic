// ���������� ������� � ������� ��� ���������� �������������� ���������
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
		else // ��������� ��� +=/-
		{
		}

//		isalpha(s[0]); // ����� �� ���
//		isdigit(s[0]); // ����� �� ���
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
	else // ��� �����
	{}
}