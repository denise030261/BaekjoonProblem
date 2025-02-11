#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string S;
	map<string,int> m;

	cin >> S;
	for (int i = 0; i < S.length(); i++)
	{
		string str = "";
		str += S[i];
		m.insert({ str,1 });
		for (int j = i + 1; j < S.length(); j++)
		{
			str += S[j];
			m.insert({ str,1 });
		}
	}

	int answer = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		answer++;
	}

	cout << answer;
}