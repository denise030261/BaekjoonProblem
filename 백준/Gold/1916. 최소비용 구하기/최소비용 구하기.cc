#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
#define INF 999999999

using namespace std;

int N, M, targetStart;

vector<pair<int, int> > arr[1001]; 
int dist[1001]; 

void dijkstra(int dijStart)
{
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,dijStart });

	dist[dijStart]=0;

	while (!pq.empty())
	{
		int currentMoney = -pq.top().first; //현재 노드까지의 비용
        int currentNode = pq.top().second; // 현재 노드
        pq.pop();
        
        if(dist[currentNode]< currentMoney) // 이미 최단경로를 체크한 노드인 경우 패스
            continue;
        
        for(int i=0; i< arr[currentNode].size(); i++)
        {
            int cost = currentMoney + arr[currentNode][i].second; // 거쳐서 가는 노드의 비용을 계산
                                                  // 현재노드까지 비용 + 다음 노드 비용
            if(cost<dist[arr[currentNode][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                dist[arr[currentNode][i].first]=cost;
                pq.push(make_pair(-cost, arr[currentNode][i].first));
            }
        }
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M,targetStart,targetEnd;
	cin >> N >> M;

	int start, end, money;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> money;
		arr[start].push_back({ end,money });
	}

	fill(dist, dist + 1001, INF);

	cin >> targetStart >> targetEnd;

	dijkstra(targetStart);

	cout << dist[targetEnd];
}