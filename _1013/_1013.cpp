#include<iostream>
#include<cstring>
using namespace std;
char Left[3][7];
char Right[3][7];
char Result[3][7];
bool isFake(char c, bool light);//¼Ù¶¨ÎªÇá

int main()
{
	int T = 0;
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 3; i++)
		{	
			cin >> Left[i] >> Right[i] >> Result[i];
		}

		for (char c = 'A'; c <= 'L'; c++)
		{
			if(isFake(c,true))
			{
				cout << c << " is the counterfeit coin and it is light."<<endl;
				break;
			}
			if (isFake(c, false))
			{
				cout << c << " is the counterfeit coin and it is heavy."<<endl;
				break;
			}
		}

	}
	return 0;
}

bool isFake(char c, bool light)
{
	int flag = 0;
	for (int i = 0; i < 3; i++)
		if (!(strchr(Right[i], c) || strchr(Left[i], c))) flag++;
	if(flag == 3)
			return false;
	for (int i = 0; i < 3; i++)
	{
		char* pLight=NULL, *pHeavy=NULL;
		
		switch (Result[i][0])
		{
		case 'u':
			pLight = Right[i];
			pHeavy = Left[i];
			break;
		case 'd':
			pLight = Left[i];
			pHeavy = Right[i];
			break;
		case 'e':
			if (strchr(Left[i], c) || strchr(Right[i], c))
				return false;
			break;
		default:
			break;
		}
		
		if (Result[i][0] == 'e')	continue;

		if ( light && (strchr(pHeavy, c)||!strchr(pLight, c)) )
			return false;
		if (!light && (strchr(pLight, c)||!strchr(pHeavy, c)) )
			return false;
	}
	return true;
}
