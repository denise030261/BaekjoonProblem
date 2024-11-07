#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	vector<int> v;
	long long int answer = 0;
	int maxNum = 0;
	int maxOrder = 0;
	cin >> n;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
		if (maxNum < num)
		{
			maxOrder = i;
			maxNum = num;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (i == maxOrder)
			continue;

		answer += maxNum + v[i];
	}
	
	cout << answer;
}