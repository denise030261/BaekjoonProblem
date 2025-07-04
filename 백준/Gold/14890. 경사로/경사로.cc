#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	int arr[100][100] = { 0, };
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int count = 1;
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		bool possible = true;
		count = 1;

		for (int j = 0; j < N-1; j++)
		{
			if (abs(arr[i][j] - arr[i][j + 1]) > 1)
			{
				possible = false;
				break;
			}

			if (arr[i][j] < arr[i][j + 1])
			{
				if (count >= L)
				{
					count = 1;
				}
				else
				{
					possible = false;
					break;
				}
			}
			else if (arr[i][j] > arr[i][j + 1])
			{
				if (count >= 0)
				{
					count = -(L - 1);
				}
				else
				{
					possible = false;
					break;
				}

				if (j + 1 == N - 1 && 1 < L)
				{
					possible = false;
				}
			}
			else
			{
				count++;

				if (j + 1 == N - 1 && count < 0)
				{
					possible = false;
				}
			}
		}

		if (possible)
		{
			answer++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		bool possible = true;
		count = 1;

		for (int j = 0; j < N-1; j++)
		{
			if (abs(arr[j][i] - arr[j+1][i]) > 1)
			{
				possible = false;
				break;
			}

			if (arr[j][i] < arr[j + 1][i])
			{
				if (count >= L)
				{
					count = 1;
				}
				else
				{
					possible = false;
					break;
				}
			}
			else if (arr[j][i] > arr[j + 1][i])
			{
				if (count >= 0)
				{
					count = -(L - 1);
				}
				else
				{
					possible = false;
					break;
				}

				if (j + 1 == N - 1 && 1 < L)
				{
					possible = false;
				}
			}
			else
			{
				count++;

				if (j + 1 == N - 1 && count < 0)
				{
					possible = false;
				}
			}
		}

		if (possible)
		{
			answer++;
		}
	}

	cout << answer;
}