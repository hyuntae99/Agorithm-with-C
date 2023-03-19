#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 함수 선언
void ready();
void print();

// 같은 것이 있는 순열의 원소들의 배열
vector <string> vec; 
// 0 < n <= 16, n은 짝수.
int n;

int main() 
{
	cin >> n;

	ready();
	print();

	return 0;
}

// n에 따라서 0,1을 추가하는 함수.
void ready()
{
	for (int i = 0; i < (n / 2); i++)
		vec.push_back(0);
	for (int i = 0; i < (n / 2); i++)
		vec.push_back(1);
}

// 같은 것이 있는 순열로 출력하는 함수.
void print()
{
	do {
		for (int i = 0; i < vec.size(); i++) 
			cout << vec[i];		
		cout << endl;
	} while (next_permutation(vec.begin(), vec.end()));
}