#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> arr;
vector<int> v;
bool visited[8] = { 0, };
int answer = INT_MIN;

void dfs(int length)
{
	if (length == N)
	{
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
		{
			sum += abs(v[i] - v[i + 1]);
		}
		/*if (answer < sum)
		{
			for (int i = 0; i < N; i++)
			{
				cout << v[i] << ' ';
			}
			cout << '\n';
		}*/
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		//cout << 1;
		if (!visited[i])
		{
			//cout << 2;
			visited[i] = true;
			v.push_back(arr[i]);
			dfs(v.size());
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	dfs(0);

	cout << answer;
}