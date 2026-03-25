#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.first == b.first)
    {
        if (a.second.first == b.second.first)
        {
            return a.second.second < b.second.second;
        }

        return a.second.first < b.second.first;
    }
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    int A[100] = { 0, };
    int B[100] = { 0, };

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i] == B[j])
            {
                v.push_back({ A[i],{i,j} });
            }
        }
    }

    sort(v.begin(), v.end(), compare);

    if (v.size() == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> answer;
    answer.push_back(v[0].first);
    int answer_num = v[0].first;
    int answer_Aidx = v[0].second.first;
    int answer_Bidx = v[0].second.second;
    for (int i = 1; i < v.size(); i++)
    {
        if (answer_num >= v[i].first && answer_Aidx<v[i].second.first && answer_Bidx<v[i].second.second)
        {
            answer.push_back(v[i].first);
            answer_num = v[i].first;
            answer_Aidx = v[i].second.first;
            answer_Bidx = v[i].second.second;
        }
    }

    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
}