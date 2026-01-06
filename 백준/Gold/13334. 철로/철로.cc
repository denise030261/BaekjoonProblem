#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(pair<long int, long int> a,pair<long int, long int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long int n, d;
    vector<pair<long int, long int>> v;
    cin >> n;

    for (long int i = 0; i < n; i++)
    {
        long int begin, arrive;
        cin >> begin >> arrive;

        if (begin > arrive)
        {
            swap(begin, arrive);
        }

        v.push_back({ begin,arrive });
    }
    cin >> d;

    sort(v.begin(), v.end(), compare);

    priority_queue<pair<long int, long int>> pq;
    int answer = 0;

    if (abs(v[0].first - v[0].second) <= d)
    {
        pq.push({ -v[0].first,v[0].second });
        answer = 1;
    }
    for (int i = 1; i < v.size(); i++)
    {
        if (abs(v[i].first - v[i].second) > d)
        {
            continue;
        }

        if (pq.empty())
        {
            pq.push({ -v[i].first,v[i].second });
        }
        else
        {
            if (-pq.top().first < v[i].second - d)
            {
                while (-pq.top().first < v[i].second - d)
                {
                    pq.pop();
                    
                    if (pq.empty())
                        break;
                }
            }

            pq.push({ -v[i].first,v[i].second });
        }

        answer = max(answer, (int)pq.size());
    }

    cout << answer;
}