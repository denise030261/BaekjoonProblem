#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v;
	int L, N;
	cin >> N >> L;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (L >= v[i])
		{
			L++;
		}
	}

	cout << L;
}