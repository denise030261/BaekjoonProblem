#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
bool visited[15][15] = { 0, };
int N;
int answer = 0;

void dfs(int length, int x, int y)
{
    if (length == N)
    {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        bool isPossible = true;
        for (int j = 0; j < v.size(); j++)
        {
            int preX = v[j].first;
            int preY = v[j].second;
            if (preY == i || preX - preY == length - i || preX + preY == length + i)
            {
                isPossible = false;
                break;
            }
        }

        if (isPossible)
        {
            v.push_back(make_pair(length, i));
            dfs(length + 1, x, y);
            v.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    dfs(0, 0, 0);

    cout << answer;
}