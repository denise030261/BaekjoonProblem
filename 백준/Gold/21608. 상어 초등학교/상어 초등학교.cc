#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<int> v[401];
	vector<int> order;
	cin >> N;

	for (int i = 0; i < N*N; i++)
	{
		int num;
		cin >> num;
		order.push_back(num);
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[num].push_back(a); v[num].push_back(b); v[num].push_back(c); v[num].push_back(d);
	}

	bool placed[20][20] = { 0, };
	int map[20][20] = { 0, };
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	for (int i = 0; i < order.size(); i++)
	{
		int place = order[i];
		int maxEmpty = 0;
		int maxLike = 0;
		pair<int, int> placeMap = { 21,21 };
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				int empty = 0;
				int like = 0;
				if (placed[j][k])
					continue;

				for (int m = 0; m < 4; m++)
				{
					int side_y = j + dy[m];
					int side_x = k + dx[m];

					if (side_x >= 0 && side_x < N && side_y>=0 && side_y < N)
					{
						if(map[side_y][side_x]==0)
							empty++;
						for (int n = 0; n < 4; n++)
						{
							if (v[place][n] == map[side_y][side_x])
							{
								like++;
								break;
							}
						} // n은 현재 번호의 좋아하는 번호
					} 
				} // m은 방향

				if ((maxLike < like) || (maxEmpty < empty && maxLike == like) ||
					(placeMap.first > j && maxEmpty == empty && maxLike == like) ||
					(placeMap.second > k && placeMap.first == j && maxEmpty == empty && maxLike == like))
				{
					maxEmpty = empty;
					maxLike = like;
					placeMap = { j,k };
				}
			} // j,k는 x,y
		}
		map[placeMap.first][placeMap.second] = order[i];
		placed[placeMap.first][placeMap.second] = true;
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				int side_x = i + dx[k];
				int side_y = j + dy[k];
				if (side_x >= 0 && side_x < N && side_y>=0 && side_y < N)
				{
					for (int n = 0; n < 4; n++)
					{
						if (v[map[i][j]][n] == map[side_x][side_y])
						{
							sum++;
							break;
						}
					} // n은 현재 번호의 좋아하는 번호
				}
			}

			//cout << map[i][j] << ' ' << sum << '\n';
			if (sum == 4)
			{
				answer += 1000;
			}
			else if (sum == 3)
			{
				answer += 100;
			}
			else if (sum == 2)
			{
				answer += 10;
			}
			else if (sum == 1)
			{
				answer += 1;
			}
		}
	}

	cout << answer;
}