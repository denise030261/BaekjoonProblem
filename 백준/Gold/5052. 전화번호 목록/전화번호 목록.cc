#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t != 0)
	{
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());

		bool correct = false;
		for (int i = 0; i < n - 1; i++) // 기준
		{
			string cur = v[i];
			string next = v[i + 1];
			if (cur.compare(next.substr(0, cur.length())))
			{
				correct = false;
			}
			else
			{
				correct = true;
				break;
			}
		}

		if (!correct)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		t--;
	}
}