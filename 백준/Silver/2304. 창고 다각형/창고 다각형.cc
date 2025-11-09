#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int arr[1001] = { 0, };
	cin >> N;
	int start = INT_MAX, end = -1;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a] = b;
		v.push_back({ a,b });
		
		start = min(start, a);
		end = max(end, a);
	}
	
	int answer = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		bool correct = true;
		int height = -1;
		for (int j = start; j < v[i].first; j++)
		{
			if (arr[j] != 0 && height < arr[j])
			{
				height = arr[j];
			}
			sum += height;
		}

		if (height > v[i].second)
		{
			correct = false;
		}

		height = -1;
		for (int j = end; j >= v[i].first+1; j--)
		{
			if (arr[j] != 0 && height < arr[j])
			{
				height = arr[j];
			}
			sum += height;
		}
		if (height > v[i].second)
		{
			correct = false;
		}

		if(correct)
		{
			answer = min(answer, sum+v[i].second);
		}
	}

	cout << answer;
}