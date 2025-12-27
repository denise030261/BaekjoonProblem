#include <iostream>
#include <vector>
#include <queue> 
#define INF 10000007

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    long int arr[101][101] = { 0, };
    vector<long int> v[101][101];
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        long int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i!=j && arr[i][j]> arr[i][k] + arr[k][j])
                {
                    //cout << i << ' ' << j << " : ";
                    //cout << arr[i][j] << " -> " << arr[i][k] << ' ' << arr[k][j] << '\n';
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

                    if (!v[i][j].empty())
                    {
                        v[i][j].clear();
                    }
                    
                    for (int p = 0; p < v[i][k].size(); p++)
                    {
                        v[i][j].push_back(v[i][k][p]);
                    }
                    v[i][j].push_back(k);
                    for (int p = 0; p < v[k][j].size(); p++)
                    {
                        v[i][j].push_back(v[k][j][p]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == INF)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << arr[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == INF)
            {
                cout << 0 << '\n';
                continue;
            }

            cout << v[i][j].size()+2 << ' ';
            cout << i << ' ';
            for (int k = 0; k < v[i][j].size(); k++)
            {
                cout << v[i][j][k] << ' ';
            }
            cout << j << ' ';
            cout << '\n';
        }
    }
}