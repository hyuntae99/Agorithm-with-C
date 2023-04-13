#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n�� �ִ����
#define MAX 301

int n;
vector <int> scores;
// 2���� �迭
int dp[MAX][3] = { 0,};
vector <int> answer;

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
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][1] = scores[0];
	dp[1][2] = 0;
	dp[2][1] = dp[1][1] + scores[1];
	dp[2][2] = scores[1];

	// ��ȭ���� �̿��� DPǮ��
	for (int i = 3; i <= n; i++)
	{
		// ���ӵ� 3ĭ x 
		// 2ĭ���� �ö�Ա⶧���� 1ĭ �� �ö� �� ����.
		dp[i][1] = dp[i-1][2] + scores[i-1];
		// 2ĭ�� �ö� ���̱� ������ 1ĭ���� �ö�Ե� 2ĭ���� �ö�Ե� ���x
		// �� �ִ񰪸� ���ϸ� �Ǳ⿡ �� ���̽��� ��� ���ؼ� �ִ񰪸� �����Ѵ�.
		dp[i][2] = max(dp[i - 2][1] + scores[i-1], dp[i - 2][2] + scores[i-1]);
	}

	// ���� ���
	cout << max(dp[n][1], dp[n][2]) << endl;

	return 0;
}
