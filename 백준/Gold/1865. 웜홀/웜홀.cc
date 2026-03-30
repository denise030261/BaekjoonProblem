#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int TC;
    cin >> TC;

    while (TC != 0)
    {
        int N, M, W; // N은 지점 수, M은 도로 개수, W은 웜홀의 개수
        int dist[501] = { 0, };
        vector<pair<pair<int,int>, int>> v;
        cin >> N >> M >> W;
        for (int i = 0; i < M; i++)
        {
            int S, E, T; // S, E는 연결 지점 번호, T는 시간
            cin >> S >> E >> T;
            v.push_back({ {S,E},T });
            v.push_back({ {E,S},T });
        } // 도로 정보

        for (int i = 0; i < W; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            v.push_back({ {S,E},-T });
        }

        for (int i = 1; i <= N; i++)
        {
            dist[i] = INF;
        }
        dist[1] = 0;

        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                int from = v[j].first.first;
                int to = v[j].first.second;
                int cost = v[j].second;

                if (dist[to] > dist[from] + cost)
                {
                    dist[to] = dist[from] + cost;
                }
            }
        }

        bool possible = false;
        for (int j = 0; j < v.size(); j++)
        {
            int from = v[j].first.first;
            int to = v[j].first.second;
            int cost = v[j].second;

            if (dist[to] > dist[from] + cost)
            {
                possible = true;
                break;
            }
        }

        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        TC--;
    }
}