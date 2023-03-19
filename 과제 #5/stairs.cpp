#include <stdio.h>
#include <iostream>
using namespace std;
// n의 최대범위
#define MAX 100000

int n;
// 2차원 배열
int dp[MAX][4] = {0, };

int main()
{
	cin >> n;

	// 초기값 설정
	dp[0][1] = 1;

	// 점화식을 이용한 DP풀이
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			// 배열 인덱스 벗어나지않도록 조정.
			if ((i - j) >= 0)
			{
				if (j == 3)
					dp[i][j] = (dp[i - j][1] + dp[i - j][2]) % 1004;
				else
					dp[i][j] = (dp[i - j][1] + dp[i - j][2] + dp[i - j][3]) % 1004;
			}

	// 정답 출력
	cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1004 << endl;

	return 0;
}
