// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"

const char AllOperators[] = "+-*/";

Lexem::Lexem(char* s, int k)
{
	strcpy(str, s);
	if (k == 1)
	{
		switch (str[0])
		{
		case '(': type = LBRACKET;
			Pr = 0;
			break;
		case ')': type = RBRACKET;
			break;
		case '+': type = OPERATOR;
			Pr = 1;
			break;
		case '-': type = OPERATOR;
			Pr = 1;
			break;
		case '*': type = OPERATOR;
			Pr = 2;
			break;
		case '/': type = OPERATOR;
			Pr = 2;
			break;
		case '0': type = NUMBER;
			break;
		case '1': type = NUMBER;
			break;
		case '2': type = NUMBER;
			break;
		case '3': type = NUMBER;
			break;
		case '4': type = NUMBER;
			break;
		case '5': type = NUMBER;
			break;
		case '6': type = NUMBER;
			break;
		case '7': type = NUMBER;
			break;
		case '8': type = NUMBER;
			break;
		case '9': type = NUMBER;
			break;
		case 'x': type = VARIABLE;
			break;
		case 'y': type = VARIABLE;
			break;
		case 'z': type = VARIABLE;
			break;
		case 'v': type = VARIABLE;
			break;
		case 'u': type = VARIABLE;
			break;
		}
	}
	else if (k != 1)
	{
		type = NUMBER;
	}
}

Lexem::Lexem(const Lexem & l)
{
	*this->str = *l.str;
	type = l.type;
	Var = l.Var;
	Pr = l.Pr;
}

Lexem Lexem::operator=(const Lexem & l)
{
	*this->str = *l.str;
	type = l.type;
	Var = l.Var;
	Pr = l.Pr;

	return *this;
}

void Lexem::SetVar()
{
	cout << "Enter the value of the variable: ";
	cin >> Var ;
	cout << endl;
}

arithmetic::arithmetic(char* s)
{
	Size = strlen(s);

	pLexem = new Lexem [Size];
	for (int i = 0; i < Size; i++)
		pLexem[i] = Lexem(s + i, 1);

}

arithmetic::arithmetic(const arithmetic & a)
{
	Size = a.Size;
	
	pLexem = new Lexem[Size];
	for (int i = 0; i < Size; i++)
		pLexem[i] = a.pLexem[i];

}

arithmetic::~arithmetic()
{
	delete[] pLexem;
}