#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int result = 1;
	vector<int> v;
	int dp[1000] = { 0, };
	cin >> N;
	
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		for(int j=0;j<i;j++)
		{
			if (v[i] < v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
			result = max(dp[i], result);
		}
	}

	cout << result;
}