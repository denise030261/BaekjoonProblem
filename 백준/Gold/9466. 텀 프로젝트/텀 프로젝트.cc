#include <iostream>
#include <cstring>

using namespace std;

int edge[100001] = { 0, };
int connect[100001] = { 0, };
int term_member = 0;

void dfs(int num, int start)
{
	if (start != 0 && edge[num] == start)
	{
		return;
	}
	else if (start != 0 && connect[edge[num]] == 1)
	{
		term_member++;
		dfs(edge[num], start);
		connect[edge[num]] = 2;
	}

	if (connect[edge[num]] == 0)
	{
		connect[edge[num]] = 1;
		dfs(edge[num], 0);
		connect[edge[num]] = 2;
	}
	else if (connect[edge[num]] == 1)
	{
		term_member++;
		dfs(edge[num], edge[num]);
		connect[edge[num]] = 2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T != 0)
	{
		int r;
		cin >> r;
		term_member = 0;
		for (int i = 1; i <= r; i++)
		{
			int end;
			cin >> end;
			edge[i] = end;
			connect[i] = 0;

			if (i == end)
			{
				connect[i] = 2;
				term_member++;
			}
		}

		for (int i = 1; i <= r; i++)
		{
			if (connect[i]==0)
			{
				connect[i] = 1;
				dfs(i, 0);
				connect[i] = 2;
			}
		}
		
		cout << r-term_member << '\n';
		T--;
	}
}