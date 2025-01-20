#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int F, S, G, U, D;
	int dp[1000001] = { 0, };
	queue<int> q;
	cin >> F >> S >> G >> U >> D;
	fill(dp, dp + F + 1, INT_MAX);

	q.push(S);
	dp[S] = 0;
	while (!q.empty())
	{
		int floor = q.front();
		if (U + floor <= F)
		{
			if (dp[floor + U] > dp[floor] + 1)
			{
				dp[floor + U] = dp[floor] + 1;
				q.push(floor + U);
			}
		}
		if (floor - D > 0)
		{
			if (dp[floor - D] > dp[floor] + 1)
			{
				dp[floor - D] = dp[floor] + 1;
				q.push(floor - D);
			}
		}
		q.pop();
	}

	if (dp[G] == INT_MAX)
		cout << "use the stairs";
	else
		cout << dp[G];
}