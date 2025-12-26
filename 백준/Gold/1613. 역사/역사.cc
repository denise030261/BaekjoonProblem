#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    bool arr[401][401] = { 0, };

    for (int i = 0; i < k; i++)
    {
        int first, second;
        cin >> first >> second;
        arr[first][second] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (arr[k][i] && arr[i][j])
                {
                    arr[k][j] = true;
                }
            }
        }
    }
    

    int s;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int a, b;
        cin >> a >> b;

        if (arr[a][b])
        {
            cout << -1 << '\n';
        }
        else if (arr[b][a])
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}