#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	vector<int> vSet;
	vector<int> vEach;

	cin >> N >> M;
	int set, each;
	for (int i = 0; i < M; i++)
	{
		cin >> set >> each;
		vSet.push_back(set);
		vEach.push_back(each);
	}

	sort(vSet.begin(), vSet.end());
	sort(vEach.begin(), vEach.end());

	int answer = 987654321;
	int circle = N / 6 + 1;
	for (int i = 0; i <= circle; i++)
	{
		if (i != circle)
			answer = min(answer, vSet[0] * i + vEach[0] * (N - 6 * i));
		else
			answer = min(answer, vSet[0] * i);
	}
	cout << answer;
}