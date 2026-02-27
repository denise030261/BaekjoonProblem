#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

void caculate(int start, vector<pair<int, int>> v[2001], int dist[2001])
{
    priority_queue<pair<int, int>> pq;
    pq.push({ -0,start });
    dist[start] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        //cout << cur << ' ' << cost << " : ";

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;

            if (dist[next] > cost + next_cost)
            {
                dist[next] = cost + next_cost;
                pq.push({ -(cost + next_cost),next });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    while (T != 0)
    {
        vector<pair<int, int>> v[2001];
        vector<int> candidates;
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            v[a].push_back({ b,d });
            v[b].push_back({ a,d });
        }
        for (int i = 0; i < t; i++)
        {
            int candidate;
            cin >> candidate;
            candidates.push_back(candidate);
        }

        int candidate1 = 0; // s->g->h->?
        int candidate2 = 0; // s->h->g->?

        int dist[2001] = { 0, };
        int start_dist[2001] = { 0, };
        for (int i = 1; i <= n; i++)
        {
            dist[i] = 987654321;
        }
        caculate(s, v, dist);
        candidate1 = dist[g]; // s->g
        candidate2 = dist[h]; // s->h
        for (int i = 1; i <= n; i++)
        {
            start_dist[i] = dist[i];
        }

        for (int i = 1; i <= n; i++)
        {
            dist[i] = 987654321;
        }
        caculate(g, v,  dist);
        candidate1 += dist[h]; // g->h
        candidate2 += dist[h]; // h->g 어처피 길이는 같음



        for (int i = 1; i <= n; i++)
        {
            dist[i] = 987654321;
        }
        caculate(h, v,  dist); // h->모든 정점

        int another_dist[2001] = { 0, };
        for (int i = 1; i <= n; i++)
        {
            another_dist[i] = 987654321;
        }
        caculate(g, v, another_dist); // g->모든 정점
        
        priority_queue<int> answers;
        for (int i = 0; i < candidates.size(); i++)
        {
            int candidate = candidates[i];
            if (start_dist[candidate] >= 
                min(candidate1 + dist[candidate], candidate2 + another_dist[candidate]))
            {
                answers.push(-candidate);
            }
        }
       
        while (!answers.empty())
        {
            cout << -answers.top() << ' ';
            answers.pop();
        }
        cout << '\n';

        T--;
    }
}