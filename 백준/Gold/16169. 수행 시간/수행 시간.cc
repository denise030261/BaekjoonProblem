#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    int last = -1;
    cin >> n;
    vector<pair<int, int>> info[101];
    int computer[101] = { 0, };
    
    for (int i = 1; i <= n; i++)
    {
        int c, t;
        cin >> c >> t;
        info[c].push_back({ i,t });
        last = max(last, c);

        if (c == 1)
        {
            computer[i] = t;
        }
    }

    for (int i = 2; i <= last; i++)
    {
        for (int k = 0; k < info[i].size(); k++)
        {
            int cur_com = info[i][k].first;
            int cur_time = info[i][k].second;

            for (int j = 0; j < info[i - 1].size(); j++)
            {
                int prev_com = info[i - 1][j].first;
                int prev_time = info[i - 1][j].second;

                computer[cur_com] = max(computer[cur_com],
                    (int)pow(prev_com - cur_com, 2) + computer[prev_com] + cur_time);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer = max(answer, computer[i]);
    }
    cout << answer;
}