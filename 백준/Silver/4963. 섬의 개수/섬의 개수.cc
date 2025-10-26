#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int answer = 0;
int a = 0;
int b = 0;
int space[50][50] = { 0, };
int visited[50][50] = { 0, };

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { 0,1,-1,1,-1,0,1,-1 };

void dfs(int x, int y)
{
	for (int i = 0; i < 8; i++)
		if (x + dx[i] >= 0 && y + dy[i] >= 0 && y + dy[i] < b && x + dx[i] < a)
			if (visited[y + dy[i]][x + dx[i]] == 0 && space[y + dy[i]][x + dx[i]] == 1)
			{
				visited[y + dy[i]][x + dx[i]] = 1;
				dfs(x + dx[i], y + dy[i]);
			}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		else
		{
			for (int i = 0; i < b; i++)
				for (int j = 0; j < a; j++)
				{
					cin >> space[i][j];
				}

			for (int i = 0; i < b; i++)
				for (int j = 0; j < a; j++)
				{
					if (visited[i][j] == 0 && space[i][j] == 1)
					{
						visited[i][j] = 1;
						dfs(j, i);
						answer++;
					}
				}
		}
		cout << answer << '\n';
		answer = 0;
		memset(visited, 0, sizeof(visited));
	}
}