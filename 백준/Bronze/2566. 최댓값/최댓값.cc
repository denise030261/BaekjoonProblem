#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int map[10][10] = { 0, };
	int answer = -1;
	int answer_x = 0;
	int answer_y = 0;

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> map[i][j];

			if (map[i][j] > answer)
			{
				answer = map[i][j];
				answer_x = i;
				answer_y = j;
			}
		}
	}

	cout << answer << '\n' << answer_x << ' ' << answer_y;
}