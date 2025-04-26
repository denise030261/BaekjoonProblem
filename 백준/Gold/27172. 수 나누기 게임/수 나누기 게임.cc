#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int answer[1000001] = { 0, };
	int isNum[1000001] = { 0, };
	vector<int> v;

	cin >> N;
	int num;
	int high = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		high = max(high, num);
		v.push_back(num);
		isNum[num] = true;
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 2; j*v[i] <= high; j++)
		{
			if (isNum[j * v[i]])
			{
				answer[v[i]]++;
				answer[j * v[i]]--;
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << answer[v[i]] << ' ';
	}
}