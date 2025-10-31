#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << "Scenario " << "#" << i + 1 << ":\n";
		if (a >= b && a >= c)
		{
			if (pow(a, 2) == pow(b, 2) + pow(c, 2))
			{
				cout << "yes";
			}
			else
			{
				cout << "no";
			}
		}
		else if (b >= c && b >= a)
		{
			if (pow(b, 2) == pow(a, 2) + pow(c, 2))
			{
				cout << "yes";
			}
			else
			{
				cout << "no";
			}
		}
		else
		{
			if (pow(c, 2) == pow(a, 2) + pow(b, 2))
			{
				cout << "yes";
			}
			else
			{
				cout << "no";
			}
		}
		cout << "\n\n";
	}
}