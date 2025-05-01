#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<long long int> v;

	long long int sum = 0;

	v.push_back(0);
	for (int i = 1; i <= 1000; i++)
	{
		if (v.size() > 1000)
			break;
		for (int j = 1; j <= i; j++)
		{
			sum += i;
			v.push_back(sum);

			if (v.size() > 1000)
				break;
		}
	}

	int start, end;
	cin >> start >> end;
	
	cout << v[end] - v[start - 1];
}