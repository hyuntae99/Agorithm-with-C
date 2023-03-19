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

// 세 점의 x, y좌표
int X[3];
int Y[3];

// 함수 선언
void CCW();

int main()
{
	// P, A, B의 좌표 입력
	// -10000 <= x, y <= 10000
	// 모두 다른 점 
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		X[i] = x;
		Y[i] = y;
	}
	
	// 함수 실행
	CCW();

	return 0;
}

// 세 점의 방향을 알기 위한 알고리즘 CCW
// 시작점 P에서의 PA, PB의 외적으로 판단
void CCW()
{
	// PA, PB의 외적
	// PA = (X[1]-X[0], Y[1]-Y[0]), PB = (X[2]-X[0], Y[2]-Y[0])
	int PA_x_PB = ((X[1] - X[0]) * (Y[2] - Y[0])) - ((Y[1] - Y[0]) * (X[2] - X[0]));

	// 외적값이 양수 -> 반시계 = L
	if (PA_x_PB > 0)
	{
		cout << "L" << endl;
		return;
	}
	// 외적값이 음수 -> 시계 = R
	else if (PA_x_PB < 0)
	{
		cout << "R" << endl;
		return;
	}
	// 외적값 = 0 -> 평행 = C
	else
	{
		cout << "C" << endl;
		return;
	}
}