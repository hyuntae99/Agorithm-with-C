#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �Լ� ���� 
long long Start_Search();
long long Reverse_Search();

int n;
vector<int> blocks;
// �Լ��� ���鼭 �ݺ�Ƚ���� ������ �� Ƚ��
long long total_count = 0;

// ���� �Լ�
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		blocks.push_back(a);
	}

	// �Լ� ���� �� ���.
	cout << Start_Search() << endl;

	return 0;
}

// ������ Ž�� �Լ�
long long Start_Search()
{
	for (int i = 0; i < n - 2; i++)
		// i��° �� < i+1��° ���϶�
		if (blocks[i] < blocks[i + 1])
		{
			// i+1��° ���� i��° ���� �ǵ��� �ϴ� ��
			int gap = blocks[i + 1] - blocks[i];
			// i+2��° �� - gap >= 0 �� ���
			if (gap <= blocks[i + 2])
			{
				// gap�� total_count�� ������.
				total_count += gap;
				// �� ���� i+1��°, i+2��° ���� ���ش�.
				blocks[i + 1] -= gap;
				blocks[i + 2] -= gap;
			}
			// i+2��° �� - gap < 0 �� ���
			else
			{
				// gap���� ���� i+2�� ���� ������ �Ǳ⶧���� i+2��° ���� 0�� �Ǵ� �������� ���ش�.
				total_count += blocks[i + 2];
				blocks[i + 1] -= blocks[i + 2];
				blocks[i + 2] -= blocks[i + 2];
			}
		}

	// ��ü Ž��
	for (int i = 0; i < n - 1; i++)
		// ��� ���� ���� ���� ���
		if (blocks[i] != blocks[i + 1])
		{
			// ������ Ž�� �Լ� ����
			return Reverse_Search();
			break;
		}
	// ��� ���� ���Ƽ� ���� for���� ������ ����Ǿ��ٸ� �� Ƚ�� ��ȯ.
	return total_count;
}

// ������ Ž�� �Լ� -> ������ Ž���� ���� ������� �������� ����.
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
		// ��� ���� ���� ������
		if (blocks[i] != blocks[i + 1])
		{
			// �������� �����Ѵ�� -1 ���.
			return -1;
			break;
		}
	// ��� ���� ���ٸ� �� Ƚ�� ��ȯ.
	return total_count;
}
