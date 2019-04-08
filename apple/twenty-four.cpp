#include<iostream>
#include<cmath>
#define EPS 1e-6
using namespace std;

double a[5];
bool isEqual(double x, double y)
{
	return fabs(x - y) <= EPS;
}

bool count24(double a[], int n)
{
	if (n == 1)                            //boundary
	{	return isEqual(a[0],24);	}

	double b[5];
	for(int i = 0 ; i < n-1 ;i++ )
		for (int j = i + 1; j < n; j++)    //取两个数
		{
			int m = 0;
			for (int k = 0; k < n; k++)
				if (k != i && k != j)	b[m++] = a[k];

			b[m] = a[i] + a[j];
			if (count24(b, m + 1))	return true;
			
			b[m] = a[i] - a[j];
			if (count24(b, m + 1))	return true;
			
			b[m] = a[i] * a[j];
			if (count24(b, m + 1))	return true;
			
			b[m] = a[j] - a[i];
			if (count24(b, m + 1))	return true;
			
			if (!isEqual(0, a[j]))
			{
				b[m] = a[i] / a[j];
				if (count24(b, m + 1))	return true;
			}
			
			if (!isEqual(0, a[i]))
			{
				b[m] = a[j] / a[i];
				if (count24(b, m + 1))	return true;
			}
		}
}
