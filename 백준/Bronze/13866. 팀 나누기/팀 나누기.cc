#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr;
	for (int i = 0; i < 4; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	cout << abs((arr[3] + arr[0]) - (arr[2] + arr[1]));
}