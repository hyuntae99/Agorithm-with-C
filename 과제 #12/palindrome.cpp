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
// �ʱ� ���ڿ�
string main_word; // 5 <= n <= 100000

// 2���� ���ڿ�
string arr[4][8]; // ���� : type-k / ���� : type-k�� ���ڿ� ����


int main()
{
	cin >> main_word;

	// �ʱⰪ ����
	arr[0][0] = main_word;

	// �ʱⰪ �Ǵ�
	int cnt = 0;
	for (int l = 0; l < (main_word.size() / 2); l++)
		// �յڰ� �ٸ��ٸ�
		if (main_word[l] != main_word[main_word.size() - (l+1)])
			cnt = 1;

	if (cnt == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	// ==================================================================================================================== //

	// k = 0,1,2,3, �� type-k�� 4�� �����ϹǷ� 4�� �ݺ�
	for (int i = 0; i < 4; i++)
	{
		int p = 0;
		// �յڿ��� ���ŵǹǷ� -> ����Ʈ�� 
		for (int j = 0; j < pow(2, i); j++)
		{
			// type-k�� ���ڿ�
			string word = arr[i][j];
			string another_word = word;

			int count = 0;
			for (int k = 0; k < (word.size() / 2); k++)
				// �յڰ� �ٸ��ٸ�
				if (word[k] != word[word.size()-(k+1)])
				{
					// k = {-1, 0, 1, 2, 3}�̹Ƿ�
					if (i < 3)
					{
						// �տ��� ����
						word.erase(word.begin() + k);
						// �ڿ��� ����
						another_word.erase(another_word.begin() + word.size() - k);

						// ������ �迭�� �Է��ϱ�.
						arr[i + 1][p] = word;
						p++;
						arr[i + 1][p] = another_word;
						p++;
					}
					count = 1;
					break;
				}

			// �յڰ� ��� ���� ���
			if (count == 0)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	// type-k�� ��� ��츦 ������ Ž���� ��� -> k�� ������ ����Ƿ� -1 ���
	cout << -1 << endl;

	return 0;
}



