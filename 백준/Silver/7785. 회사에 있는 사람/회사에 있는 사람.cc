#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	map<string,bool> m;
	vector<string> v;
	cin >> n;

	string command, name;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> command;
		if (command == "enter")
		{
			m.insert(pair<string, bool>(name, true));
		}
		else
		{
			m.erase(name);
		}
	}

	for (auto const& names : m)
	{
		v.push_back(names.first);
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i] << '\n';
	}
}