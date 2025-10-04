#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int K; // 참외의 개수
	int maxHeight = 0;
	int maxWidth = 0;
	vector<pair<int, int>> v;

	cin >> K;
	for (int i = 0; i < 6; i++)
	{
		int num, dist;
		cin >> num >> dist;

		if (num == 1 || num == 2)
		{
			maxWidth = max(maxWidth, dist);
		}
		else
		{
			maxHeight = max(maxHeight, dist);
		}
		v.push_back({ num,dist });
	}

	int area = maxHeight * maxWidth;
	int partArea = 0;
	for (int i = 0; i < 6; i++)
	{
		int curA = i;
		int nextA = (i + 2) % 6;
		int curB = (i + 1) % 6;
		int nextB = (i + 3) % 6;

		if (v[curA].first == v[nextA].first && v[curB].first == v[nextB].first)
		{
			partArea = v[nextA].second * v[curB].second;
			break;
		}
	}
	cout << (area-partArea) * K;
}