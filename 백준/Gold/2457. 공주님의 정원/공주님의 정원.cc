#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({ a * 100 + b,c * 100 + d }); // 피고 지기
    }

    sort(v.begin(), v.end());

    int answer = 0;
    int cur_end = 301;
    int index = 0;

    while (cur_end<=1130)
    {
        int late_bloom = -1;
        bool changed = false;
        for (int i = index; i < N; i++)
        {
            if (cur_end >= v[i].first)
            {
                if (v[i].second > late_bloom)
                {
                    late_bloom = v[i].second;
                    changed = true;
                }
                index = i + 1;
            }
            else
            {
                break;
            }
        }

        if (late_bloom == -1)
        {
            cout << 0;
            return 0;
        }
        else
        {
            cur_end = late_bloom;
            answer++;
        }
    }

    cout << answer;
}