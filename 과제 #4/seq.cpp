#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �Լ� ����
int seq_vec(int MAX, int x, int y, int i);
void Data_add(int index, int sum, int x, int y);
int add(int n);
int binarySearch(int a, int x, int d);

int n;
int len; // 2���� ������ ũ��
vector <int> vec; // ����
vector <vector <int>> Map;// 2���� ���ͷ� ǥ��
vector <vector <int>> Data; // (sum,x,y)�� ǥ��
vector <int> Sum; // �������� ������ ����

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	// n x n�� ����
	Map.assign(n, vector<int>(n, 0));
	// len x 3�� ���� -> (sum, x, y)
	add(n);
	Data.assign(len, vector<int>(3, 0));
	
	int sum = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		sum += vec[i];
		Map[0][i] = sum;
		// sum, x, y ���� ����
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
				// sum, x, y ���� ����
				Data_add(index, sum, i, j);
				index++;
			}
			Sum[j] = sum;
		}

	// �κ����� �������� �������� ����
	sort(Data.begin(), Data.end(), greater<>());

	int answer = 0;
	// �ִ� �κ��պ��� ����
	for (int i = 0; i < len; i++)
	{
		// �κ��տ� ���� x,y��ǥ ����
		int MAX = Data[i][0];
		int x = Data[i][2];
		int y = Data[i][1];

		// �������� ����Ž�� �Լ�����
		if (seq_vec(MAX, x, y, i) != -1)
		{
			answer = MAX;
			break;
		}
	}
	
	// �Լ��� ������������ ���� ���� ��� 
	if (answer == 0)
		// �⺻ �������� ���� ū �� ���
		cout << *max_element(vec.begin(), vec.end()) << endl;
	else
		// ������ ã�� answer ���
		cout << answer << endl;

	return 0;
}

// 1~n������ �� -> �Լ��� ũ�⸦ �����ϱ� ����
int add(int n)
{
	if (n == 0)
		return len;
	else
		len = n + add(n-1);
}

// 2�� ���Ϳ� sum,x,y�� �ֱ�
void Data_add(int index, int sum, int x, int y)
{
	Data[index][0] = sum;
	Data[index][1] = x;
	Data[index][2] = y;
}

// �������� ����Ž�� �Լ�
int binarySearch(int a, int x, int val)
{
	int s = a+1; //����
	int e = x; //��
	int m; // �߰�
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

// �������� �������� �ش� x��ǥ�� y��ǥ�� ���� ���� �ִ��� Ȯ���ϴ� �Լ�
int seq_vec(int MAX, int x, int y, int i)
{
	for (int a = y; a < x; a++)
	{
		int val = Map[y][a];
		// ����Ž�� -> y��ǥ�� a+1 ���� x���� val�� ���� ���� �ִٸ� MAX���.
		if (binarySearch(a, x, val) != -1)
		{
			return MAX;
			break;
		}
	}
	return -1;
}
