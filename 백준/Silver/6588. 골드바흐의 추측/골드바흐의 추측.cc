#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bool composite[1000001] = { 0, };
	composite[0] = true, composite[1] = true;
	vector<int> v;
	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = 2; j <= 1000000; j++)
		{
			if (i * j <= 1000000)
				composite[i * j] = true;
			else
				break;
		}
	}

	for (int i = 1; i <= 1000000; i++)
	{
		if (!composite[i])
			v.push_back(i);
	}

	int num;
	while (1)
	{
		cin >> num;
		if (num == 0)
			break;

		bool correct = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (!composite[num - v[i]])
			{
				cout << num << " = " << v[i] << " + " << num - v[i] << '\n';
				correct = true;
				break;
			}
		}

		if (!correct)
		{
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
	}
}