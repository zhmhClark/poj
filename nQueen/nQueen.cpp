#include<iostream>
#include<cmath>
using namespace std;
int N;
int queenPos[100];   //存皇后位置，左上角为（0，0）
void nQueen(int k);  //在 0~（k-1）行已经摆好的情况下，摆从K到N行
int main()
{
	cin >> N;
	nQueen(0);
	return 0;
}

void nQueen(int k)
{
	int i;
	if (k == N)  //N个皇后已摆好，则输出结果
	{
		for (i = 0; i < N; i++)
			cout << queenPos[i] + 1 << " ";
		cout << endl;
		return;
	}
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < k; j++)
		{
			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j))
				break;
		}
		if (j == k) //没有break,第i个位置可行
		{
			queenPos[k] = i;
			nQueen(k + 1);
		}
	}
}