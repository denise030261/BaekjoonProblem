#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int arr[100] = { 0, };
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		for (int j = 0; j <= (end-start) / 2; j++)
		{
			int temp = arr[start+j];
			arr[start + j] = arr[end - j];
			arr[end - j] = temp;
		}

	}

	for (int i = 1; i <= N; i++)
	{
		cout << arr[i] << ' ';
	}
}