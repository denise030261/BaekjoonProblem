#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int N, M, R;
int map[300][300] = { 0, };
bool visited[300][300] = { 0, };

void turn(int N_start, int N_end, int M_start, int M_end)
{
    visited[N_start][M_start] = true;
    int temp = map[N_start][M_start];
    for (int i = M_start; i < M_end - 1; i++)
    {
        visited[N_start][i] = true;
        map[N_start][i] = map[N_start][i + 1];
    }
    for (int i = N_start; i < N_end - 1; i++)
    {
        visited[i][M_end - 1] = true;
        map[i][M_end - 1] = map[i + 1][M_end - 1];
    }
    for (int i = M_end - 1; i > M_start; i--)
    {
        visited[N_end - 1][i] = true;
        map[N_end - 1][i] = map[N_end - 1][i - 1];
    }
    for (int i = N_end - 1; i > N_start; i--)
    {
        visited[i][M_start] = true;
        map[i][M_start] = map[i - 1][M_start];
    }
    visited[N_start + 1][M_start] = true;
    map[N_start+1][M_start] = temp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    while (R != 0)
    {
        int index = 0;
        memset(visited, 0, sizeof(visited));

        while (!visited[index][index])
        {
            turn(index, N - index, index, M - index);
            index++;
        }
        R--;
    } // 회전

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}