#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int origin[100001] = { 0, };
	int sum[100001] = { 0, };

	for (int i = 0; i < N; i++)
	{
		cin >> origin[i];
	}
	for (int i = 0; i < M; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		sum[start-1] += cost;
		sum[end] -= cost;
	}

	int add = 0;
	for (int i = 0; i < N; i++)
	{
		add += sum[i];
		cout << origin[i] + add << ' ';
	}

}