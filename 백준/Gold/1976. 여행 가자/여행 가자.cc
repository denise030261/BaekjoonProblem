#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root[201] = { 0, };
int arr[201][201] = {0,};
bool cal[201][201] = { 0, };

int find(int x)
{
	if (x == root[x])
		return x;
	else
		return root[x] = find(root[x]);
}

void merge(int x,int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	root[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
	{
		root[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1)
			{
				merge(i, j);
			}
		}
	}

	vector<int> v;
	for (int i = 1; i <= M; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	bool correct = true;
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (find(v[i]) != find(v[i + 1]))
		{
			correct=false;
		}
	}

	if (correct)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}