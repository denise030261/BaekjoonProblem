#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int arr[100001] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    vector<pair<int, int>> v;
    priority_queue<pair<int, int>> users; // 끝나는 시간, 인덱스
    priority_queue<int> possible_users; // 비어있는 인덱스
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int P, Q;
        cin >> P >> Q;
        v.push_back({ P,Q });
    }

    sort(v.begin(), v.end());

    int total = 0;
    for (int i = 0; i < N; i++)
    {
        int start = v[i].first;
        int end = v[i].second;

        //cout << start << ' ' << end << " : ";
        while (!users.empty())
        {
            int value = -users.top().first;
            int idx = -users.top().second;

            users.pop();
            if (value <= start)
            {
                possible_users.push(-idx);
            }
            else
            {
                users.push({ -value,-idx });
                break;
            }
        }

        if(!possible_users.empty())
        {
            //cout << -end << ' ' << -possible_users.top() << " 빈 배치\n";
            int current = -possible_users.top();
            users.push({ -end,-current });
            arr[current]++;
            possible_users.pop();
        }
        else
        {
            //cout << -end << ' ' << -newSize << "배치\n";
            users.push({ -end,-total });
            arr[total]++;
            total++;
        }
    }

    cout << total << '\n';
    for (int i = 0; i < total; i++)
    {
        cout << arr[i] << ' ';
    }
}