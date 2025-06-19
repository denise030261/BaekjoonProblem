#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	int answer = 0;
	cin >> T;
	for (int i = 0; i < 5; i++)
	{
		int a;
		cin >> a;
		answer += (T == a ? 1 : 0);
	}

	cout << answer;
}