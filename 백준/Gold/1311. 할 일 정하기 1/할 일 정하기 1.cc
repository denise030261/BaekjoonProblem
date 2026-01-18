#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;
int N;
int map[20][20] = { 0, };
int dp[20][1048577] = { 0, };

int dfs(int current, int visited)
{
	if (current == N)
		return 0; 

	if (dp[current][visited] != 98765432)
		return dp[current][visited];

	for (int i = 0; i < N; i++) 
	{
		if (!(visited & (1 << i))) 
		{ 
			dp[current][visited] = min(dp[current][visited],map[current][i] + dfs(current + 1, visited | (1 << i)));
		}
	}
	return dp[current][visited];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 1048577; j++)
		{
			dp[i][j] = 98765432;
		}
	}

	cout << dfs(0, 0);
}