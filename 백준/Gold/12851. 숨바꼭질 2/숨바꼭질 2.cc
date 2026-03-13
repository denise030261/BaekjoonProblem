#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    bool big = true;
    cin >> N >> K;

    if (N > K)
    {
        cout << N - K << ' ' << 1 << '\n';
        return 0;
    }

    priority_queue<pair<int,int>> pq;
    pq.push({ 0,N });

    int answer_num = INF;
    int answer_way = 0;
    int visited[200001] = { 0, };
    for (int i = 1; i <= 200000; i++)
    {
        visited[i] = INF;
    }
   
    while (!pq.empty())
    {
        int num = pq.top().second;
        int cost = -pq.top().first;
        visited[num] = cost;
        pq.pop();
        
        if (num == K)
        {
            if (cost == answer_num)
            {
                answer_way++;
            }
            else if (cost < answer_num)
            {
                answer_num = cost;
                answer_way = 1;
            }
        }
        if (cost+1 > answer_num)
        {
            continue;
        }

        if (num < K)
        {
            if(visited[num*2]>=cost+1)
            {
                pq.push({ -(cost + 1), num * 2 });
            }
            if(visited[num+1]>=cost+1)
            {
                pq.push({ -(cost + 1), num + 1 });
            }
        }
        if (visited[num - 1] >= cost + 1)
        {
            pq.push({ -(cost + 1), num - 1 });
        }
    }

    cout << answer_num << '\n' << answer_way;
}