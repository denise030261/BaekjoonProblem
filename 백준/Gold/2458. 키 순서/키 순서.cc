#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

vector<int> Bigv[501];
vector<int> Smallv[501];
bool visited[501] = { 0, };
int Smalltotals[501] = { 0, };
int Bigtotals[501] = { 0, };

int BigDfs(int index)
{
	int count = 0;
	for (int i = 0; i < Bigv[index].size(); i++)
	{
		if (!visited[Bigv[index][i]])
		{
			visited[Bigv[index][i]] = true;
			count+= 1+BigDfs(Bigv[index][i]);
		}
	}

	return count;
}

int SmallDfs(int index)
{
	int count = 0;
	for (int i = 0; i < Smallv[index].size(); i++)
	{
		if (!visited[Smallv[index][i]])
		{
			visited[Smallv[index][i]] = true;
			count += 1 + SmallDfs(Smallv[index][i]);
		}
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Bigv[a].push_back(b);
		Smallv[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));

		visited[i] = true;
		Bigtotals[i] = BigDfs(i);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));

		visited[i] = true;
		Smalltotals[i] = SmallDfs(i);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++ )
	{
		if (Bigtotals[i] + Smalltotals[i] == N-1)
		{
			answer++;
		}
		//cout << Bigtotals[i] << ' ' << Smalltotals[i] << ' ' << '\n';
	}
	cout << answer;
}