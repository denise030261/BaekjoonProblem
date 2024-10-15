#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			return 0;
		}
		else
		{
			vector<int> v;
			for (int i = 0; i < n; i++)
			{
				int num;
				cin >> num;
				v.push_back(num);
			}
			sort(v.begin(), v.end());

			int distance = 0;
			int moveDistance = 0;
			bool isCheck = true;

			for (int i = 0; i < v.size(); i++)
			{
				moveDistance = v[i]-distance;
				if (200 >= moveDistance)
				{
					distance = v[i];
				}
				else
				{
					isCheck = false;
					break;
				}
			}

			if (200 >= (1422-distance)*2)
			{
				distance = 1422;
			}
			else
			{
				isCheck = false;
			}

			for (int i = v.size()-1; i >= 0; i--)
			{
				moveDistance = distance - v[i];
				if (200 >= distance- v[i])
				{
					distance = v[i];
				}
				else
				{
					isCheck = false;
					break;
				}
			}

			if (isCheck == false)
			{
				cout << "IMPOSSIBLE" << '\n';
			}
			else
			{
				cout << "POSSIBLE" << '\n';
			}
		}
	}
}