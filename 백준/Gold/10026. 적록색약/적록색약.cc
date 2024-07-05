#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char arr[100][100];
char visit[100][100] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int num1 = 0;
int num2 = 0;

void dfs1(char node,int x,int y)
{
	visit[x][y] = 1;
	int temp_x;
	int temp_y;

	for (int i = 0; i < 4; i++)
	{
		temp_x = x + dx[i];
		temp_y = y + dy[i];
		if (!visit[temp_x][temp_y] && arr[temp_x][temp_y] == arr[x][y] &&
			(0 <= temp_x && temp_x < 100) && (0 <= temp_y && temp_y < 100))
			dfs1(arr[temp_x][temp_y], temp_x, temp_y);
	}
}

void dfs2(char node, int x, int y)
{
	visit[x][y] = 1;
	int temp_x;
	int temp_y;

	for (int i = 0; i < 4; i++)
	{
		temp_x = x + dx[i];
		temp_y = y + dy[i];
		if (!visit[temp_x][temp_y] && (0 <= temp_x && temp_x < 100) && (0 <= temp_y && temp_y < 100))
		{
			if((arr[temp_x][temp_y]=='R' || arr[temp_x][temp_y]=='G') && (arr[x][y] == 'R' || arr[x][y] == 'G'))
				dfs2(arr[temp_x][temp_y], temp_x, temp_y);
			else if(arr[temp_x][temp_y] == arr[x][y])
				dfs2(arr[temp_x][temp_y], temp_x, temp_y);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				dfs1(arr[i][j], i, j);
				num1++;
			}
		}

	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				dfs2(arr[i][j], i, j);
				num2++;
			}
		}
	cout << num1 << ' ' << num2;
}