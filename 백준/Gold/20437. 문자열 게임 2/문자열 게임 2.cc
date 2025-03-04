#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

	while (T != 0)
	{
		unordered_map<char, int> game;
		vector<int> v[26];
		string W;
		int K;
		int answer3 = INT_MAX, answer4 = 0;

		cin >> W >> K;
		for (int i = 0; i < W.length(); i++)
		{
			game[W[i]]++;
			v[W[i] - 'a'].push_back(i);
			if (game[W[i]]>=K)
			{
				answer3 = min(answer3, (v[W[i] - 'a'][v[W[i] - 'a'].size() - 1] - v[W[i] - 'a'][v[W[i] - 'a'].size() - 1 - (K - 1)])+1);
				answer4 = max(answer4, (v[W[i] - 'a'][v[W[i] - 'a'].size() - 1] - v[W[i] - 'a'][v[W[i] - 'a'].size() - 1 - (K - 1)])+1);
			}
		}

		if (answer3 == INT_MAX && answer4 == 0)
			cout << -1 << '\n';
		else
			cout << answer3 << ' ' << answer4 << '\n';

		T--;
	}
}