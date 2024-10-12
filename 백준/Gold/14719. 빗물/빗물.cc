#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int H, W;
	vector<int> v;
	cin >> H >> W;
	
	int num = 0;
	for (int i = 0; i < W; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	int answer = 0;
	for (int i = 1; i < W-1; i++)
	{
		int left = 0;
		int right = 0;

		for (int j = 0; j < i; j++)
		{
			left = max(left, v[j]);
		}
		for (int j = i + 1; j < W; j++)
		{
			right = max(right, v[j]);
		}

		answer += max(0,min(left, right) - v[i]);
	}

	cout << answer;
}
