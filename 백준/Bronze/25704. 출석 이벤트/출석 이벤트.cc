#include <iostream>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, P;
	cin >> N >> P;

	int answer = P;

	if (N >= 5)
	{
		answer = min(answer, P - 500);
	}
	if (N >= 10)
	{
		answer = min(answer, P -(P/10));
	}
	if (N >= 15)
	{
		answer = min(answer, P - 2000);
	}
	if (N >= 20)
	{
		answer = min(answer, P - (P / 4));
	}

	if (answer <= 0)
	{
		cout << 0;
	}
	else
	{
		cout << answer;
	}
}