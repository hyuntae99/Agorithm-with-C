#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <stack>
#include <queue>
using namespace std;

// k1 = f(x), k2 = g(x)
// 1 <= k1, k2 <= 100000
int k1, k2;
// -20억 <= a <= b <= 20억
int a, b;
int answer = 0;

// mapset (x, f(x))
map <int, vector<int>> mapset;
// x좌표 벡터
vector <int> key_vec;

int main()
{
	// f(x) 입력받기
	cin >> k1;
	for (int i = 0; i < k1; i++)
	{
		int x, y;
		cin >> x >> y;
		mapset[x].push_back(y);
		key_vec.push_back(x);
	}

	// g(x) 입력받기
	cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		int x, y;
		cin >> x >> y;
		mapset[x].push_back(y);
		key_vec.push_back(x);
	}

	// 시작값, 끝값 입력받기
	cin >> a >> b;

	// x좌표 정렬 + 중복제거
	sort(key_vec.begin(), key_vec.end());
	key_vec.erase(unique(key_vec.begin(), key_vec.end()), key_vec.end());

	// x1 < x2 -> f(x1) <= f(x2)
	for (int i = 0; i < key_vec.size()-1; i++)
	{
		int cur = key_vec[i]; // f(x) 
		int next = key_vec[i+1]; // f(x+1) 
		int cur_val = *max_element(mapset[cur].begin(), mapset[cur].end());
		int next_val = *max_element(mapset[next].begin(), mapset[next].end());
		// 각 key의 첫번째 value에 최댓값 대입
		mapset[cur][0] = cur_val;
		mapset[next][0] = next_val;
		// f(x) > f(x+1)이면
		if (cur_val > next_val)
			mapset[next][0] = cur_val; // f(x) = f(x+1)
	}
	
	// 현재 위치 (x값)
	int start = a;
	while (1)
	{
		// 끝 변수
		int end = upper_bound(key_vec.begin(), key_vec.end(), start) - key_vec.begin();
		// end값이 첫 인덱스을 경우 -> val = 0이므로 통과
		if (end == 0)
		{
			start = key_vec[end];
			continue;
		}
		// start보다 큰 값이 없을 경우
		else if (end >= key_vec.size())
		{
			// 이전 계단 값 x (끝값 - 현재위치 +1)
			int pre_val = mapset[start][0] % 10007;
			answer += (((b - start + 1) % 10007) * (pre_val % 10007)) % 10007;
			break;
		}

		// 현재 위치 == 끝 변수
		if (key_vec[end] == start)
		{
			answer += (mapset[key_vec[end]][0] % 10007);
			start = key_vec[end+1];
		}
		// 현재 위치 < 끝 변수
		else
		{	
			// 이전 계단 값 x (끝 변수 - 현재위치)
			int pre_val = mapset[key_vec[end-1]][0] % 10007;
			answer += (((key_vec[end] - start) % 10007) * (pre_val % 10007)) % 10007;
			start = key_vec[end];
		}
	}

	// 정답 출력
	cout << answer % 10007 << endl;

	return 0;
}