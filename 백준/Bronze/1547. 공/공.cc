#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int ball = 1;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (a == ball)
		{
			ball = b;
		}
		else if(b==ball)
		{
			ball = a;
		}
	}

	cout << ball;
}