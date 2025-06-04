#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T != 0)
	{
		int N, K, W;
		int cost[1001] = { 0, };
		int indegree[1001] = { 0, };
		int dp[1001] = { 0, };
		vector<int> v[1001];
		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			cin >> cost[i + 1];
		}

		for (int i = 0; i < K; i++)
		{
			int first, second;
			cin >> first >> second;
			v[first].push_back(second);
			indegree[second]++;
		}

		cin >> W;
		queue<int> q;
		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
				dp[i] = cost[i];
			}
		}
		while (!q.empty())
		{
			int current = q.front();
			q.pop();
			
			for (int i = 0; i < v[current].size(); i++)
			{
				int next = v[current][i];
				if (next > 0)
				{
					dp[next] = max(dp[next], dp[current] + cost[next]);
					if (--indegree[next] == 0)
						q.push(next);
				}
			}
		}
		
		cout << dp[W]<<'\n';
		T--;
	}
}