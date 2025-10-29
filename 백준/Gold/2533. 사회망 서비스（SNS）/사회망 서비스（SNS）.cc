#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dp[1000001][2] = { 0, };
vector<int> v[1000001];
bool visited[1000001] = { 0, };

void dfs(int current)
{
	dp[current][1] += 1;
	//cout << current << " : " << dp[current][0] << ' ' << dp[current][1] << '\n';
	for (int i = 0; i < v[current].size(); i++)
	{
		if (!visited[v[current][i]])
		{
			visited[v[current][i]] = true;
			//cout << current << "에서 " << v[current][i] << " 입장\n";
			dfs(v[current][i]);
			dp[current][0] += dp[v[current][i]][1];
			dp[current][1] += min(dp[v[current][i]][0], dp[v[current][i]][1]);
		}
	}

	//cout << current << " : " << dp[current][0] << ' ' << dp[current][1] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	visited[1] = true;
	dfs(1);
	cout << min(dp[1][0],dp[1][1]);
}