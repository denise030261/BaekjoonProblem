#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x;
	vector<int> v;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	cin >> x;

	sort(v.begin(), v.end());
	
	int start = 0;
	int end = v.size() - 1;
	int answer = 0;
	while (start < end)
	{
		if (v[start] + v[end] == x)
		{
			answer++;
			start++;
			end--;
		}
		else if (v[start] + v[end] < x)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << answer;
}