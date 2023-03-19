#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 함수 선언
int seq_vec(int MAX, int x, int y, int i);
void Data_add(int index, int sum, int x, int y);
int add(int n);
int binarySearch(int a, int x, int d);

int n;
int len; // 2차원 벡터의 크기
vector <int> vec; // 수열
vector <vector <int>> Map;// 2차원 벡터로 표현
vector <vector <int>> Data; // (sum,x,y)로 표현
vector <int> Sum; // 구간합을 저장할 벡터

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	// n x n의 벡터
	Map.assign(n, vector<int>(n, 0));
	// len x 3의 벡터 -> (sum, x, y)
	add(n);
	Data.assign(len, vector<int>(3, 0));
	
	int sum = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		sum += vec[i];
		Map[0][i] = sum;
		// sum, x, y 값을 저장
		Data_add(index, sum, 0, i);
		index++;
		Sum.push_back(sum);
	}

	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			sum = Sum[j] - vec[i-1];
			if (sum > 0)
			{
				Map[i][j] = sum;
				// sum, x, y 값을 저장
				Data_add(index, sum, i, j);
				index++;
			}
			Sum[j] = sum;
		}

	// 부분합을 기준으로 내림차순 정리
	sort(Data.begin(), Data.end(), greater<>());

	int answer = 0;
	// 최대 부분합부터 시작
	for (int i = 0; i < len; i++)
	{
		// 부분합에 대한 x,y좌표 설정
		int MAX = Data[i][0];
		int x = Data[i][2];
		int y = Data[i][1];

		// 내림차순 이진탐색 함수실행
		if (seq_vec(MAX, x, y, i) != -1)
		{
			answer = MAX;
			break;
		}
	}
	
	// 함수를 실행했음에도 답이 없을 경우 
	if (answer == 0)
		// 기본 수열에서 가장 큰 값 출력
		cout << *max_element(vec.begin(), vec.end()) << endl;
	else
		// 위에서 찾은 answer 출력
		cout << answer << endl;

	return 0;
}

// 1~n까지의 합 -> 함수의 크기를 설정하기 위해
int add(int n)
{
	if (n == 0)
		return len;
	else
		len = n + add(n-1);
}

// 2차 벡터에 sum,x,y값 넣기
void Data_add(int index, int sum, int x, int y)
{
	Data[index][0] = sum;
	Data[index][1] = x;
	Data[index][2] = y;
}

// 내림차순 이진탐색 함수
int binarySearch(int a, int x, int val)
{
	int s = a+1; //시작
	int e = x; //끝
	int m; // 중간
	while (s <= e) {
		m = (s + e) / 2;
		if (Map[m][x] == val) 
			return m;
		else if (Map[m][x] < val)
			e = m - 1;
		else 
			s = m + 1;
	}
	return -1;
}

// 구간합을 기준으로 해당 x좌표와 y좌표의 같은 값이 있는지 확인하는 함수
int seq_vec(int MAX, int x, int y, int i)
{
	for (int a = y; a < x; a++)
	{
		int val = Map[y][a];
		// 이진탐색 -> y좌표는 a+1 부터 x까지 val과 같은 값이 있다면 MAX출력.
		if (binarySearch(a, x, val) != -1)
		{
			return MAX;
			break;
		}
	}
	return -1;
}
