#include<iostream>
#include<vector>
using namespace std;

void hanoi(int n, char x, char y, char z);
int main()
{
	int n;
	cout << "please input the number\n";
	cin >> n;
	hanoi(n,'A','B','C');
	return 0;
}

void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		cout << x << "-->" << z << endl;
	else
	{
		hanoi(n - 1, x, z, y);
		cout << x << "-->" << z << endl;
		hanoi(n - 1, y, x, z);
	}
}   