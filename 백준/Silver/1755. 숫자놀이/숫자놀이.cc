#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	map<char, string> m; 
	m['1'] = "one";
	m['2'] = "two";
	m['3'] = "three";
	m['4'] = "four";
	m['5'] = "five";
	m['6'] = "six";
	m['7'] = "seven";
	m['8'] = "eight";
	m['9'] = "nine";
	m['0'] = "zero";
	string N, M;
	cin >> N >> M;
	int numN = stoi(N);
	int numM = stoi(M);
	vector<pair<string, int>> v;
	
	for (int i = numN; i <= numM; i++)
	{
		string str = to_string(i);
		string answerStr = "";
		for (int j = 0; j < str.length(); j++)
		{
			answerStr += m[str[j]];
		}
		v.push_back({ answerStr, i });
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < numM - numN + 1; i++)
	{
		cout << v[i].second << ' ';
		if (i % 10 == 9)
		{
			cout << '\n';
		}
	}
}