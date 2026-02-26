#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int answer = 0;
    vector<pair<int, int>> v;
    priority_queue<pair<int, int>> pq;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int deadline = 0, ramen = 0;
        cin >> deadline >> ramen;
        v.push_back({ deadline,ramen });
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++)
    {
        int deadline = v[i].first;
        int ramen = v[i].second;
        pq.push({ -ramen,deadline });

        if (deadline < pq.size())
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        answer += -pq.top().first;
        pq.pop();
    }

    cout << answer;
}