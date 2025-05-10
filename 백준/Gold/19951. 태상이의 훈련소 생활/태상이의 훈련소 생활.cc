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
	int starts[100001] = { 0, };
	int ends[100001] = { 0, };

	for (int i = 0; i < N; i++)
	{
		cin >> origin[i];
	}
	for (int i = 0; i < M; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		starts[start-1] += cost;
		ends[end-1] += cost;
	}

	int add = 0;
	for (int i = 0; i < N; i++)
	{
		if (starts[i] != 0)
		{
			add += starts[i];
		}
		origin[i] += add;
		if (ends[i] != 0)
		{
			add -= ends[i];
		}
		cout << origin[i] << ' ';
	}


}