#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int result = -10000;
	int total = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		total += num;

		if (num > total)
			total = num;

		if (total > result)
			result = total;
	}
	cout << result;
}