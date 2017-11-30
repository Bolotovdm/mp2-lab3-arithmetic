// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"

const char AllLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

Lexem::Lexem(char* s, int k)
{
	strncpy(str, s, k);
	str[k] = '\0';

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
			Var = 0;
			break;
		case '1': type = NUMBER;
			Var = 1;
			break;
		case '2': type = NUMBER;
			Var = 2;
			break;
		case '3': type = NUMBER;
			Var = 3;
			break;
		case '4': type = NUMBER;
			Var = 4;
			break;
		case '5': type = NUMBER;
			Var = 5;
			break;
		case '6': type = NUMBER;
			Var = 6;
			break;
		case '7': type = NUMBER;
			Var = 7;
			break;
		case '8': type = NUMBER;
			Var = 8;
			break;
		case '9': type = NUMBER;
			Var = 9;
			break;
		case 'A': type = VARIABLE;
			break;
		case 'B': type = VARIABLE;
			break;
		case 'D': type = VARIABLE;
			break;
		case 'C': type = VARIABLE;
			break;
		case 'E': type = VARIABLE;
			break;
		case 'F': type = VARIABLE;
			break;
		case 'G': type = VARIABLE;
			break;
		case 'H': type = VARIABLE;
			break;
		case 'I': type = VARIABLE;
			break;
		case 'J': type = VARIABLE;
			break;
		case 'K': type = VARIABLE;
			break;
		case 'L': type = VARIABLE;
			break;
		case 'M': type = VARIABLE;
			break;
		case 'N': type = VARIABLE;
			break;
		case 'O': type = VARIABLE;
			break;
		case 'P': type = VARIABLE;
			break;
		case 'Q': type = VARIABLE;
			break;
		case 'R': type = VARIABLE;
			break;
		case 'S': type = VARIABLE;
			break;
		case 'T': type = VARIABLE;
			break;
		case 'U': type = VARIABLE;
			break;
		case 'V': type = VARIABLE;
			break;
		case 'W': type = VARIABLE;
			break;
		case 'X': type = VARIABLE;
			break;
		case 'Y': type = VARIABLE;
			break;
		case 'Z': type = VARIABLE;
			break;
		case 'a': type = VARIABLE;
			break;
		case 'b': type = VARIABLE;
			break;
		case 'd': type = VARIABLE;
			break;
		case 'c': type = VARIABLE;
			break;
		case 'e': type = VARIABLE;
			break;
		case 'f': type = VARIABLE;
			break;
		case 'g': type = VARIABLE;
			break;
		case 'h': type = VARIABLE;
			break;
		case 'i': type = VARIABLE;
			break;
		case 'j': type = VARIABLE;
			break;
		case 'k': type = VARIABLE;
			break;
		case 'l': type = VARIABLE;
			break;
		case 'm': type = VARIABLE;
			break;
		case 'n': type = VARIABLE;
			break;
		case 'o': type = VARIABLE;
			break;
		case 'p': type = VARIABLE;
			break;
		case 'q': type = VARIABLE;
			break;
		case 'r': type = VARIABLE;
			break;
		case 's': type = VARIABLE;
			break;
		case 't': type = VARIABLE;
			break;
		case 'u': type = VARIABLE;
			break;
		case 'v': type = VARIABLE;
			break;
		case 'w': type = VARIABLE;
			break;
		case 'x': type = VARIABLE;
			break;
		case 'y': type = VARIABLE;
			break;
		case 'z' : type = VARIABLE;
			break;
			
		}
	}
	else if (k != 1)
	{
		type = NUMBER;
		Var = atof(str);
	}
}

Lexem::Lexem(const Lexem & l)
{
	strcpy(str, l.str);

	type = l.type;
	Var = l.Var;
	Pr = l.Pr;
}

Lexem Lexem::operator=(const Lexem & l)
{
	strcpy(str, l.str);

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
	int k = 0; // счетчик лексем
	pLexem = new Lexem [Size];
	for (int i = 0; i < Size; i++)
	{
		if (isdigit(s[i]))
		{
			int j = i; // конец числа
			while (isdigit(s[j]) || (s[j] == '.')) 
			{
				if (s[j] != '/0')
				j++;
			}
				pLexem[k] = Lexem(s + i, j - i);
				k++;
				i = j - 1;
		}
		else 
		{
				pLexem[k] = Lexem(s + i, 1);
				k++;
		}
	}
	nLexems = k;
}

arithmetic::arithmetic(const arithmetic & a)
{
	Size = a.Size;
	nLexems = a.nLexems;

	pLexem = new Lexem[Size];
	for (int i = 0; i < Size; i++)
		pLexem[i] = a.pLexem[i];

}

arithmetic::~arithmetic()
{
	delete[] pLexem;
}

arithmetic& arithmetic::operator +=(const Lexem a)
{
	int size = this->GetNLexems();
	pLexem[size] = a;
	nLexems += 1;

	return *this;
}

double arithmetic::PolishEntry()
{
	arithmetic res(*this);
	res.nLexems = 0;
	Stack<Lexem> s1;	

	for (int i = 0; i < nLexems; i++)
	{
		if ((pLexem[i].type == NUMBER) || (pLexem[i].type == VARIABLE))
			res += pLexem[i];

		if (pLexem[i].type == LBRACKET)
			s1.Push(pLexem[i]);

		if (pLexem[i].type == OPERATOR)
		{
			if (s1.IsEmpty())
				s1.Push(pLexem[i]);
			else
			{
				 Lexem x = s1.Top();
				 while ((s1.IsEmpty()!= 1) &&(x.Pr >= pLexem[i].Pr))  
				 {
					 x = s1.Pop();
					 res += x;
					 x = s1.Top(); 
				 }
				 s1.Push(pLexem[i]);
			}
		}

		if (pLexem[i].type == RBRACKET)
		{
			Lexem x = s1.Pop();
			while (x.type != LBRACKET)
			{
				res += x;
				x = s1.Pop();
			}
		}
	}

	while (!s1.IsEmpty())
	{
		Lexem x = s1.Pop();
		res += x;
	}

	return 0;
}