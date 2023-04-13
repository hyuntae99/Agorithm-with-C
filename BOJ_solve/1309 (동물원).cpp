#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100000

int n;
// 이차원 배열
int dp[MAX][2] = { 0, };

int main()
{
	cin >> n;

	// 초기값 설정
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		// dp[i][0] = i번째 우리에 사자를 넣지 않는 경우 -> 왼쪽, 오른쪽이 있으므로 dp[i-1][1] x 2!
		dp[i][0] = (dp[i - 1][0] + (dp[i - 1][1] * 2)) % 9901;
		// dp[i][1] = i번째 우리에 사자를 넣는 경우 -> 이전 경우 더하기
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	cout << (dp[n][0] + dp[n][1] * 2) % 9901 << endl;

	return 0;
}