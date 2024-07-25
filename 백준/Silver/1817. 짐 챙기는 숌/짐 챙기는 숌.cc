#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int index = 0;
	vector<int> v;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (v.empty())
		{
			v.push_back(num);
		}
		else if (v[index]+num <= M)
		{
			v[index] += num;
		}
		else
		{
			index++;
			v.push_back(num);
		}
	}

	cout << v.size();
}