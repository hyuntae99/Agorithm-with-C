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

// 1 <= n <= 10
int n;

vector <string> dice; // �ֻ��� ���ڿ� (6��¥��)
string answer[2401]; // �ֻ����� ���� �� �ִ� ��� ��츦 �����ϴ� ���ڿ� (7x7x7x7)
vector <string> problems; // n���� ����(���ڿ�)�� �����ϴ� ���ڿ�


int main()
{
	cin >> n;

	// �ֻ��� ���ڿ� 4���� �ʱ�ȭ
	dice.clear(), dice.resize(4);

	// �ֻ��� ���ڿ� �Է�
	for (int i = 0; i < 4; i++)
	{
		string s;
		cin >> s;
		// ������ ���ҿ� 0�� �߰��ؼ� �ֻ����� �Ⱦ��� ��츦 ������.
		dice[i] = s + "0"; 
	}

	int a = 0;
	// �ֻ����� ���� �� �ִ� ��� ���
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			for (int k = 0; k < 7; k++)
				for (int l = 0; l < 7; l++)
				{
					string s1, s2, s3, s4;
					s1 = dice[0].at(i);
					s2 = dice[1].at(j);
					s3 = dice[2].at(k);
					s4 = dice[3].at(l);

					answer[a] = s1 + s2 + s3 + s4;
					a++;
				}

	// ���� ���ڿ� n���� �ʱ�ȭ
	problems.clear(), problems.resize(n);

	// ���� ���ڿ� ����
	for (int i = 0; i < n; i++)
	{
		string problem;
		cin >> problem;
		problems[i] = problem;
	}


	int no; // "NO"�� ����ص� �Ǵ��� �Ǵ�
	// n��(����)��ŭ �ݺ�
	for (int i = 0; i < n; i++)
	{
		// ��� ����� ���� ���� �湮 �Ǵ� �迭
		bool visited[2401][4] = {false, };

		// ���� ���� ���ڿ� ����
		string problem_n = problems[i];

		// ��� ��쿡 ���ؼ� ����
		for (int j = 0; j < size(answer); j++)
		{
			// ī��Ʈ ����
			int count = 0;
			// NO������ 1�� ����
			no = 1;
			// ���� ���ڿ���ŭ �ݺ�
			for (int k = 0; k < problem_n.size(); k++)
				// answer�� ��� ���ҿ� ����
				for (int l = 0; l < 4; l++)
					// �湮���� �ʾƾ� �ϰ�
					if (! visited[j][l])
						// ���� ���ڿ��� ���ҿ� ���ƾ� ��
						if (problem_n[k] == answer[j][l])
						{
							// �湮ó��
							visited[j][l] = true;
							// ī��Ʈ ����
							count++;
							// ����
							break;
						}
			// for�� ���� �� count�� ���� ���ڿ��� ���̿� ���ٸ� -> ���� ���ڿ��� answer�� ���ڿ��� ����.
			if (count == problem_n.size())
			{
				// YES ���
				cout << "YES" << endl;
				// NO���� 0���� ����
				no = 0;
				// ����
				break;
			}
		} 
		// NO������ 1�̶�� NO���
		if (no == 1)
			cout << "NO" << endl;
	}

	return 0;
}
