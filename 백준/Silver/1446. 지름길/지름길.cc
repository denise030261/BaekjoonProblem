#include <iostream> 
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, D;
    int answer[10001] = { 0, };
    vector<pair<int, int>> v[10001];

    cin >> N >> D;

    for (int i = 0; i < N; i++)
    {
        int start, end, length;
        cin >> start >> end >> length;
        v[start].push_back({ end,length });
    }

    for (int i = 0; i <= D; i++)
    {
        answer[i] = i;
    }

    for (int i = 0; i <= D; i++)
    {
        if (i != 0)
        {
            answer[i] = min(answer[i],answer[i - 1] + 1);
        }

        for (int j = 0; j < v[i].size(); j++)
        {
            int next = v[i][j].first;
            answer[next] = min(answer[next], answer[i] + v[i][j].second);
        }
    }

    cout << answer[D];
}