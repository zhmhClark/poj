#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
double termValue();
double expValue();
double factorValue();

int main()
{
	cout << expValue() << endl;
	return 0;
}

double termValue()
{
	double res = factorValue(); //先求第一个因子
	bool more = true;
	while (more)
	{
		char op = cin.peek();
		if (op == '*' || op == '/')
		{
			cin.get();
			double value = factorValue();
			if (op == '*') res *= value;
			else           res /= value;
		}
		else
			more = false;
	}
	return res;
}

double expValue()
{
	double res = termValue(); //先求第一项
	bool more = true;
	while (more)
	{
		char op = cin.peek();
		if (op == '+' || op == '-')
		{
			cin.get();
			double value = termValue();
			if (op == '+') res += value;
			else           res -= value;
		}
		else
			more = false;
	}
	return res;
}

double factorValue()
{
	double res = 0;
	char op = cin.peek();
	if (op == '(')
	{
		cin.get();
		res = expValue();
		cin.get();
	}
	else
	{
		while (isdigit(op))//处理整数部分
		{
			res = 10 * res + op - '0';
			cin.get();
			op = cin.peek();
		}
		if (op == '.')//处理小数部分
		{
			cin.get();
			op = cin.peek();
			double t = 0.1;
			while (isdigit(op))
			{
				res += (op - '0')*t;
				t *= 0.1;
				cin.get();
				op = cin.peek();
			}
		}
	}
	return res;
}


