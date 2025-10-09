#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, K; // N은 알고 있는 각도, K는 맞출 수 있는지의 각도
vector<int> v;
set<int> s;
bool visited[4000] = { 0, };

void dfs(int index, int sum)
{
	if (index >= N)
	{
		return;
	}

	for (int i = index; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			if(sum+v[i]!=0)
				s.insert(sum + v[i]);
			if (abs(sum - v[i]) != 0)
				s.insert(abs(sum - v[i]));
			dfs(index + 1, sum + v[i]);
			dfs(index + 1, abs(sum - v[i]));
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	dfs(0, 0);

	for (int i = 0; i < K; i++)
	{
		int angle;
		cin >> angle;

		bool correct = false;
		for (int j = 0; j <= 360; j++)
		{
			for (auto it = s.begin(); it != s.end(); it++)
			{
				//cout << ((360 * j) + angle) % (*it) << '\n'
				if (((360 * j) + angle) % (*it) == 0)
				{
					correct = true;
					break;
				}
			}
		}

		if (correct)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}