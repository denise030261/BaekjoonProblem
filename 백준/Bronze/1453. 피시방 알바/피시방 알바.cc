#include <iostream>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bool arr[101] = { 0, };
	int N;
	cin >> N;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (arr[num])
		{
			answer++;
		}
		else
		{
			arr[num] = true;
		}
	}

	cout << answer;
}