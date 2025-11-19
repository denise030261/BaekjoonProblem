#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int road[101];
int num[101];
queue<int> q;

void bfs(int node)
{
	q.push(node);
	num[node] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int temp = x + i;
			if (temp > 100)
				continue;
			if (road[temp] != 0)
			{
				temp = road[temp];
			}
			if (num[temp] == -1)
			{
				num[temp] = num[x] + 1;
				q.push(temp);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N+M; i++)
	{
		int element1, element2;
		cin >> element1 >> element2;
		road[element1] = element2;
	}

	memset(num, -1, sizeof(num));
	bfs(1);
	cout << num[100];
}