#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<string> v;
	cin >> N;

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			str[j] = tolower(str[j]);
		}
		v.push_back(str);
	}

	for (int i = 0; i < N; i++)
	{
		cout << v[i] << '\n';
	}
}