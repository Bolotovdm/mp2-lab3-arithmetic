// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"

TEST(arithmetic, can_get_nlexems)
{
	arithmetic tmp("50/5*2-19");
	int a = tmp.GetNLexems();

	EXPECT_EQ(7,a);
}

TEST(arithmetic, can_make_up_polish_entry)
{
	arithmetic tmp("(5*5+5)/(2*3)");
	tmp = tmp.PolishEntry();

	char tmp2[9];
	tmp2[0] = '5';
	tmp2[1] = '5';
	tmp2[2] = '*';
	tmp2[3] = '5';
	tmp2[4] = '+';
	tmp2[5] = '2';
	tmp2[6] = '3';
	tmp2[7] = '*';
	tmp2[8] = '/';

	bool res = true;
	for (int i = 0; i < 9; i++)
		if (tmp2[i] != tmp.GetCharLexem(i))
			res = false;

	EXPECT_EQ(true,res);
}

TEST(arithmetic, can_copied_arithmetic)
{
	arithmetic tmp("(5*1+7)");
	arithmetic tmp2(tmp);

	char tmp3[7];
	tmp3[0] = '(';
	tmp3[1] = '5';
	tmp3[2] = '*';
	tmp3[3] = '1';
	tmp3[4] = '+';
	tmp3[5] = '7';
	tmp3[6] = ')';

	bool res = true;
	for (int i = 0; i < 7; i++)
		if (tmp3[i] != tmp2.GetCharLexem(i))
			res = false;

	EXPECT_EQ(true,res);
}

TEST(arithmetic, can_calculate_polish_entry)
{
	arithmetic tmp("(8+2*5)/(1+3*2-4)");
	tmp = tmp.PolishEntry();
	double res = tmp.CalculatePolishEntry();

	EXPECT_EQ(6,res);
}

TEST(arithmetic, can_compare_two_arithmetic)
{
	arithmetic tmp("(8+2*5)/(1+3*2-4)");
	arithmetic tmp2("0");
	tmp2 = tmp;

	char tmp3[17];
	tmp3[0] = '(';
	tmp3[1] = '8';
	tmp3[2] = '+';
	tmp3[3] = '2';
	tmp3[4] = '*';
	tmp3[5] = '5';
	tmp3[6] = ')';
	tmp3[7] = '/';
	tmp3[8] = '(';
	tmp3[9] = '1';
	tmp3[10] = '+';
	tmp3[11] = '3';
	tmp3[12] = '*';
	tmp3[13] = '2';
	tmp3[14] = '-';
	tmp3[15] = '4';
	tmp3[16] = ')';

	bool res = true;
	for (int i = 0; i < 17; i++)
		if (tmp3[i] != tmp2.GetCharLexem(i))
			res = false;

	EXPECT_EQ(true,res);
}

TEST(arithmetic, cam_check_bracket)
{
	arithmetic tmp("(()");
	arithmetic tmp2("(4+5)");
	arithmetic tmp3("()");

	bool res;
	bool res2;
	bool res3;

	res = tmp.CheckBracket();
	res2 = tmp2.CheckBracket();
	res3 = tmp3.CheckBracket();

	EXPECT_EQ(false,res);
	EXPECT_EQ(true,res2);
	EXPECT_EQ(true,res3);
}

TEST(arithmetic, cam_check_point)
{
	arithmetic tmp(".a");
	arithmetic tmp2("a.");
	arithmetic tmp3(".)");
	arithmetic tmp4("(.");
	arithmetic tmp5(".(");
	arithmetic tmp6(").");

	bool res;
	bool res2;
	bool res3;
	bool res4;
	bool res5;
	bool res6;

	res = tmp.CheckPoint();
	res2 = tmp2.CheckPoint();
	res3 = tmp3.CheckPoint();
	res4 = tmp4.CheckPoint();
	res5 = tmp5.CheckPoint();
	res6 = tmp6.CheckPoint();

	EXPECT_EQ(false,res);
	EXPECT_EQ(false,res2);
	EXPECT_EQ(false,res3);
	EXPECT_EQ(false,res4);
	EXPECT_EQ(false,res5);
	EXPECT_EQ(false,res6);
}

TEST(arithmetic, can_check_operator)
{
	arithmetic tmp("++");
	arithmetic tmp2("4+5+");
	arithmetic tmp3("4+)");
	arithmetic tmp4(")+");
	arithmetic tmp5("(+");
	arithmetic tmp6("+(");

	bool res;
	bool res2;
	bool res3;
	bool res4;
	bool res5;
	bool res6;

	res = tmp.CheckOperator();
	res2 = tmp2.CheckOperator();
	res3 = tmp3.CheckOperator();
	res4 = tmp4.CheckOperator();
	res5 = tmp5.CheckOperator();
	res6 = tmp6.CheckOperator();

	EXPECT_EQ(false,res);
	EXPECT_EQ(false,res2);
	EXPECT_EQ(false,res3);
	EXPECT_EQ(false,res4);
	EXPECT_EQ(false,res5);
	EXPECT_EQ(false,res6);
}

TEST(arithmetic, can_check_letters)
{
	arithmetic tmp("^");
	arithmetic tmp2("aaa");
	
	bool res;
	bool res2;

	res = tmp.CheckLetters();
	res2 = tmp2.CheckLetters();

	EXPECT_EQ(false,res);
	EXPECT_EQ(false,res2);
}