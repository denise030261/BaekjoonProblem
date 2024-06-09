#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v;
	vector<int> sort_v;
	vector<int> answer;
	bool visited[1001] = { 0, };
	int N;
	int num;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		sort_v.push_back(num);
	}

	sort(sort_v.begin(), sort_v.end());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i] == sort_v[j] && !visited[j])
			{
				answer.push_back(j);
				visited[j] = true;
				break;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << ' ';
	}
}