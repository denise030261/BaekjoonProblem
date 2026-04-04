#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int m, d;
	cin >> m >> d;

	if (m < 2)
	{
		cout << "Before";
	}
	else if (m == 2)
	{
		if (d < 18)
		{
			cout << "Before";
		}
		else if (d == 18)
		{
			cout << "Special";
		}
		else
		{
			cout << "After";
		}
	}
	else
	{
		cout << "After";
	}
}