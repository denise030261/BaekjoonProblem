#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<pair<int, string>> v;

	for (int i = 0; i < 7; i++)
	{
		string str;
		int num;
		cin >> str >> num;
		v.push_back({ num,str });
	}
	sort(v.begin(), v.end());

	cout << v[v.size()-1].second;
}