#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    bool visited[200001] = { 0, };
    int answer = INT_MAX;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0,N });

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        //cout << cost << ' ' << current << '\n';

        if (current == K)
        {
            cout << cost;
            break;
        }

        if (visited[current])
        {
            continue;
        }

        visited[current] = true;

        if (current < K)
        {
            pq.push({ -(cost + 1),current + 1 });
            pq.push({ -cost,current * 2 });
        }
        if(current-1>=0)
        {
            pq.push({ -(cost + 1),current - 1 });
        }
    }
}