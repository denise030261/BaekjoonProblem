#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, L, R, X;
vector<int> v;
int answer = 0;
bool visited[20] = { 0, };

void dfs(int start, long long int sum, int minBound,int maxBound)
{
	for (int i = start; i < N; i++)
	{
		if (visited[i])
			continue;


		if (v[i] + sum >= L && v[i] + sum <= R
			&& max(maxBound, v[i]) - min(minBound, v[i]) >= X)
			answer++;

		visited[i] = true;
		dfs(i, sum + v[i], min(minBound, v[i]), max(maxBound, v[i]));
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> L >> R >> X;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	dfs(0,0,1000001, 1);

	cout << answer;
}