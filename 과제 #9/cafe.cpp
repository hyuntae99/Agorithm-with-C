#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>    
using namespace std;

// n = 카페의 수, k = 방문할 카페의 수, s = 현재 위치
// 1 <= k <= n <= 1000000
// -10억 <= s <= 10억
int n, k, s;

vector<int> cafe; // 카페의 위치

// 함수 선언
int find_cafe();

int main()
{
	cin >> n >> k >> s;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cafe.push_back(a);
	}

	// 함수 실행
	cout << find_cafe() << endl;

	return 0;
}

// 정해진 개수의 카페를 모두 가는 최단거리를 구하는 함수
int find_cafe()
{
	// 카페의 위치 오름차순 정렬
	sort(cafe.begin(), cafe.end());

	// 초기 정답 ( 0 ~ k번째 카페라고 가정)
	// 첫번째 카페와 현재 위치 사이의 거리
	int dist = abs(s - cafe[0]); 
	// 만약 k번째 카페와 현재 위치 사이의 거리가 더 작다면
	if (abs(s - cafe[0]) > abs(s - cafe[k-1]))
		dist = abs(s - cafe[k-1]); // k번째 카페와 현재 위치 사이의 거리로 바꾼다.
	// (첫번째 카페부터 k번째 카페까지의 거리 + 배열과 현재 위치 사이의 최단거리)
	int answer = abs(cafe[0] - cafe[k-1]) + dist;

	// 모든 카페에 대해서 탐색 
	int new_answer = 0;
	for (int i = 1; i < n - k+1; i++)
	{
		// i ~ i+k번째 카페라고 가정
		int dist = abs(s - cafe[i]);
		if (abs(s - cafe[i]) > abs(s - cafe[i+k-1]))
			dist = abs(s - cafe[i+k-1]);
		new_answer = abs(cafe[i] - cafe[i+k-1]) + dist;

		// 새로운 정답이 더 작을 경우
		if (answer > new_answer)
			answer = new_answer;
	}
	return answer;
}
