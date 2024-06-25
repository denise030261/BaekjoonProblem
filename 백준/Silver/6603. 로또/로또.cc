#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<int> v;
int arr[13];
bool visited[13];

void dfs(int length, int current)
{
	if (length == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = current; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			v.push_back(arr[i]);
			dfs(length + 1, i);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1)
	{
		cin >> N;

		if (N == 0)
		{
			break;
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				cin >> arr[i];
			}
			dfs(0, 0);
		}
		cout << '\n';
	}
}