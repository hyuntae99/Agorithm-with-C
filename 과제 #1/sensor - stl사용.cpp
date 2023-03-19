#include <stdio.h>
#include <algorithm> // sort 함수 사용 
#include <math.h> // pow 함수 사용 
#include <vector> // 벡터 함수 사용 
#include<iostream> // cout, cin 사용

int main(void)
{
	int d, r, n; // d = 강폭, r = 통신반경, n = 센서의 개수
	scanf_s("%d %d %d", &d, &r, &n);

	// 범위가 커서 벡터 사용
	std::vector <int> North; // 북쪽 센서
	std::vector <int> South; // 남쪽 센서

	// 한줄씩 받기
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf_s("%d", &a);
		North.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf_s("%d", &a);
		South.push_back(a);
	}

	// 오름차순 정렬
	sort(North.begin(), North.end());

	// deadline > x좌표 차이 -> 통신X
	int deadline = int(pow(pow(r, 2) - pow(d, 2),0.5)); 

	// 정답 
	std::vector <int> answer;

	// 탐색 코드
	for (int i = 0; i < n; i++)
	{
		int left = South[i] - deadline; // 최솟값
		int right = South[i] + deadline; // 최댓값

		// 최솟값 이상인 첫번째 인덱스 ==> 최솟값의 시작 인덱스
		int lower = std::lower_bound(North.begin(), North.end(), left) - North.begin(); 
		// 최댓값 초과하는 첫번째 인덱스 ==> 최댓값의 마지막 인덱스
		int upper = std::upper_bound(North.begin(), North.end(), right) - North.begin();

		// 최솟값과 최댓값 사이의 인덱스의 개수 저장
		answer.push_back(upper - lower);
	}

	// 정답 오름차순 정리
	sort(answer.begin(), answer.end()); 

	// 정답 출력
	for (int i = 0; i < answer.size(); i++)
		std::cout << answer[i] << " ";

	return 0;
}
