#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n의 최대범위
#define MAX 10001

int n;
vector <int> scores;
// 2차원 배열
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

	// 초기값 설정
	dp[1][1] = scores[0];
	dp[1][2] = 0;
	dp[1][3] = 0;
	dp[2][1] = dp[1][1] + scores[1];
	dp[2][2] = scores[1];
	dp[2][3] = 0;
	dp[3][3] = scores[2];

	// 점화식을 이용한 DP풀이
	for (int i = 3; i <= n; i++)
	{
		// 연속 3잔을 불가능.
		// 이번 잔을 마시는 경우 -> dp[][1]의 경우는 계속 마셔왔으므로 연속될 수 있음.
		dp[i][1] = max(dp[i - 1][2] + scores[i - 1], dp[i - 1][3] + scores[i - 1]);
		// i-1번 잔을 마시지 않는 경우 -> 모든 경우 가능 -> 최댓값을 저장
		dp[i][2] = *max_element(dp[i - 2], dp[i - 2] + 3) + scores[i - 1];
		//i-2, i-1번 잔을 마시지 않는 경우 -> 모든 경우 가능 -> 최댓값을 저장
		dp[i][3] = *max_element(dp[i - 3], dp[i - 3]+3) + scores[i-1];
	}

	// 정답 출력
	// 마지막을 안마실 경우까지 비교! (dp[n-1]와 dp[n]을 비교)
	cout << max(* max_element(dp[n],dp[n]+3), *max_element(dp[n - 1],dp[n-1]+3)) << endl;

	return 0;
}
