#include <iostream>
#include <stdio.h>
using namespace std;

// A�� ũ��, B�� ũ��
int n, m;

// ���� = ����
int total_count;

// ���� A, B
int A[200000];
int B[100];

// ������ �迭 �ʱ�ȭ
int dp[200000][100];

// �Լ� ����
void func(int a, int b, int count);

int main()
{
	cin >> n >> m;

	// ���� A�� ����
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		A[i] = a;
	}

	// ���� B�� ����
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		B[i] = a;
	}

	// 2���� �迭
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			// ���� A���� B[j]�� ������Ű�� 
			if (A[i] == B[j])
				// �ε���+1�� ���� �����Ѵ�.
				dp[i][j] = i + 1;

	// �Լ� ����
	func(0, 0, total_count);

	// ���� ���
	cout << total_count % 20221022 << endl;

	return 0;
}

// ����Լ� �̿�
void func(int a, int b, int count)
{
	// ���ǿ� ���� ���
	count %= 20221022;
	total_count %= 20221022;

	// a -> n���� 
	for (int i = a; i < n; i++)
		// B[b]�� ��ġ�� ��� == ������ ���
		if (dp[i][b] != 0)
		{
			// ������ ������ ���
			if (b == m - 1)
			{
				// total_count�� �����ش�.
				count++;
				total_count = count;
			}
			// ������ ���Ұ� �ƴ϶�� ���� ����, ���� �ε����� �Ѿ��.
			else
				func(i + 1, b + 1, total_count);
		}
}