#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int arr[2001] = { 0, };
	bool palindrom[2001][2001] = { 0, };
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		palindrom[i][i] = true;
		if (arr[i] == arr[i - 1] && i != 1)
			palindrom[i - 1][i] = true;
	}

	for (int i = 2; i <= N - 1; i++)
	{
		for (int j = 1; i + j <= N; j++) 
		{
			if (arr[j] == arr[i + j] && palindrom[j + 1][i + j - 1] == 1)
				palindrom[j][i + j] = true;
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;

		cout << palindrom[S][E] << '\n';
	}
}