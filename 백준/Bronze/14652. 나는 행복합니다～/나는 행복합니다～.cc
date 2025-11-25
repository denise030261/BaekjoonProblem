#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (sum == K)
			{
				cout << i << ' ' << j;
				return 0;
			}
			else
			{
				sum++;
			}
		}
	}
}