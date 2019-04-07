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
	double res = factorValue(); //�����һ������
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
	double res = termValue(); //�����һ��
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
		while (isdigit(op))//������������
		{
			res = 10 * res + op - '0';
			cin.get();
			op = cin.peek();
		}
		if (op == '.')//����С������
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


