#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string magic, strDevil, strAngel;
    int dpDevil[100][20] = { 0, }; // 1 : 위치 인덱스, 2 : 두루마리 인덱스 
    int dpAngel[100][20] = { 0, };

    cin >> magic >> strDevil >> strAngel;

    int N = magic.length();
    int M = strDevil.length();

    if (strDevil[0] == magic[0])
    {
        dpDevil[0][0]++;
    }
    if (strAngel[0] == magic[0])
    {
        dpAngel[0][0]++;
    }

    for (int i = 1; i < M; i++)
    {
        if (strDevil[i] == magic[0])
        {
            dpDevil[i][0] = dpDevil[i - 1][0] + 1;
        }
        else
        {
            dpDevil[i][0] = dpDevil[i - 1][0];
        }
        if (strAngel[i] == magic[0])
        {
            dpAngel[i][0] = dpAngel[i - 1][0] + 1;
        }
        else
        {
            dpAngel[i][0] = dpAngel[i - 1][0];
        }

        for (int j = 1; j < N; j++)
        {
            if (strDevil[i] == magic[j])
            {
                dpDevil[i][j] = dpDevil[i - 1][j] + dpAngel[i - 1][j - 1];
            }
            else if (strDevil[i] != magic[j])
            {
                dpDevil[i][j] = dpDevil[i - 1][j];
            }

            if (strAngel[i] == magic[j])
            {
                dpAngel[i][j] = dpAngel[i - 1][j] + dpDevil[i - 1][j - 1];
            }
            else if (strAngel[i] != magic[j])
            {
                dpAngel[i][j] = dpAngel[i - 1][j];
            }
        }
    }

    cout << dpDevil[M-1][N-1] + dpAngel[M - 1][N - 1];
}