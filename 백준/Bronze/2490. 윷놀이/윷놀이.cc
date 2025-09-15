#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0;
	int T = 3;

	while (T != 0)
	{
		sum = 0;

		for (int i = 0; i < 4; i++)
		{
			int num;
			cin >> num;
			sum += num;
		}

		if (sum == 3)
		{
			cout << "A" << '\n';
		}
		else if (sum == 2)
		{
			cout << "B" << '\n';
		}
		else if (sum == 1)
		{
			cout << "C" << '\n';
		}
		else if (sum == 0)
		{
			cout << "D" << '\n';
		}
		else
		{
			cout << "E" << '\n';
		}

		T--;
	}
}