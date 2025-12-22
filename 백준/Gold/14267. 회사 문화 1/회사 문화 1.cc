#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    vector<int> v[100001];
    int answer[100001] = { 0, };
    vector<int> roots;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int boss;
        cin >> boss;

        if (boss != -1)
        {
            v[boss].push_back(i + 1);
        }
        else
        {
            roots.push_back(i + 1);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int num, w;
        cin >> num >> w;

        answer[num] += w;
    }

    for (int i = 0; i <roots.size(); i++)
    {
        queue<pair<int, int>> q;
        q.push({ roots[i],0});

        while (!q.empty())
        {
            int cur = q.front().first;
            int cost = q.front().second;
            q.pop();
           // cout << "----------------------------------------------------\n";
            //cout << cur << ' ' << cost << '\n';

            for (int j = 0; j < v[cur].size(); j++)
            {
                int next = v[cur][j];
                //cout << "next : " << next << ' ' << answer[next] + cost << '\n';
                answer[next] += cost;
                q.push({ next,answer[next] });
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] << ' ';
    }
}