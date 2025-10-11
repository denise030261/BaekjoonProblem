#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	char map[1000][1000];
	char answer[1000][1000];
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			map[i][j] = str[j];
		}
	}

	int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
	int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] >= '1' && map[i][j] <= '9')
			{
				answer[i][j] = '*';
				continue;
			}

			int num = 0;
			for (int k = 0; k < 8; k++)
			{
				int next_x = i + dx[k];
				int next_y = j + dy[k];

				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
				{
					if (map[next_x][next_y] != '.')
					{
						num += map[next_x][next_y] - '0';
					}
				}
			}
			
			if(num<10)
			{
				answer[i][j] = num + '0';
			}
			else
			{
				answer[i][j] = 'M';
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << answer[i][j];
		}
		cout << '\n';
	}
}