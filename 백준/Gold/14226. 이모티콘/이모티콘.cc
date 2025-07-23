#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

bool visited[10001][1001] = {0,};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int S;
	cin >> S;

	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -0,{1,0} }); // 시간, 현재 숫자, 클립보드
	int answer = 0;
	while (!pq.empty())
	{
		int time = -pq.top().first;
		int cur = pq.top().second.first;
		int clip = pq.top().second.second;
		pq.pop();

		if (cur == S)
		{
			answer = time;
			break;
		}

		if (!visited[clip][cur])
		{
			visited[clip][cur] = true;

			time++;
			pq.push({ -time, {cur,cur} });

			if(clip!=0)
				pq.push({ -time, {cur+ clip,clip} });
			
			if(cur>1)
				pq.push({ -time, {cur-1,clip} });
		}
	}

	cout << answer;
}