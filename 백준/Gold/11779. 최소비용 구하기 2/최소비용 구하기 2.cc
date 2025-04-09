#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, start, end;
    vector<pair<int, int>> v[1001];
    pair<int, vector<int>> answer[1001];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost;
        v[node1].push_back({ node2,cost });
    }
    cin >> start >> end;
    for (int i = 1; i <= 1000; i++)
    {
        vector<int> initV;
        answer[i] = { INT_MAX,initV };
    }

    priority_queue<pair<int, vector<int>>> pq;
    vector<int> startV;
    startV.push_back(start);
    pq.push({ -0,startV });
    int answer_cost = INT_MAX;

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        vector<int> locV = pq.top().second;
        int loc = locV[locV.size() - 1];
        if (loc == end)
            break;
        pq.pop();
        for (int i = 0; i < v[loc].size(); i++)
        {
            int next_loc = v[loc][i].first;
            int next_cost = v[loc][i].second + cost;
            if (answer[next_loc].first > next_cost)
            {
                locV.push_back(next_loc);
                answer[next_loc]= { next_cost, locV };
                pq.push({ -next_cost, locV });
                locV.pop_back();
                
            }
        }
    }

    cout << answer[end].first << '\n';
    cout << answer[end].second.size() << '\n';
    for (int i = 0; i < answer[end].second.size(); i++)
    {
        cout << answer[end].second[i] << ' ';
    }
}
