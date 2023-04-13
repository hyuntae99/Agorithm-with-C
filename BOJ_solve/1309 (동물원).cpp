#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100000

int n;
// ������ �迭
int dp[MAX][2] = { 0, };

int main()
{
	cin >> n;

	// �ʱⰪ ����
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		// dp[i][0] = i��° �츮�� ���ڸ� ���� �ʴ� ��� -> ����, �������� �����Ƿ� dp[i-1][1] x 2!
		dp[i][0] = (dp[i - 1][0] + (dp[i - 1][1] * 2)) % 9901;
		// dp[i][1] = i��° �츮�� ���ڸ� �ִ� ��� -> ���� ��� ���ϱ�
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	cout << (dp[n][0] + dp[n][1] * 2) % 9901 << endl;

	return 0;
}