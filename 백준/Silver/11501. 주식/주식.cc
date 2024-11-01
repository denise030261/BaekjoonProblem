#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T != 0)
	{
		int N;
		long long int answer = 0;
		vector<int> prices;
		vector<pair<int, int>> v;
		bool visited[1000000] = { 0, };
		cin >> N;
		int num;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			prices.push_back(num);
			v.push_back({ num,i });
		}
		sort(v.rbegin(), v.rend());


		for (int i = 0; i < v.size(); i++)
		{
			for (int j = v[i].second - 1; j >= 0; j--)
			{
				if (!visited[j] && v[i].first > prices[j])
				{
					visited[j] = true;
					answer += v[i].first - prices[j];
				}
				else 
				{
					break;
				}
			}
		}

		cout << answer << '\n';
		T--;
	}
}