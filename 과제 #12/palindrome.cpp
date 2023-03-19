#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdbool.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#include <map>
#include <stdio.h>
#include <unordered_set>
#include <set>
using namespace std;
// 초기 문자열
string main_word; // 5 <= n <= 100000

// 2차원 문자열
string arr[4][8]; // 세로 : type-k / 가로 : type-k별 문자열 저장


int main()
{
	cin >> main_word;

	// 초기값 설정
	arr[0][0] = main_word;

	// 초기값 판단
	int cnt = 0;
	for (int l = 0; l < (main_word.size() / 2); l++)
		// 앞뒤가 다르다면
		if (main_word[l] != main_word[main_word.size() - (l+1)])
			cnt = 1;

	if (cnt == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	// ==================================================================================================================== //

	// k = 0,1,2,3, 총 type-k는 4번 가능하므로 4번 반복
	for (int i = 0; i < 4; i++)
	{
		int p = 0;
		// 앞뒤에서 제거되므로 -> 이진트리 
		for (int j = 0; j < pow(2, i); j++)
		{
			// type-k별 문자열
			string word = arr[i][j];
			string another_word = word;

			int count = 0;
			for (int k = 0; k < (word.size() / 2); k++)
				// 앞뒤가 다르다면
				if (word[k] != word[word.size()-(k+1)])
				{
					// k = {-1, 0, 1, 2, 3}이므로
					if (i < 3)
					{
						// 앞에서 제거
						word.erase(word.begin() + k);
						// 뒤에서 제거
						another_word.erase(another_word.begin() + word.size() - k);

						// 이차원 배열에 입력하기.
						arr[i + 1][p] = word;
						p++;
						arr[i + 1][p] = another_word;
						p++;
					}
					count = 1;
					break;
				}

			// 앞뒤가 모두 같은 경우
			if (count == 0)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	// type-k의 모든 경우를 무사히 탐색한 경우 -> k의 범위를 벗어나므로 -1 출력
	cout << -1 << endl;

	return 0;
}



