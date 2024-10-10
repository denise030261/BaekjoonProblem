#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
bool isCheck[10] = { 0, };
vector<int> answers;
vector<int> v;

void dfs(int num)
{
	if (answers.size() == M)
	{
		for (int j = 0; j < M; j++)
		{
			cout << answers[j] << ' ';
		}

		cout << '\n';
		return;
	}

	for (int i = num; i < N; i++)
	{
		if (isCheck[i])
		{
			continue;
		}

		isCheck[i] = true;
		answers.push_back(v[i]);
		dfs(i+1);
		isCheck[i] = false;
		answers.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	int num = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());

	dfs(0);
}