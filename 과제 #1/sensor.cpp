#include <stdio.h>
#include <iostream> 
#include <algorithm> // sort�� ���� ���
#include <math.h> // pow�� ���� ���
using namespace std;

// -20000 <= x <= 20000�̹Ƿ� �迭�� ũ�� 40001
int North[40001];
// N <= 100000
int South[100000];

int sum[40001];
int answer[100000];

int main(void) 
{
	int d, r, n; // d = ������ ����, r = ���̴� �ݰ�, n = ���̴� ����
	cin >> d >> r >> n;

	// ������ ���̴� -> �迭�� �ε����� x��ǥ�� ���Ͻ� 
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		North[a + 20000] += 1;
	}

	// ������ ���̴� -> x��ǥ�� �������� ���� (-20000~20000 ==> 0~4000)
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		South[i] = a + 20000;
	}

	if (d <= r)
	{
		// ��Ÿ��������� ���Ͽ� x��ǥ�� ���ġ ���ϱ� -> d = 5, r = 7 --> int(pow(24, 0.5)) > 4 --> int => 4
		int deadline = int(pow(pow(r, 2) - pow(d, 2), 0.5)); // �ε����� �ֱ� ���ؼ� intó��

		// ������ �˰��� ��� 
		for (int i = 0; i < 40001; i++)
		{
			if (i == 0) { sum[i] = North[i]; }
			else { sum[i] = sum[i - 1] + North[i]; }
		}

		// ���� ���� ���׳��� ���� ���ϱ�
		for (int i = 0; i < n; i++)
		{
			// ���� �����
			int left = South[i] - deadline;
			int right = South[i] + deadline;

			// ������ �ε��� ������ �Ѿ�� ���
			if (right > 40000) { right = 40000; }
			if (left <= 0)
			{
				answer[i] = sum[right]; // -20000������ ������ ������ 0���� ó��.
			}
			else
			{
				answer[i] = sum[right] - sum[left - 1];
			}
		}
		sort(answer, answer + n);

		// ���� ��� (���� n��, ��ĭ n-1�� �̹Ƿ�)
		cout << answer[0];
		for (int i = 1; i < n; i++)
		{
			cout << " " << answer[i];
		}
		cout << endl;
	}
	else  // d > r�̸� ������ ���̴��� ���� �� �����Ƿ� 0�� ����ϰ� ���α׷� ����.
	{
		cout << 0;
		for (int i = 1; i < n; i++)
		{
			cout << " " << 0;
		}
		cout << endl;
	}
	return 0;
}

/* 
���ʷ��̴��� ���� �������� ���ʷ��̴� ������ ���ϴ� �����̹Ƿ�
���ʷ��̴� �迭(North)���� �ε����� x��ǥȭ �ؼ� ������ �Է¹ް�
���ʷ��̴� �迭(South)���� n���� x��ǥ�� ���� ����.(x��ǥ�� �ε����� �̿�)
���� ������ ����(d)�� ���̴��ݰ�(r)�� �̿��ؼ� ��Ÿ��������� ���� x�·ῡ ���� ����(deadline)�� ����.
�׸��� North�迭�� ���� ���̴� ������ ���� ������(sum)�� ���� ��, 
deadline�� �̿��� �¿� ����(left, right)�� �����Ѵ�.
������ �迭�� �̿��� sum(right) - sum(left-1)�� South�迭�� ���̴��� ���� �������� North ���̴��� ������ ����.
���� sort�� �̿��� ������������ ���� ����Ѵ�.
*/