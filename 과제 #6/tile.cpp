#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
// n의 최대범위
#define MAX 1000001

// 함수 선언
void print_tile();

// 0 < n <= 1000000
int n;

// 2차원 배열
int dp[MAX][3] = {0, };

// 3차원 배열 -> 2차원 배열에는 개수만 들어가기 때문에 3차원배열에 문자열을 입력받음.
string dp_tile[31][3][585] = {"0", };

int main()
{
	cin >> n;

	// 초기값 설정
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;

	if (n <= 30)
	{
		// 문자열을 위한 초기값 설정
		dp_tile[1][1][0] = "|";
		dp_tile[2][1][0] = "||";
		dp_tile[2][2][0] = "==";
		dp_tile[3][1][0] = "==|";
		dp_tile[3][2][0] = "|==";
	}

	// 점화식을 이용한 DP풀이
	for (int i = 3; i <= n; i++)
	{
		// "|"가 오려면 전에 "="가 오던가 "= |"가 와야함.
		dp[i][1] = (dp[i - 1][2] + dp[i - 2][2]) % 20201212;
		// "="가 오려면 2칸전에 "|"가 와야함.
		dp[i][2] = dp[i - 2][1] % 20201212;

		// n이 30이하 일 경우, 타일을 출력해야하므로 string벡터에 따로 처리
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

	// 정답 출력
	cout << (dp[n][1] + dp[n][2]) % 20201212 << endl;

	// n이 30이하 일 경우, 타일 출력
	if (n <= 30)
		print_tile();

	return 0;
}

// 타일 출력 함수
void print_tile()
{
	// 두 벡터 합치기
	vector <string> DP1 (begin(dp_tile[n][1]), end(dp_tile[n][1]));
	vector <string> DP2 (begin(dp_tile[n][2]), end(dp_tile[n][2]));
	DP1.insert(DP1.end(), DP2.begin(), DP2.end());

	// 문자열을 기준을 오름차순으로 
	sort(DP1.begin(), DP1.end());
	
	// 공백 제거
	DP1.erase(unique(DP1.begin(), DP1.end()), DP1.end());

	// 타일 문양 출력
	for (int i = 1; i < DP1.size(); i++)
		cout << DP1[i] << endl;

	return;
}