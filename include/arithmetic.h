// ���������� ������� � ������� ��� ���������� �������������� ���������

#include <iostream>
#include "stack.h"

using namespace std;

 enum LexemType { NUMBER, OPERATOR, VARIABLE, LBRACKET, RBRACKET };

struct Lexem
{
	char str[10];
	LexemType type;
	double Var;
	int Pr;

	Lexem() {};
	Lexem(char* s, int k);

	Lexem(const Lexem & l);
	Lexem operator=(const Lexem & l);
	void SetVar();
};

class arithmetic
{
	Lexem* pLexem;
	int Size;
	int nLexems;

public:
	arithmetic(char* s);
	arithmetic(const arithmetic & a);
	~arithmetic();

	int GetNLexems() { return nLexems; };
	double PolishEntry();

	arithmetic& operator +=(const Lexem a);
};