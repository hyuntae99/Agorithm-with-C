#include <stdio.h>
#include <iostream>
using namespace std;
// n�� �ִ����
#define MAX 100000

int n;
// 2���� �迭
int dp[MAX][4] = {0, };

int main()
{
	cin >> n;

	// �ʱⰪ ����
	dp[0][1] = 1;

	// ��ȭ���� �̿��� DPǮ��
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			// �迭 �ε��� ������ʵ��� ����.
			if ((i - j) >= 0)
			{
				if (j == 3)
					dp[i][j] = (dp[i - j][1] + dp[i - j][2]) % 1004;
				else
					dp[i][j] = (dp[i - j][1] + dp[i - j][2] + dp[i - j][3]) % 1004;
			}

	// ���� ���
	cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1004 << endl;

	return 0;
}
