#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>

using namespace std;

vector<int> v[11];
int people[101] = { 0, };
bool same[11] = { 0, };
int N;
int answer = INT_MAX;

int calculate()
{
    int numA = 0; // 같은 선거구 수
    int valueA = 0; // 선거구 특정값
    int totalA = 0; // 같은 선거구 인원 수

    int numB = 0;
    int totalB = 0;
    int valueB = 0;

    for (int i = 1; i <= N; i++)
    {
        if (same[i])
        {
            totalA += people[i];
            numA++;
            valueA = i;
        }
        else
        {
            totalB += people[i];
            numB++;
            valueB = i;
        }
    }

    if (numA == 0 || numB == 0)
    {
        return INT_MAX;
    }

    queue<int> qA;
    qA.push(valueA);
    bool visited[11] = { 0, };
    int visitedValue = 0;
    while (!qA.empty())
    {
        int value = qA.front();
        qA.pop();

        if (visited[value])
        {
            continue;
        }

        visited[value] = true;
        visitedValue++;
        for (int i = 0; i < v[value].size(); i++)
        {
            int next = v[value][i];
            if (same[next] && !visited[next])
            {
                qA.push(next);
            }
        }
    }

    if (visitedValue != numA)
    {
        return INT_MAX;
    }

    queue<int> qB;
    qB.push(valueB);
    memset(visited, 0, sizeof(visited));
    visitedValue = 0;
    while (!qB.empty())
    {
        int value = qB.front();
        qB.pop();

        if (visited[value])
        {
            continue;
        }

        visited[value] = true;
        visitedValue++;
        for (int i = 0; i < v[value].size(); i++)
        {
            int next = v[value][i];
            if (!same[next] && !visited[next])
            {
                qB.push(next);
            }
        }
    }

    if (visitedValue != numB)
    {
        return INT_MAX;
    }

    return abs(totalA-totalB);
}

void dfs(int index)
{
    for (int i = index; i <= N; i++)
    {
        same[i] = true;

        answer = min(answer, calculate());
        dfs(i + 1);
        same[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> people[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        
        for (int j = 0; j < num; j++)
        {
            int node;
            cin >> node;
            v[i].push_back(node);
        }
    }

    dfs(1);

    if (answer == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}