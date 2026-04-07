#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int answer = 4;
int N, M, H; // N은 세로선, M은 가로선
bool placed[11][31] = { 0, };

bool check()
{
    for (int i = 1; i <= N; i++)
    {
        int current = i;
        for (int j = 1; j <= H; j++)
        {
            if (placed[current][j])
            {
                current++;
            }
            else if (current > 1 && placed[current - 1][j])
            {
                current--;
            }
        }

        if (current != i)
        {
            return false;
        }
    }

    return true;
}

void dfs(int cnt, int x, int y)
{
    if (cnt >= answer) return;

    if (check())
    {
        answer = cnt;
        return;
    }

    if (cnt == 3) return;

    for (int i = x; i <= H; i++)
    {
        for (int j = (i == x ? y : 1); j < N; j++)
        {
            if (!placed[j][i] && !placed[j - 1][i] && !placed[j + 1][i])
            {
                placed[j][i] = true;
                dfs(cnt + 1, i, j + 2);
                placed[j][i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {
        int a, b; // b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결
        cin >> a >> b;
        placed[b][a] = true;
    }

    dfs(0, 1, 1);
    
    if (answer == 4)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }

}