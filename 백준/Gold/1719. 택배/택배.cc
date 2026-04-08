#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    vector<pair<int,int>> v[201];
    int arr[201][201] = { 0, };
    int order[201][201] = { 0, };
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = INF;
            order[i][j] = j;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        arr[a][b] = c;
        arr[b][a] = c;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][j] > arr[k][j] + arr[i][k])
                {
                    arr[i][j] = arr[k][j] + arr[i][k];
                    order[i][j] = order[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                cout << "- ";
            }
            else if (order[i][j] == -1)
            {
                cout << j << ' ';
            }
            else
            {
                cout << order[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}