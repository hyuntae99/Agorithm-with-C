#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n�� �ִ����
#define MAX 10001

int n;
vector <int> scores;
// 2���� �迭
int dp[MAX][4] = { {0,0,0,0}, };

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		scores.push_back(a);
	}

	// �ʱⰪ ����
	dp[1][1] = scores[0];
	dp[1][2] = 0;
	dp[1][3] = 0;
	dp[2][1] = dp[1][1] + scores[1];
	dp[2][2] = scores[1];
	dp[2][3] = 0;
	dp[3][3] = scores[2];

	// ��ȭ���� �̿��� DPǮ��
	for (int i = 3; i <= n; i++)
	{
		// ���� 3���� �Ұ���.
		// �̹� ���� ���ô� ��� -> dp[][1]�� ���� ��� ���ſ����Ƿ� ���ӵ� �� ����.
		dp[i][1] = max(dp[i - 1][2] + scores[i - 1], dp[i - 1][3] + scores[i - 1]);
		// i-1�� ���� ������ �ʴ� ��� -> ��� ��� ���� -> �ִ��� ����
		dp[i][2] = *max_element(dp[i - 2], dp[i - 2] + 3) + scores[i - 1];
		//i-2, i-1�� ���� ������ �ʴ� ��� -> ��� ��� ���� -> �ִ��� ����
		dp[i][3] = *max_element(dp[i - 3], dp[i - 3]+3) + scores[i-1];
	}

	// ���� ���
	// �������� �ȸ��� ������ ��! (dp[n-1]�� dp[n]�� ��)
	cout << max(* max_element(dp[n],dp[n]+3), *max_element(dp[n - 1],dp[n-1]+3)) << endl;

	return 0;
}
