#include<memory>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
char oriLights[5];
char lights[5];
char result[5];

int getBit(char c, int i)//获取字符c在第i位的bit
{
	return (c >> i) & 1;
}

void setBit(char &c, int i, int v)//开关灯
{
	if (v)
	{
		c |= (1 << i);
	}
	else
	{
		c &= !(1 << i);
	}
}

void flipBit(char &c, int i)
{
	c ^= (1 << i);
}

void outPutResult(int t, char result[])
{
	cout << "PUZZLE #" << t << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << getBit(result[i], j);
			if (j < 5)	cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	int T;
	cin >> T;
	int t = 1;
	while (T--)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				int s;
				cin >> s;
				setBit(oriLights[i] , j , s);
			}
		}
		for (int n = 0; n < 64; n++)
		{
			int switchs = n;
			memcpy(lights, oriLights, sizeof(oriLights));
			for (int i = 0; i < 5; i++)
			{
				result[i] = switchs;
				for (int j = 0; j < 6; j++)
				{
					if (getBit(switchs, j))
					{
						if (j > 0)
							flipBit(lights[i], j-1);
						if (j < 5)
							flipBit(lights[i], j + 1);
						flipBit(lights[i], j);
					}
				}
				if (i < 4)
					lights[i + 1] ^= switchs;
				switchs = lights[i];
			}
			if (lights[4] == 0)
			{
				outPutResult(t, result);
				break;
			}
		}
		t++;
	}
}