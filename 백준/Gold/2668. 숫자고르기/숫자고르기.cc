#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[101] = { 0, };
vector<int> answers;
bool checkAnswers[101] = {0,};
bool visitNode[101] = { 0, };

void dfs(int front,int end, int first, vector<int> visited)
{
	if (visitNode[end] && end == first)
	{
		for (int i = 0; i < visited.size(); i++)
		{
			checkAnswers[visited[i]]=true;
			answers.push_back(visited[i]);
		}
	}
	else if ((visitNode[end] && end != first)
		|| checkAnswers[end])
	{
		return;
	}
	else 
	{
		visitNode[end] = true;
		visited.push_back(end);
		dfs(end, arr[end], first, visited);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (!checkAnswers[i])
		{
			memset(visitNode, 0, sizeof(visitNode));
			vector<int> visited;
			visited.push_back(i);
			visitNode[i] = true;
			dfs(i, arr[i], i, visited);
		}
	}

	sort(answers.begin(), answers.end());
	cout << answers.size()<<'\n';
	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i]<<'\n';
	}
}