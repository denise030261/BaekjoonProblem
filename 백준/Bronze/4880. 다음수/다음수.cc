#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}

		if (c == b + (b - a))
		{
			cout << "AP" << ' ' << c + (b - a) << '\n';
		}
		else
		{
			cout << "GP" << ' ' << c * (b / a) << '\n';
		}
	}
}