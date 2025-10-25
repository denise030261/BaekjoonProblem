#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	bool arrB[100][100] = { 0, }; // a>b
	bool arrS[100][100] = { 0, }; // a<b
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arrB[a][b] = true;
		arrS[b][a] = true;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (arrB[j][i] && arrB[i][k])
				{
					//cout << arrB[i][k] << ' ' << arrB[k][j] << '\n';
					//cout << i << "가 " << j << "보다 무겁습니다 : " << k<<'\n';
					arrB[j][k]=true;
				}
				if (arrS[j][i] && arrS[i][k])
				{
					//cout << arrS[i][k] << ' ' << arrS[k][j] << '\n';
					//cout << i << "가 " << j << "보다 가볍습니다 : " << k << '\n';
					arrS[j][k] = true;
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		int numB = 0;
		int numS = 0;
		for (int j = 1; j <= N; j++)
		{
			if (arrB[i][j] > 0)
			{
				numB++;
			}
			if (arrS[i][j] > 0)
			{
				numS++;
			}
		}

		if (numB >= (N + 1) / 2 || numS >= (N + 1) / 2)
		{
			answer++;
		}
	}

	cout << answer;
}