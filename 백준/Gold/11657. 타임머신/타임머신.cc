#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    vector<pair<pair<int, int>, int>> v;
    long int node[501] = { 0, };
    cin >> N >> M;

    for (int i = 0; i <= 500; i++)
    {
        node[i] = INT_MAX;
    }

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        v.push_back({ {A,B},C });
    }

    node[1] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int from = v[j].first.first;
            int to = v[j].first.second;
            int cost = v[j].second;
            
            if (node[from] != INT_MAX && node[from] + cost < node[to])
            {
                node[to] = node[from] + cost;
            }
        }
    }

    bool bminus = false;
    for (int i = 0; i < M; ++i)
    {
        int from = v[i].first.first;
        int to = v[i].first.second;
        int weight = v[i].second;

        if (node[from] != INT_MAX && node[from] + weight < node[to])
        {
            bminus = true;
        }
    }

    if (bminus)
    {
        cout << -1;
    }
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (node[i] == INT_MAX)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << node[i] << '\n';
            }
        }
    }
}