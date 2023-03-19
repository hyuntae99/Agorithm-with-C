#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 함수 선언 
long long Start_Search();
long long Reverse_Search();

int n;
vector<int> blocks;
// 함수를 돌면서 반복횟수를 저장할 총 횟수
long long total_count = 0;

// 메인 함수
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		blocks.push_back(a);
	}

	// 함수 실행 후 출력.
	cout << Start_Search() << endl;

	return 0;
}

// 정방향 탐색 함수
long long Start_Search()
{
	for (int i = 0; i < n - 2; i++)
		// i번째 값 < i+1번째 값일때
		if (blocks[i] < blocks[i + 1])
		{
			// i+1번째 값이 i번째 값이 되도록 하는 값
			int gap = blocks[i + 1] - blocks[i];
			// i+2번째 값 - gap >= 0 일 경우
			if (gap <= blocks[i + 2])
			{
				// gap을 total_count에 적용함.
				total_count += gap;
				// 그 값을 i+1번째, i+2번째 값에 빼준다.
				blocks[i + 1] -= gap;
				blocks[i + 2] -= gap;
			}
			// i+2번째 값 - gap < 0 일 경우
			else
			{
				// gap으로 빼면 i+2의 값이 음수가 되기때문에 i+2번째 값이 0이 되는 값까지만 빼준다.
				total_count += blocks[i + 2];
				blocks[i + 1] -= blocks[i + 2];
				blocks[i + 2] -= blocks[i + 2];
			}
		}

	// 전체 탐색
	for (int i = 0; i < n - 1; i++)
		// 모든 값이 같지 않을 경우
		if (blocks[i] != blocks[i + 1])
		{
			// 역방향 탐색 함수 실행
			return Reverse_Search();
			break;
		}
	// 모든 값이 같아서 위의 for문이 무사히 종료되었다면 총 횟수 반환.
	return total_count;
}

// 역방향 탐색 함수 -> 정방향 탐색과 같은 방법으로 역순으로 실행.
long long Reverse_Search()
{
	for (int i = n - 1; i > 1; i--)
		if (blocks[i] < blocks[i - 1])
		{
			int gap = blocks[i - 1] - blocks[i];
			if (gap <= blocks[i - 2])
			{
				total_count += gap;
				blocks[i - 1] -= gap;
				blocks[i - 2] -= gap;
			}
			else
			{
				total_count += blocks[i - 2];
				blocks[i - 1] -= blocks[i - 2];
				blocks[i - 2] -= blocks[i - 2];
			}
		}

	for (int i = 0; i < n - 1; i++)
		// 모든 값이 같지 않으면
		if (blocks[i] != blocks[i + 1])
		{
			// 문제에서 제시한대로 -1 출력.
			return -1;
			break;
		}
	// 모든 값이 같다면 총 횟수 반환.
	return total_count;
}
