#include<iostream>
#include<cmath>
using namespace std;
int N;
int queenPos[100];   //��ʺ�λ�ã����Ͻ�Ϊ��0��0��
void nQueen(int k);  //�� 0~��k-1�����Ѿ��ںõ�����£��ڴ�K��N��
int main()
{
	cin >> N;
	nQueen(0);
	return 0;
}

void nQueen(int k)
{
	int i;
	if (k == N)  //N���ʺ��Ѱںã���������
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
		if (j == k) //û��break,��i��λ�ÿ���
		{
			queenPos[k] = i;
			nQueen(k + 1);
		}
	}
}