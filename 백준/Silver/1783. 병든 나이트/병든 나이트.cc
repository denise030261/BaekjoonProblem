#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int answer = 0;
	cin >> N >> M;

	if (N == 1)
	{
		answer = 1;
	}
	else if (N == 2)
	{
		answer = min(4, (M - 1) / 2 + 1);
	}
	else
	{
		if (M >= 7)
		{
			answer = M - 2;
		}
		else
		{
			answer = min(4, M);
		}
	}

	cout << answer;
}