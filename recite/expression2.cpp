#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;
double termValue();
double expValue();
double factorValue();

int main()
{
	cout << expValue() << endl;
	return 0;
}

double expValue()
{
	double res = termValue();
	bool more = true;
	while (more)
	{
		char op = cin.peek();
		switch (op)
		{
		case '+':
			cin.get();
			double value = termValue();
			res += value;
			break;
		case '-':
			cin.get();
			double value = termValue();
			res -= value;
			break;
		default:
			more = false;
		}
	}
	return res;
}


double termValue()
{
	double res = factorValue();
	bool more = true;
	while (more)
	{
		char op = cin.peek();
		switch (op)
		{
		case '*':
			cin.get();
			double value = factorValue();
			res *= value;
			break;
		case '/':
			cin.get();
			double value = factorValue();
			res /= value;
			break;
		default:
			more = false;
		}
	}
	return res;
}

double factorValue()
{

}