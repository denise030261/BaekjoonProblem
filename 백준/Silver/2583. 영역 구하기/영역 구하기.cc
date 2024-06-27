#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[100][100] = { 0, };
bool visited[100][100];
int M, N;
int sum;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y)
{
	sum++;
	for (int i = 0; i < 4; i++)
	{
		int move_x = dx[i] + x;
		int move_y = dy[i] + y;
		if (move_x >= 0 && move_x < N && move_y >= 0 && move_y < M)
		{
			if (!visited[move_y][move_x] && map[move_y][move_x] == 0)
			{
				visited[move_y][move_x] = true;
				dfs(move_x, move_y);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int K;
	int answer = 0;
	vector<int> answers;
	cin >> M >> N >> K;
	
	for (int i = 0; i < K; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int p = y1; p < y2; p++)
		{
			for (int q = x1; q < x2; q++)
			{
				map[p][q] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && map[i][j] == 0)
			{
				visited[i][j] = 1;
				sum = 0;
				dfs(j, i);
				answer++;
				answers.push_back(sum);
			}
		}
	}

	cout << answer << '\n';
	sort(answers.begin(), answers.end());
	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i] << ' ';
	}
}