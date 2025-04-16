#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int answer = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		answer += num;
	}

	cout << answer - (N - 1);
}