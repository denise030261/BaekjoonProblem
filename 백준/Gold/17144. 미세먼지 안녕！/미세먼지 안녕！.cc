#include <iostream>
#include <vector>

using namespace std;

int map[100][100] = { 0, };
int diffusionMap[100][100] = { 0, };

void diffusion(int R, int C) 
{
    for (int i = 0; i < R; i++) 
    {
        for (int j = 0; j < C; j++) 
        {
            if (map[i][j] > 0) 
            {
                int dust = map[i][j] / 5;
                int direction = 0;
                if (i > 0 && map[i - 1][j] != -1) 
                {
                    diffusionMap[i - 1][j] += dust;
                    direction++;
                }
                if (i < R - 1 && map[i + 1][j] != -1) 
                {
                    diffusionMap[i + 1][j] += dust;
                    direction++;
                }
                if (j > 0 && map[i][j - 1] != -1) 
                {
                    diffusionMap[i][j - 1] += dust;
                    direction++;
                }
                if (j < C - 1 && map[i][j + 1] != -1) 
                {
                    diffusionMap[i][j + 1] += dust;
                    direction++;
                }
                diffusionMap[i][j] += map[i][j] - dust * direction;
            }
        }
    }
}

void purify(int R, int C, pair<int, int> up, pair<int, int> down) 
{
    for (int i = up.first - 1; i > 0; i--)
    {
        map[i][0] = map[i - 1][0];
    }
    for (int j = 0; j < C - 1; j++)
    {
        map[0][j] = map[0][j + 1];
    }
    for (int i = 0; i < up.first; i++)
    {
        map[i][C - 1] = map[i + 1][C - 1];
    }
    for (int j = C - 1; j > 1; j--)
    {
        map[up.first][j] = map[up.first][j - 1];
    }
    map[up.first][1] = 0;

    for (int i = down.first + 1; i < R - 1; i++)
    {
        map[i][0] = map[i + 1][0];
    }
    for (int j = 0; j < C - 1; j++)
    {
        map[R - 1][j] = map[R - 1][j + 1];
    }
    for (int i = R - 1; i > down.first; i--)
    {
        map[i][C - 1] = map[i - 1][C - 1];
    }
    for (int j = C - 1; j > 1; j--)
    {
        map[down.first][j] = map[down.first][j - 1];
    }
    map[down.first][1] = 0;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int R, C, T;
    vector<pair<int, int>> purifiers;
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) 
    {
        for (int j = 0; j < C; j++) 
        {
            cin >> map[i][j];
            if (map[i][j] == -1) 
            {
                purifiers.push_back({ i, j });
            }
        }
    }

    for (int i = 0; i < T; i++)
    {
        fill(&diffusionMap[0][0], &diffusionMap[0][0] + sizeof(diffusionMap) / sizeof(int), 0);
        diffusion(R, C);

        for (int p = 0; p < R; p++)
        {
            for (int q = 0; q < C; q++)
            {
                if (map[p][q] != -1)
                {
                    map[p][q] = diffusionMap[p][q];
                }
            }
        }

        purify(R, C, purifiers[0], purifiers[1]);
    }

    int sum = 0;
    for (int i = 0; i < R; i++) 
    {
        for (int j = 0; j < C; j++) 
        {
            if (map[i][j] > 0) 
            {
                sum += map[i][j];
            }
        }
    }

    cout << sum << '\n';
    return 0;
}
