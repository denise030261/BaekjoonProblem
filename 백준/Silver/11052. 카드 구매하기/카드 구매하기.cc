#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int arr[1001];
	int cost[1001] = { 0, };

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	cost[1] = arr[1];
	for (int i = 2; i <= N; i++)
	{
		cost[i] = max(cost[i], arr[i]);
		for (int j = 1; j <= i; j++)
		{
			cost[i] = max(arr[j] + cost[i - j], cost[i]);
		}
	}

	cout << cost[N];
}