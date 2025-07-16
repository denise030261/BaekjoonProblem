#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	vector<string> v;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < N; i++)
	{
		string str = v[i];
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
}