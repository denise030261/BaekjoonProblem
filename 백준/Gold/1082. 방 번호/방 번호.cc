#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
	return a > b;
}

bool compareV(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	vector<int> price;
	vector<pair<int, int>> v; // 가격, 숫자
	string answer = "";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		price.push_back(num);
		v.push_back({ num,i });
	}
	sort(v.begin(), v.end(), compareV);
	cin >> M;

	if (price.size() == 1 || (v[0].second == 0 && v[0].first <= M && v[1].first > M))
	{
		cout << 0;
		return 0;
	}

	if (v[0].second == 0)
	{
		M -= v[1].first;
		answer += v[1].second + '0';
	}
	for (int i = 0; i < M / v[0].first; i++)
	{
		answer += v[0].second + '0';
	}
	M %= v[0].first;
	sort(answer.begin(), answer.end()); // 자리수 만들기

	int index = 0;
	for (int i = price.size()-1; i >=0; i--)
	{
		for (int j = index; j < answer.length(); j++)
		{
			if (M < price[i] - price[answer[j]-'0'] || answer[j]>i + '0')
			{
				continue;
			}

			answer[j] = i + '0';
			M -= price[i] - v[0].first;
			index++;
		}
	}
	sort(answer.begin(), answer.end(),compare);

	cout << answer;
}