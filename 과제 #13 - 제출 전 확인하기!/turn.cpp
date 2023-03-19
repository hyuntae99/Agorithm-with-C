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

// �� ���� x, y��ǥ
int X[3];
int Y[3];

// �Լ� ����
void CCW();

int main()
{
	// P, A, B�� ��ǥ �Է�
	// -10000 <= x, y <= 10000
	// ��� �ٸ� �� 
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		X[i] = x;
		Y[i] = y;
	}
	
	// �Լ� ����
	CCW();

	return 0;
}

// �� ���� ������ �˱� ���� �˰��� CCW
// ������ P������ PA, PB�� �������� �Ǵ�
void CCW()
{
	// PA, PB�� ����
	// PA = (X[1]-X[0], Y[1]-Y[0]), PB = (X[2]-X[0], Y[2]-Y[0])
	int PA_x_PB = ((X[1] - X[0]) * (Y[2] - Y[0])) - ((Y[1] - Y[0]) * (X[2] - X[0]));

	// �������� ��� -> �ݽð� = L
	if (PA_x_PB > 0)
	{
		cout << "L" << endl;
		return;
	}
	// �������� ���� -> �ð� = R
	else if (PA_x_PB < 0)
	{
		cout << "R" << endl;
		return;
	}
	// ������ = 0 -> ���� = C
	else
	{
		cout << "C" << endl;
		return;
	}
}