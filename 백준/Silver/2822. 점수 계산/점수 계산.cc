#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<pair<int,int>> v;
	int scoresum = 0;
	vector<int> answer;

	for (int i = 0; i < 8; i++)
	{
		int score;
		cin >> score;
		v.push_back(make_pair(score, i + 1));
	}
	sort(v.begin(), v.end());
	for (int i = 7; i >= 3; i--)
	{
		scoresum += v[i].first;
		answer.push_back(v[i].second);
	}
	sort(answer.begin(), answer.end());

	cout << scoresum << '\n';
	for (int i = 0; i < 5; i++)
	{
		cout << answer[i] << ' ';
	}
}