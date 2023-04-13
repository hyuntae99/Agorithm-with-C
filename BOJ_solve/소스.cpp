#include <iostream>
#include <stdio.h>
using namespace std;

// A의 크기, B의 크기
int n, m;

// 개수 = 정답
int total_count;

// 수열 A, B
int A[200000];
int B[100];

// 이차원 배열 초기화
int dp[200000][100];

// 함수 선언
void func(int a, int b, int count);

int main()
{
	cin >> n >> m;

	// 수열 A의 원소
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		A[i] = a;
	}

	// 수열 B의 원소
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		B[i] = a;
	}

	// 2차원 배열
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			// 수열 A에서 B[j]를 만족시키면 
			if (A[i] == B[j])
				// 인덱스+1의 값을 저장한다.
				dp[i][j] = i + 1;

	// 함수 실행
	func(0, 0, total_count);

	// 정답 출력
	cout << total_count % 20221022 << endl;

	return 0;
}

// 재귀함수 이용
void func(int a, int b, int count)
{
	// 조건에 의한 계산
	count %= 20221022;
	total_count %= 20221022;

	// a -> n까지 
	for (int i = a; i < n; i++)
		// B[b]와 일치할 경우 == 가능한 경우
		if (dp[i][b] != 0)
		{
			// 마지막 원소일 경우
			if (b == m - 1)
			{
				// total_count에 더해준다.
				count++;
				total_count = count;
			}
			// 마지막 원소가 아니라면 다음 원소, 다음 인덱스로 넘어간다.
			else
				func(i + 1, b + 1, total_count);
		}
}