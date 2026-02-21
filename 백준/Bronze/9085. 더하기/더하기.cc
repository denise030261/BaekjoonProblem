#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

	while (T != 0)
	{
		int N;
		cin >> N;
		int sum = 0;

		if (N > 10)
		{
			continue;
		}

		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			sum += num;
		}
		cout << sum << '\n';

		T--;
	}
}