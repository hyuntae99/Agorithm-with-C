#include <stdio.h>
#include <algorithm> // sort �Լ� ��� 
#include <math.h> // pow �Լ� ��� 
#include <vector> // ���� �Լ� ��� 
#include<iostream> // cout, cin ���

int main(void)
{
	int d, r, n; // d = ����, r = ��Źݰ�, n = ������ ����
	scanf_s("%d %d %d", &d, &r, &n);

	// ������ Ŀ�� ���� ���
	std::vector <int> North; // ���� ����
	std::vector <int> South; // ���� ����

	// ���پ� �ޱ�
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf_s("%d", &a);
		North.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf_s("%d", &a);
		South.push_back(a);
	}

	// �������� ����
	sort(North.begin(), North.end());

	// deadline > x��ǥ ���� -> ���X
	int deadline = int(pow(pow(r, 2) - pow(d, 2),0.5)); 

	// ���� 
	std::vector <int> answer;

	// Ž�� �ڵ�
	for (int i = 0; i < n; i++)
	{
		int left = South[i] - deadline; // �ּڰ�
		int right = South[i] + deadline; // �ִ�

		// �ּڰ� �̻��� ù��° �ε��� ==> �ּڰ��� ���� �ε���
		int lower = std::lower_bound(North.begin(), North.end(), left) - North.begin(); 
		// �ִ� �ʰ��ϴ� ù��° �ε��� ==> �ִ��� ������ �ε���
		int upper = std::upper_bound(North.begin(), North.end(), right) - North.begin();

		// �ּڰ��� �ִ� ������ �ε����� ���� ����
		answer.push_back(upper - lower);
	}

	// ���� �������� ����
	sort(answer.begin(), answer.end()); 

	// ���� ���
	for (int i = 0; i < answer.size(); i++)
		std::cout << answer[i] << " ";

	return 0;
}
