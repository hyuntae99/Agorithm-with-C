#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// �Լ� ����
void ready();
void print();

// ���� ���� �ִ� ������ ���ҵ��� �迭
vector <string> vec; 
// 0 < n <= 16, n�� ¦��.
int n;

int main() 
{
	cin >> n;

	ready();
	print();

	return 0;
}

// n�� ���� 0,1�� �߰��ϴ� �Լ�.
void ready()
{
	for (int i = 0; i < (n / 2); i++)
		vec.push_back(0);
	for (int i = 0; i < (n / 2); i++)
		vec.push_back(1);
}

// ���� ���� �ִ� ������ ����ϴ� �Լ�.
void print()
{
	do {
		for (int i = 0; i < vec.size(); i++) 
			cout << vec[i];		
		cout << endl;
	} while (next_permutation(vec.begin(), vec.end()));
}