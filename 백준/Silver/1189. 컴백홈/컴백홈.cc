#include <iostream>
#include <vector>

using namespace std;

int C, R, K;
int answer = 0;
int map[5][5];
bool visited[5][5] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int col, int row, int cost)
{
	if (col == 0 && row == R - 1)
	{
		if (cost == K)
			answer++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextCol = col + dy[i];
		int nextRow = row + dx[i];
		if (nextCol >= 0 && nextCol < C && nextRow >= 0 && nextRow < R)
		{
			if (map[nextCol][nextRow] == 1 || visited[nextCol][nextRow])
				continue;

			visited[nextCol][nextRow] = true;
			dfs(nextCol, nextRow, cost+1);
			visited[nextCol][nextRow] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> C >> R >> K;
	
	string str;
	for (int i = 0; i < C; i++)
	{
		cin >> str;
		for (int j = 0; j < R; j++)
		{
			if (str[j] == 'T')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		} 
	}

	visited[C - 1][0] = true;
	dfs(C - 1, 0, 1);

	cout << answer;
}