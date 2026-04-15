#include <iostream>
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
    vector<pair<int,int>> v;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int S, E;
        cin >> S >> E;
        v.push_back({ S,E });
    }

    sort(v.begin(), v.end(), compare);
    
    vector<int> arr;
    arr.push_back(v[0].second);
    int first = v[0].first;
    int second = v[0].second;
    int answer = 0;
    for (int i = 1; i < N; i++)
    {
        int start = v[i].first;
        int end = v[i].second;

        bool possible = false;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] < start)
            {
                if (start - second <= 1)
                {
                    arr[j] = end;
                } // 연속적일 경우
                else
                {
                    answer += arr.size() * (second - first + 1);
                    first = start;
                    second = end;
                    arr.clear();
                    arr.push_back(second);
                } // 연속적이지 않을 경우

                possible = true;
                break;
            }
        }

        if (!possible)
        {
            arr.push_back(end);
        }
        second = max(second, end);
    }

    if (!arr.empty())
    {
        answer += arr.size() * (second - first + 1);
    }

    cout << answer;
}