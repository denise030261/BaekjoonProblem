#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int sum = 0;
	while (1)
	{
		int num;
		cin >> num;

		if (num == -1)
		{
			cout << sum;
			return 0;
		}
		else
		{
			sum += num;
		}
	}
}