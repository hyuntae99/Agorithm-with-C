#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

int n, k;
vector <int> coins;
int dp[MAX] = {0,};

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		coins.push_back(a);
	}

	/*
	n = 3, k = 10, coins = [1, 2, 5]

	           j = 1 2 3 4 5 6 7 8 9 10
		i = 1 (1)  1 1 1 1 1 1 1 1 1 1
		i = 2 (2)  1 2 2 3 3 4 4 5 5 6
		i = 3 (5)  1 2 2 3 4 5 6 7 8 10
		*/

	for (int i = 0; i < n; i ++)
		for (int j = 1; j <= k; j++)
		{
			if (j == coins[i])
				dp[j] ++;
			else if (j > coins[i])
				dp[j] += dp[j - coins[i]];
		}

	cout << dp[k] << endl;

	return 0;
}
