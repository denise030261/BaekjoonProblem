#include <iostream>
#include <vector>

using namespace std;
vector<string> v;

void dfs(int index, int length, int num, string total)
{
	if (index > length)
	{
		v.push_back(total);
		return;
	}

	for (int i = 0; i <= num - 1; i++)
	{
		if (num >= 0 && i < num)
		{
			string str = "";
			str += (i + '0');
			dfs(index + 1, length, i, total + str);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	v.push_back("0");
	for (int i = 0; i <= 9; i++)
	{
		string str = "";
		str += (i + '0');
		v.push_back(str);
	}

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			string str = "";
			str += (j + '0');
			dfs(1, i, j, str);
		}
	}

	if (v.size() <= N)
	{
		cout << -1;
	}
	else
	{
		cout << v[N];
	}
}