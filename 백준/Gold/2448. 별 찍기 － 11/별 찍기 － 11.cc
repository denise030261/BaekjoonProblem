#include <iostream>
#include <cmath>

using namespace std;

int k = 0;
char map[3072][6144];


void DivConq(int N,int x,int y)
{
    if (N == 3)
    {
        map[x][y] = '*';
        map[x+1][y-1] = '*';
        map[x + 1][y + 1] = '*';
        for (int i = y - 2; i <= y + 2; i++)
        {
            map[x + 2][i] = '*';
        }
        return;
    }

    DivConq(N / 2, x, y);
    DivConq(N / 2, x + (N / 2), y - (N / 2));
    DivConq(N / 2, x + (N / 2), y + (N / 2));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            map[i][j] = ' ';
        }
    }

    DivConq(N, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }
}