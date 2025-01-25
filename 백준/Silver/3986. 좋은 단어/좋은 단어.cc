#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		vector<int> v;
		for (int j = 0; j < str.length(); j++)
		{
			if (v.empty())
				v.push_back(str[j]);
			else if (v.back() == str[j])
				v.pop_back();
			else
				v.push_back(str[j]);
		}
		if (v.empty())
			answer++;
	}

	cout << answer;
}