#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int K = 0;
	cin >> K;
	while (K != 0)
	{
		int V, E;
		cin >> V >> E;
		vector<int> v[20001];
		int a, b;
		for (int i = 0; i < E; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		int group[20001] = { 0, };
		queue<pair<int, bool>> q; // bfs queue
		q.push({ a,true });
		bool answer = true;

		for (int i = 1; i <= V; i++)
		{
			if (!answer)
				break;

			if (group[i] == 0)
			{
				queue<int> q;
				group[i] = 1;
				q.push(i);

				while (!q.empty())
				{
					if (!answer)
						break;

					int cur = q.front();
					q.pop();

					for (int next : v[cur])
					{
						if (group[next] == 0)
						{
							group[next] = 3 - group[cur];
							q.push(next);
						}
						else if (group[next] == group[cur])
						{
							answer = false;
						}
					}
				}
			}
		}

		if (answer)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO\n";
		}

		K--;
	}
}