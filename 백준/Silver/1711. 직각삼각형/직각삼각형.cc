#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long int distance(long long int x1, long long int y1, long long int x2, long long int y2)
{
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool judgement(long long int a, long long int b, long long int c)
{
	if (a == b + c )
		return true;
	else
		return false;
}

bool decline(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3)
{
	return (x3 - x2) * (y2 - y1) == (x2 - x1) * (y3 - y2);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<pair<int, int>> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	long long int answer = 0;
	for (int i = 0; i < N-2; i++)
	{
		for (int j = i + 1; j < N-1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if (decline(v[i].first, v[i].second, v[j].first, v[j].second, v[k].first, v[k].second))
				{
					continue;
				}

				long long int distA = distance(v[i].first, v[i].second, v[j].first, v[j].second);
				long long int distB = distance(v[i].first, v[i].second, v[k].first, v[k].second);
				long long int distC = distance(v[k].first, v[k].second, v[j].first, v[j].second);

				if (distA >= distB && distA >= distC)
				{
					answer += judgement(distA, distB, distC);
				}
				else if (distB >= distA && distB >= distC)
				{
					answer += judgement(distB, distA, distC);
				}
				else
				{
					answer += judgement(distC, distB, distA);
				}
			}
		}
	}

	cout << answer;
}
