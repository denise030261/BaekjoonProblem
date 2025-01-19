#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num = 0;
	int answer = 0;
	int arr[5] = { 0, };

	cin >> num;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	for (int i = 0; i < 5; i++)
	{
		if (num == arr[i])
			answer++;
	}

	cout << answer;
}