#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int map[10][10] = { 0, };
int last_x;
int last_y;
bool clear = false;

void rowcheck(int x, int y, bool(&check)[10])
{
	for (int i = 0; i < 9; i++)
	{
		if (map[i][x] != 0)
		{
			check[map[i][x]] = true;
		}
	}
} // 세로 체크

void columncheck(int x, int y, bool(&check)[10])
{
	for (int i = 0; i < 9; i++)
	{
		if (map[y][i] != 0)
		{
			check[map[y][i]] = true;
		}
	}
} // 가로 체크

void square(int x, int y, bool(&check)[10])
{
	for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++)
	{
		for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++)
		{
			if (map[i][j] != 0)
			{
				check[map[i][j]] = true;
			}
		}
	}
} // 3x3 체크

void dfs(int x, int y)
{
	if (y == 9) 
	{
		clear = true;
		return;
	}

	if (x == 9)
	{
		dfs(0, y + 1);
		return;
	}

	if (map[y][x] == 0) 
	{
		bool check[10] = { 0 };
		square(x, y, check);
		rowcheck(x, y, check);
		columncheck(x, y, check);

		for (int k = 1; k <= 9; k++) 
		{
			if (!check[k]) 
			{
				map[y][x] = k;
				dfs(x + 1, y);

				if (clear) 
					return;

				map[y][x] = 0; 
			}
		}
	}
	else {
		// 빈칸이 아니면 다음 칸으로 이동
		dfs(x + 1, y);
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 0)
			{
				last_x = j;
				last_y = i;
			}
		}
	}

	dfs(0, 0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}