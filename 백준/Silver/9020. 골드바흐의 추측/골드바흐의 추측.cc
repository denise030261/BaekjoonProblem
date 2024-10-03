#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T,n;
	bool composite[10001] = { 0, };
	vector<int> v;
	cin >> T;

	for (int i = 2; i <= 10000; i++)
	{
		if (composite[i])
		{
			continue;
		}

		for (int j = 2; j * i <= 10000; j++)
		{
			composite[i * j] = true;
		}
	}

	while (T > 0)
	{
		T--;
		cin >> n;

		for (int i = n / 2; i >= 0; i--)
		{
			if (composite[i])
				continue;

			if (!composite[n - i])
			{
				cout << i << ' ' << n - i << '\n';
				break;
			}
		}
	}
}