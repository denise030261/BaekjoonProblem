#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int answer = 0;

	cin >> N;

	if (N < 10) 
	{
		cout << N;
		return 0;
	}

	for (int i = 1; i <= N; i *= 10) 
	{
		answer += N - i + 1;
	}

	cout << answer;
}