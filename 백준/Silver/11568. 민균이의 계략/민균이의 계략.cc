#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int arr[1001] = { 0, };
	int length[1001] = { 0, };
	int answer = 0;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		length[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j])
			{
				length[i] = max(length[i], length[j] + 1);
			}
		}
		answer = max(answer, length[i]);
	}

	cout << answer;
}