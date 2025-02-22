#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, arrive;
	int map[1000][1000] = { 0, };
	cin >> N >> arrive;

	int start_x = N / 2;
	int start_y = N / 2;
	int arrive_x = 0;
	int arrive_y = 0;
	int sum = 1; // 숫자 위치
	int add = 1; // 기준
	int change = 0; // direction 바꾸기
	int direction = 0; // 0 : 위, 1 : 오른쪽, 2 : 아래, 3 : 왼쪽

	if (sum == arrive)
	{
		arrive_x = start_x;
		arrive_y = start_y;
	}
	map[start_y][start_x] = sum;
	sum++;
	while (sum != pow(N, 2))
	{
		if (direction == 0)
			start_y--;
		else if (direction == 1)
			start_x++;
		else if (direction == 2)
			start_y++;
		else if (direction == 3)
			start_x--;

		map[start_y][start_x] = sum;

		if (sum == arrive)
		{
			arrive_y = start_y;
			arrive_x = start_x;
		}

		sum++;
		change++;

		if (change % add == 0)
		{
			if (direction + 1 == 4)
				direction = 0;
			else
			{
				direction++;
			}
		}
		if (add * 2 == change)
		{
			add++;
			change = 0;
		}
	}
	if (pow(N, 2) == arrive)
	{
		arrive_y = 0;
		arrive_x = 0;
	}
	map[0][0] = pow(N, 2);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << arrive_y + 1 << ' ' << arrive_x + 1;
}