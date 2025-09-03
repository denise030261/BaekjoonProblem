#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[300000] = { 0, };
int pre_middle = -1;
vector<int> bags;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++)
	{
		int weight, value;
		cin >> weight >> value;
		v.push_back({ weight,value });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < K; i++)
	{
		int bag;
		cin >> bag;
		bags.push_back(bag);
	}
	sort(bags.begin(), bags.end());

	long long int answer = 0;
	int index = 0;
	priority_queue<int> pq;
	for (int i = 0; i < K; i++)
	{
		for (int j = index; j < N; j++)
		{
			if (bags[i] >= v[j].first)
			{
				pq.push(v[j].second);
			}
			else
			{
				index = j;
				break;
			}
		}
		if (bags[i] >= v[N - 1].first)
		{
			index = N;
		}

		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;
}