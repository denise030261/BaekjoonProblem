#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	long long int T, x, y;

	cin >> T;
	while (T != 0)
	{
		cin >> x >> y;
		long long int dist = y - x;
		long double sqr = sqrt(dist);
		long long int sqrR = round(sqr);

		if (sqr <= sqrR)
		{
			cout << sqrR * 2 - 1 << '\n';
		}
		else
		{
			cout << sqrR * 2 << '\n';
		}

		T--;
	}
}