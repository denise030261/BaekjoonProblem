#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[26][26];
int visit[26][26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, num;

void dfs(int x, int y)
{
	visit[x][y] = 1;
	num++;

	for (int i = 0; i < 4; i++)
	{
		int check_x = x + dx[i];
		int check_y = y + dy[i];

		if ((check_x >= 0 && check_x < N) && (check_y >= 0 && check_y < N)
			&& !visit[check_x][check_y] && arr[check_x][check_y] == 1)
		{
			dfs(check_x, check_y);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
			arr[i][j] = str[j] - '0';
	}

	vector<int> v;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			num = 0;
			if (arr[i][j] == 1 && !visit[i][j])
				dfs(i, j);
			if (num != 0)
				v.push_back(num);
		}

	sort(v.begin(), v.end());
	
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}