#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
// n�� �ִ����
#define MAX 1000001

// �Լ� ����
void print_tile();

// 0 < n <= 1000000
int n;

// 2���� �迭
int dp[MAX][3] = {0, };

// 3���� �迭 -> 2���� �迭���� ������ ���� ������ 3�����迭�� ���ڿ��� �Է¹���.
string dp_tile[31][3][585] = {"0", };

int main()
{
	cin >> n;

	// �ʱⰪ ����
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;

	if (n <= 30)
	{
		// ���ڿ��� ���� �ʱⰪ ����
		dp_tile[1][1][0] = "|";
		dp_tile[2][1][0] = "||";
		dp_tile[2][2][0] = "==";
		dp_tile[3][1][0] = "==|";
		dp_tile[3][2][0] = "|==";
	}

	// ��ȭ���� �̿��� DPǮ��
	for (int i = 3; i <= n; i++)
	{
		// "|"�� ������ ���� "="�� ������ "= |"�� �;���.
		dp[i][1] = (dp[i - 1][2] + dp[i - 2][2]) % 20201212;
		// "="�� ������ 2ĭ���� "|"�� �;���.
		dp[i][2] = dp[i - 2][1] % 20201212;

		// n�� 30���� �� ���, Ÿ���� ����ؾ��ϹǷ� string���Ϳ� ���� ó��
		if ((n <= 30) && (i > 3))
		{
			int k = 0;
			for (int j = 0; j < dp[i - 1][2]; j++)
			{
				dp_tile[i][1][k] = dp_tile[i - 1][2][j] + "|";
				k++;
			}
			for (int j = 0; j < dp[i - 2][2]; j++)
			{
				dp_tile[i][1][k] = dp_tile[i - 2][2][j] + "||";
				k++;
			}
			for (int j = 0; j < dp[i - 2][1]; j++)
				dp_tile[i][2][j] = dp_tile[i - 2][1][j] + "==";
		}
	}

	// ���� ���
	cout << (dp[n][1] + dp[n][2]) % 20201212 << endl;

	// n�� 30���� �� ���, Ÿ�� ���
	if (n <= 30)
		print_tile();

	return 0;
}

// Ÿ�� ��� �Լ�
void print_tile()
{
	// �� ���� ��ġ��
	vector <string> DP1 (begin(dp_tile[n][1]), end(dp_tile[n][1]));
	vector <string> DP2 (begin(dp_tile[n][2]), end(dp_tile[n][2]));
	DP1.insert(DP1.end(), DP2.begin(), DP2.end());

	// ���ڿ��� ������ ������������ 
	sort(DP1.begin(), DP1.end());
	
	// ���� ����
	DP1.erase(unique(DP1.begin(), DP1.end()), DP1.end());

	// Ÿ�� ���� ���
	for (int i = 1; i < DP1.size(); i++)
		cout << DP1[i] << endl;

	return;
}