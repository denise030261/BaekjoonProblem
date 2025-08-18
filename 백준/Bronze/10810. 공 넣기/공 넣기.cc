#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, N;
	int arr[101] = { 0, };
	
	cin >> M >> N;
	for (int t = 0; t < N; t++)
	{
		int i, j, k;
		cin >> i >> j >> k;

		for (int c = i; c <= j; c++)
		{
			arr[c] = k;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cout << arr[i] << ' ';
	}
}