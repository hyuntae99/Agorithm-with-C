#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector<int> v; // �׷���
vector<bool> check; // dfs �Լ��� �湮����
vector<bool> visit; // dfs_for_cycle �Լ��� �湮����
vector<int> indegree; // �׷������� indegree�� ���� ����
vector<int> outdegree; // �׷������� outdegree�� ���� ����
vector<int> dp; // ����� ��

// �Լ� ����
void dfs_for_cycle(int i); 
void dfs(int i);

// ����
int answer = 0;
// n = ���� ����, m = ¤������ ����
int m, n;

int main(void) 
{
	cin >> m >> n;

	// ���� ũ�� �Ҵ�
	v.clear(), v.resize(n+1);
	check.clear(), check.resize(n+1,false);
	visit.clear(), visit.resize(n+1,false);
	indegree.clear(), indegree.resize(n+1);
	outdegree.clear(), outdegree.resize(n+1,true);
	dp.clear(), dp.resize(n+1,1);

	// �׷��� �Է� (������ ������ŭ �ݺ�)
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		// bool �迭�� ����ϹǷ� 1�� ���ؼ� 0�� ����.
		v[a+1] = b+1;
		// indegree(������ ����)�� ���� üũ��.
		indegree[b+1]++;
		// outdegree(������ ����)�� ���� ���� üũ��.
		outdegree[a+1] = false;
	}

	// ����(¤������ ���� ���)
	if (m == 0)
	{
		// ����(��)�� ���� ���
		if (n == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		// ����(��)�� ���� ���
		else
		{
			cout << 1 << endl;
			return 0;
		}
	}

	// ��� ����(��)�� ���ؼ� cycle Ž�� ����
	for (int i = 1; i <= n; i++)
	{
		// ��, �ѹ��̶� �湮����� �ִٸ� ����ó��
		if (!visit[i])
			dfs_for_cycle(i);
	}

	// answer = ����Ŭ�� �ִ� ũ��
	answer = *max_element(dp.begin()+1, dp.end());
	for (int i = 1; i <= n; i++)
		// indegree = 0 -> ���� ������ ���� + outdegree�� �����ϴ� ���
		if (indegree[i] == 0 && !outdegree[i])
			dfs(i);

	// ���� ���
	cout << answer << endl;

	return 0;
}

// ����Ŭ ã��
void dfs_for_cycle(int i)
{
	vector<int> cycle; // cycle ������ ����
	stack<int> s; // stack

	s.push(i);
	// �湮 ó��
	visit[i] = true;
	// stack�� ũ�Ⱑ ���� ������
	while (!s.empty())
	{
		// ���� ���(��) = ������ ���� ���� ����
		int cur_node = s.top();
		// ������ ���� ���� ���� ����
		s.pop();
		// ���� ���(��) ����
		int next_node = v[cur_node];

		// ���� ������ �湮�����ʾҴٸ�
		if (!visit[next_node])
		{
			// �湮 ó��
			visit[next_node] = true;
			// ���� ó��
			s.push(cur_node);
			s.push(next_node);
			// cycle�� �߰�
			cycle.push_back(cur_node);
		}
		// ���� ������ �湮�ߴٸ�
		else
		{
			// cycle�� �߰�
			cycle.push_back(cur_node);
			cycle.push_back(next_node);

			// �ߺ��Ǵ� ����
			int overlap = next_node;
			// ����Ŭ�� ũ��, ���� �ε���
			int size = 0;
			int start = 0;
			for (int i = 0; i < cycle.size(); i++)
				// �ߺ��Ǵ� ���ҿ� ���� ��
				if (cycle[i] == overlap)
				{
					// ����Ŭ�� ũ��
					size = int(cycle.size()) - (i+1);
					// ����Ŭ�� ���� �ε���
					start = i;
					break;
				}
			// ����Ŭ�� ���� ���
			if (size == 0 && start == 0)
				return;

			// ����Ŭ�� ������ ũ�⸦ �Է��ϰ�, �湮ó���� �Ѵ�.
			for (int i = start; i < cycle.size()-1; i++)
			{
				dp[cycle[i]] = size;
				check[cycle[i]] = true;
			}
			return;
		}
	}
}

// indegree = 0�� �������� �ٸ� ���������� �Ÿ�
void dfs(int i)
{
	while (1)
	{
		int next = v[i];
		// ���� ������ ����Ŭ�� ������ ��� + outdegree�� ���� ���
		if (check[next] || outdegree[next])
		{
			// ���� = "indegree = 0"�� ������ �ٷ� ������ ���� ����� �� + ����Ŭ or ������ ���� ����� ��
			answer = max(answer, dp[next] + dp[i]);
			return; // ����
		}
		
		// ���� ������ �湮����� ������
		if (dp[next] > 0)
		{
			// �̹� ��ΰ� ���� ��κ��� ������
			if (dp[next] == max(dp[i] + 1, dp[next]))
				return; // ����
			dp[next] = dp[i] + 1;
		}
		// ���� ������ ó�� �������� ��
		else
			// ���� ������ ����� �� = ���� ������ ����� ��  + 1
			dp[next] = dp[i] + 1;
		
		// ���� �ܰ�� �������� ������ ����
		i = next;
	}
}
