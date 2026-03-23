#include <iostream>
#define INF 987654321;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, r;
    int arr[101][101] = { 0, };
    int cost[101] = { 0, };
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    } // 아이템 수 입력

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = INF;
            arr[j][i] = INF;
        }
        arr[i][i] = 0;
    }

    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
        arr[b][a] = c;
    } // 길 입력

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    } // 플로이드

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] <= m)
            {
                sum += cost[j];
            }
        }
        
        answer = max(answer, sum);
    }

    cout << answer;
}