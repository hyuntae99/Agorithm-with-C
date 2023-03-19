#include <stdio.h>
#include <vector> 
#include <iostream> 
#include <algorithm>

using namespace std;

int n, k; // n:�迭�� ũ��, k:������ ����
vector <int> P; // ���� P
vector <int> color_P; // P�� ���� ������ �� ���� 
vector <int> color_Pl; // P'�� ���� ������ �� ����
vector <int> answer; // double rainbow�ĺ��� �����ϱ� ���� ���� ����

// ������ ������ ����ϴ� �Լ�
int count_color(vector <int> arr)
{
	// ����Ž���� ���� ����
	sort(arr.begin(), arr.end());
	// color[0] = 0���� �⺻������ ������ �����Ƿ� arr.begin()+1
	if (binary_search(arr.begin()+1, arr.end(), 0))
		return 0;
	// ���� ���Ϳ� ��� ������ ���� ��� -> O
	else
		return k;
}

// double rainbow�� Ž���ϴ� �Լ�
void double_rainbow(void)
{
	// ������ ����, ������ ����
	int left = 0;
	int right = 0;

	// left, right�� n�� ���� ���� ������ �ݺ�
	while ((left < n) && (right < n))
	{
		// P'�� k���� ������ ������ ��
		if (count_color(color_Pl) == k)
		{
			// P-P'�� ������ �� -> ���� ���Ϳ� �����Ѵ�.
			if (count_color(color_P) == k)
				// �Ʒ� else������ right += 1�� color���Ϳ� �ݿ���Ų �� �����߱⶧���� (right - 1) - left + 1 => right - left
				answer.push_back(right - left);

			// P'�� ������ ���δ�. -> P'�� �������� ���� ������
			left += 1;
			color_P[P[left-1]] += 1;
			color_Pl[P[left-1]] -= 1;
		}
		// P'�� k���� ������ �������� ���� ��
		else
		{
			// P'�� ���������� Ȯ���Ѵ�.
			color_P[P[right]] -= 1;
			color_Pl[P[right]] += 1;
			right += 1;
		}
	}
	// ���� ������ ��� �������� ���� �� -> double rainbow�� ���� ���
	if (answer.size() == 0)
		// �ּڰ� ����� ���� answer�� 0�߰�.
		answer.push_back(0);
}


// ���� �Լ�
int main(void)
{
	cin >> n >> k;

	// ���� �ʱ�ȭ
	color_P.assign(k + 1, 0);
	color_Pl.assign(k + 1, 0);

	// P ���� �ޱ� + color1�� ���� �� �ޱ�
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		P.push_back(a);
		// ������ ������ �ε����� ���Ͻ��ؼ� ������ ���� ī��Ʈ�Ѵ�. -> ������ 1�����̹Ƿ� 0�� �ε����� ���¼�ġ�� �����ؾ���.
		// color������ k+1���� (0,a,b,c,d)�� ǥ���� �� ����. (a,b,c,d�� ������ ����)
		color_P[a] += 1;
	}

	// �Լ� ����
	double_rainbow();

	// answer����(���� �ĺ�)�� �ּڰ� ���
	int min = *min_element(answer.begin(), answer.end());
	cout << min << endl;

	return 0;
}