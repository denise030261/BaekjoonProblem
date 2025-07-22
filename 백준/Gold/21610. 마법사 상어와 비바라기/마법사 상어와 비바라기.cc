#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	vector<pair<int, int>> v; // 방향, 움직임 양
	vector<pair<int,int>> cloud; // 현재 구름
	int map[51][51] = { 0, };
	bool curCloud[51][51] = { 0, };

	int dx[9] = {0, -1,-1,0,1,1,1,0,-1 };
	int dy[9] = {0,0,-1,-1,-1,0,1,1,1 };
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int dir, move;
		cin >> dir >> move;
		v.push_back({dir,move});
	}

	cloud.push_back({ N,1 });
	cloud.push_back({ N,2 });
	cloud.push_back({ N - 1,1 });
	cloud.push_back({ N - 1,2 });

	for (int i = 0; i < M; i++)
	{
		int dir = v[i].first;
		int move = v[i].second;
	
		for (int j = 0; j < cloud.size(); j++)
		{
			int col = cloud[j].first + dy[dir] * move;
			if (col <= 0)
			{
				while(col<=0)
					col += N;
			}
			else if (col > N)
			{
				while (col > N)
					col -= N;
			}

			int row = cloud[j].second + dx[dir] * move; // 넘어갈 수 있으니 처리해야함
			if (row <= 0)
			{
				while (row <= 0)
					row += N;
			}
			else if (row > N)
			{
				while (row > N)
					row -= N;
			}

			curCloud[col][row] = true;

			cloud[j] = { col,row };
			map[col][row]++;
		}

		for (int j = 0; j < cloud.size(); j++)
		{
			for (int k = 2; k <= 8; k += 2)
			{
				int diagonal_col = cloud[j].first + dy[k]; // 넘어갈 수 있으니 처리해야함
				if (diagonal_col <= 0 || diagonal_col > N)
				{
					continue;
				}

				int diagonal_row = cloud[j].second + dx[k]; // 넘어갈 수 있으니 처리해야함
				if (diagonal_row <= 0 || diagonal_row > N)
				{
					continue;
				}

				if (map[diagonal_col][diagonal_row] > 0)
				{
					map[cloud[j].first][cloud[j].second]++;
				}
			}
		}

		cloud.clear();
		for (int p = 1; p <= N; p++)
		{
			for (int q = 1; q <= N; q++)
			{
				if (map[p][q] >= 2 && !curCloud[p][q])
				{
					cloud.push_back({ p,q });
					map[p][q] -= 2;
				}
				else if (curCloud[p][q])
				{
					curCloud[p][q] = false;
				}
			}
		}
	}

	int answer = 0;
	for (int p = 1; p <= N; p++)
	{
		for (int q = 1; q <= N; q++)
		{
			answer += map[p][q];
		}
	}

	cout << answer;
}