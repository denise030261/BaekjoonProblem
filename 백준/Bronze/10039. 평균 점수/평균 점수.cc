#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0;
	int num;
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		num = (num < 40 ? 40 : num);
		sum += num;
	}

	cout << sum / 5;
}