#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int arr[201];
	int length[201];
	int standard = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		length[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				length[i] = max(length[i], length[j] + 1);
				standard = max(standard, length[i]);
			}
		}
	}

	cout << N - standard;
}