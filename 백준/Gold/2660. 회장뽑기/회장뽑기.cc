#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int arr[51][51] = { 0, }; // 각 노드와 노드의 비용
    int answers[51] = { 0, }; // 각 노드의 비용
    for (int i = 0; i <= 50; i++)
    {
        for (int j = 0; j <= 50; j++)
        {
            if (i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = 1e9;
        }
    }
    
    vector<int> v[51]; // 각 노드에 연결되어 있는 노드들
    cin >> N;
    while (1)
    {
        int freiend1, freiend2;
        cin >> freiend1 >> freiend2;
        if (freiend1 == -1 && freiend2 == -1)
            break;

        v[freiend1].push_back(freiend2);
        v[freiend2].push_back(freiend1);
    }

    for (int i = 1; i <= N; i++)
    {
        queue<pair<int, int>> q;
        q.push({ i,0 });
        while (!q.empty())
        {
            int cost = q.front().second;
            int loc = q.front().first;
            q.pop();
            for (int k = 0; k < v[loc].size(); k++)
            {
                if (arr[i][v[loc][k]] > cost + 1)
                {
                    q.push({ v[loc][k],cost + 1 });
                    arr[i][v[loc][k]] = cost + 1;
                    //arr[v[loc][k]][i] = cost + 1;
                }
            }
        }

        for (int j = 1; j <= N; j++)
        {
            answers[i] = max(arr[i][j], answers[i]);
        }
    }

    vector<int> answerV;
    int answer = 1e9;
    for (int i = 1; i <= N; i++)
    {
        if (answer > answers[i])
        {
            answerV.clear();
            answerV.push_back(i);
            answer = answers[i];
        }
        else if(answer == answers[i])
        {
            answerV.push_back(i);
        }
    }

    cout << answer << ' ' << answerV.size() << '\n';
    for (int i = 0; i < answerV.size(); i++)
    {
        cout << answerV[i] << ' ';
    }
}