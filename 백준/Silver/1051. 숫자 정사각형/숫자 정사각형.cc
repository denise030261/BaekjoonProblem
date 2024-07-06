#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int answer = 1;
	string str[51];
	int arr[51][51] = { 0, };

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >>str[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			arr[i][j] = str[i][j-1] - '0';		
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (arr[i][j] == arr[i][k])
				{
					int sub = k - j;
					if (0 < i + sub && N >= i + sub)
					{
						if (arr[i][j] == arr[i + sub][j] && arr[i][k]== arr[i + sub][k])
						{
							answer = max(answer, (int)pow((sub + 1), 2));
						}
					}
				}
			}
		}
	}

	cout << answer;
}