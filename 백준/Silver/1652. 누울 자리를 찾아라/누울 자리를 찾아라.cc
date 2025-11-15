#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	char map[101][101];
	cin >> N;

	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	int rowAns = 0;
	for (int i = 0; i < N; i++)
	{
		bool possible = false;
		int seat = 0;
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == '.')
			{
				seat++;
			}
			else
			{
				possible = false;
				seat = 0;
			}

			if (seat == 2 && !possible)
			{
				possible = true;
				rowAns++;
			}
		}
	}

	int calAns = 0;
	for (int i = 0; i < N; i++)
	{
		bool possible = false;
		int seat = 0;
		for (int j = 0; j < N; j++)
		{
			if (map[j][i] == '.')
			{
				seat++;
			}
			else
			{
				possible = false;
				seat = 0;
			}

			if (seat == 2 && !possible)
			{
				possible = true;
				calAns++;
			}
		}
	}

	cout << rowAns << ' ' << calAns;
}