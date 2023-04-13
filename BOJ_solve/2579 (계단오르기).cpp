#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n의 최대범위
#define MAX 301

int n;
vector <int> scores;
// 2차원 배열
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

	// 초기값 설정
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][1] = scores[0];
	dp[1][2] = 0;
	dp[2][1] = dp[1][1] + scores[1];
	dp[2][2] = scores[1];

	// 점화식을 이용한 DP풀이
	for (int i = 3; i <= n; i++)
	{
		// 연속된 3칸 x 
		// 2칸으로 올라왔기때문에 1칸 더 올라갈 수 있음.
		dp[i][1] = dp[i-1][2] + scores[i-1];
		// 2칸을 올라갈 것이기 때문에 1칸으로 올라왔든 2칸으로 올라왔든 상관x
		// 단 최댓값만 구하면 되기에 두 케이스를 모두 비교해서 최댓값만 저장한다.
		dp[i][2] = max(dp[i - 2][1] + scores[i-1], dp[i - 2][2] + scores[i-1]);
	}

	// 정답 출력
	cout << max(dp[n][1], dp[n][2]) << endl;

	return 0;
}
