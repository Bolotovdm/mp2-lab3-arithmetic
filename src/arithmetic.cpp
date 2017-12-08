// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"

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
	cout << "Введите значение переменной " << str[0] << " : " ;
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

	for (int i = 0; i < nLexems - 3; i++)
	{
		if ((pLexem[i].type == LBRACKET) && (pLexem[i+1].str[0] == '-') && (pLexem[i + 2].type == NUMBER ))
		{
			pLexem[i + 2].Var = 0 - pLexem[i + 2].Var;
			for (int j = i + 1; j < nLexems - 1; j++)
			{
				pLexem[j] = pLexem[j + 1];
			}
			nLexems--;
		}
	}

	for (int i = 0; i < 1; i++) //  i < nLexems ?? 
	{
		if ((pLexem[i].str[0] == '-') && (pLexem[i + 1].type == NUMBER))
		{

			pLexem[i + 1].Var = 0 - pLexem[i + 1].Var;
			for (int j = i; j < nLexems - 1; j++)
			{
				pLexem[j] = pLexem[j + 1];
			}
			nLexems--;
		}
	}

	for (int i = 0; i < nLexems - 3; i++)
	{
		if ((pLexem[i].type == LBRACKET) && (pLexem[i + 1].str[0] == '-') && (pLexem[i + 2].type == VARIABLE))
		{
			pLexem[i + 2].SetVar();
			pLexem[i + 2].type = NUMBER;
			pLexem[i + 2].Var = 0 - pLexem[i + 2].Var;
			for (int j = i + 1; j < nLexems - 1; j++)
			{
				pLexem[j] = pLexem[j + 1];
			}
			nLexems--;
		}
	}

	for (int i = 0; i < 1; i++) // i < nLexems - 1 ??
	{
		if ((pLexem[i].str[0] == '-') && (pLexem[i + 1].type == VARIABLE))
		{
			pLexem[i + 1].SetVar();
			pLexem[i + 1].type = NUMBER;
			pLexem[i + 1].Var = 0 - pLexem[i + 1].Var;
			for (int j = i; j < nLexems - 1; j++)
			{
				pLexem[j] = pLexem[j + 1];
			}
			nLexems--;
		}
	}
}

arithmetic::arithmetic(const arithmetic & a)
{
	Size = a.Size;
	nLexems = a.nLexems;

	pLexem = new Lexem[Size];
	for (int i = 0; i < nLexems; i++)
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

arithmetic& arithmetic::operator =(const arithmetic & a)
{
	Size = a.Size;
	nLexems= a.nLexems;

	pLexem = new Lexem[Size];
	for (int i = 0; i < nLexems; i++)
		pLexem[i] = a.pLexem[i];

	return (*this);
}

arithmetic arithmetic::PolishEntry()
{
	arithmetic res(*this);
	res.nLexems = 0;
	Stack<Lexem> s1;	
	int k = 0;

	for (int i = 0; i < nLexems; i++)
	{
		if ((pLexem[i].type == NUMBER) || (pLexem[i].type == VARIABLE))
			res += pLexem[i];

		if (pLexem[i].type == LBRACKET)
		{
			s1.Push(pLexem[i]);
		}

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

	return res;
}

double arithmetic::CalculatePolishEntry()
{
	for (int i = 0; i < nLexems; i++)
	{
		if (pLexem[i].type == VARIABLE)
		{
			pLexem[i].SetVar();
			pLexem[i].type = NUMBER;
		}
	}

	Stack<double> s1;
	double res = 0.0;

	for (int i = 0; i < nLexems; i++)
	{
		if (pLexem[i].type == NUMBER)
		{
			s1.Push(pLexem[i].Var);
		}

		if (pLexem[i].type == OPERATOR)
		{
			double A = s1.Pop();
			double B = s1.Pop();

			switch (pLexem[i].str[0])
			{
			case '+':
				res = A + B;
				break;
			case '-':
				res = B - A;
				break;
			case '*':
				res = A * B;
				break;
			case '/':
				res = B / A;
				break;
			}
			s1.Push(res);
		}
	}
	return s1.Pop();
}

void arithmetic::CheckBracket()
{
	int tmp = 0;

	for (int i = 0; i < nLexems; i++)
	{
		if (pLexem[i].type == LBRACKET)
			tmp ++;

		if (pLexem[i].type == RBRACKET)
			tmp --;
	}

	if (tmp < 0)
		cout << " Ошибка. Неправильное количество скобок." << endl;

}

void arithmetic::CheckLetters()
{
	for (int i = 0; i < nLexems; i++)
	{
		if ((pLexem[i].type != LBRACKET) && (pLexem[i].type != RBRACKET) && (pLexem[i].type != NUMBER) && (pLexem[i].type != OPERATOR) && (pLexem[i].type != VARIABLE))
		{
			cout << " Ошибка. Недопустимый символ. " << endl;
		}
	}

	for (int i = 0; i < nLexems - 1 ; i++)
	{
		if ((pLexem[i].type == VARIABLE) && (pLexem[i + 1].type == VARIABLE))
		{
			int k = 1;
			for (int j = i + 2; j < nLexems - 1; j++)
			{
				if (pLexem[j].type != VARIABLE)
				{
					j = nLexems;
				}
				k++;
			}
			cout << " Ошибка. Недопустимое имя переменной. " << endl;
			i = i + k;
		}
	}
}

void arithmetic::CheckOperator()
{
	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == OPERATOR) && (pLexem[i-1].type == OPERATOR))
		{
			cout << " Ошибка. Несколько операций подряд. " << endl;
		}
	}

	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == RBRACKET) && (pLexem[i - 1].type == OPERATOR))
		{
			cout << " Ошибка. Знак операции перед ')'. " << endl;
		}

	}
		
	if ((pLexem[nLexems-1].type == RBRACKET) && (pLexem[nLexems].type == OPERATOR))
		{
			cout << " Ошибка. Знак операции после ')' в конце выражения. " << endl;
		}
	

	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i-1].type == LBRACKET) && (pLexem[i].type == OPERATOR))
		{
			cout << " Ошибка. Знак операции после '('. " << endl;
		}
	}

	if ((pLexem[1].type == LBRACKET) && (pLexem[0].type == OPERATOR))
	{
		cout << " Ошибка. Знак операции перед '(' в начале выражения. " << endl;
	}
}

void arithmetic::CheckPoint()
{
	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == VARIABLE) && (pLexem[i - 1].str[0] == '.'))
		{
			cout << " Ошибка. Точка находится перед переменной. " << endl;
		}

		if ((pLexem[i - 1].type == VARIABLE) && (pLexem[i].str[0] == '.'))
		{
			cout << " Ошибка. Точка находится после переменной. " << endl;
		}
	}

	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == RBRACKET) && (pLexem[i - 1].str[0] == '.'))
		{
			cout << " Ошибка. Точка находится перед ')' " << endl;
		}
	}

	for (int i = 0; i < nLexems - 1; i++)
	{
		if ((pLexem[i].type == RBRACKET) && (pLexem[i + 1].str[0] == '.'))
		{
			cout << " Ошибка. Точка находится после ')' " << endl;
		}
	}

	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == LBRACKET) && (pLexem[i - 1].str[0] == '.'))
		{
			cout << " Ошибка. Точка находится перед '(' " << endl;
		}
	}

	for (int i = 0; i < nLexems - 1; i++)
	{
		if ((pLexem[i].type == LBRACKET) && (pLexem[i + 1].str[0] == '.'))
		{
			cout << " Ошибка. Точка находится после '(' " << endl;
		}
	}
}