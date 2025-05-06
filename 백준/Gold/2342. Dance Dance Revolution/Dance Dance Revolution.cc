#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[100001][5][5];
vector<int> v;

int dist(int cur, int next)
{
	if (cur == 0) return 2;
	if (cur == next) return 1;
	if (abs(cur - next) == 2) return 4;
	return 3;
}

int cal(int cur, int left, int right)
{
	if (cur == v.size()) return 0;

	if (dp[cur][left][right] != -1) 
		return dp[cur][left][right];

	int left_val = cal(cur + 1, v[cur], right) + dist(left, v[cur]);	
	int right_val = cal(cur + 1, left, v[cur]) + dist(right, v[cur]);	

	return dp[cur][left][right] = min(left_val, right_val);	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int input;
	while (true)
	{
		cin >> input;
		if (input == 0) break;
		v.push_back(input);
	}

	memset(dp, -1, sizeof(dp));
	cout << cal(0, 0, 0);
}
