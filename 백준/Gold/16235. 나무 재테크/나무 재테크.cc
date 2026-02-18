#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, M, K;
int A[11][11];      
int food[11][11];  
deque<int> tree[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            cin >> A[i][j];
            food[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sort(tree[i][j].begin(), tree[i][j].end());
        }
    }

    while (K--) 
    {
        for (int i = 1; i <= N; i++) 
        {
            for (int j = 1; j <= N; j++)
            {
                if (tree[i][j].empty()) 
                    continue;

                deque<int> alive;
                int dead_food = 0;
                for (int age : tree[i][j]) 
                {
                    if (food[i][j] >= age) 
                    {
                        food[i][j] -= age;
                        alive.push_back(age + 1);
                    }
                    else {
                        dead_food += (age / 2);
                    }
                }
                tree[i][j] = alive; 
                food[i][j] += dead_food; 
            }
        }

        for (int i = 1; i <= N; i++) 
        {
            for (int j = 1; j <= N; j++) 
            {
                for (int age : tree[i][j]) 
                {
                    if (age % 5 == 0) 
                    {
                        for (int d = 0; d < 8; d++) 
                        {
                            int ni = i + dx[d], nj = j + dy[d];
                            if (ni < 1 || ni > N || nj < 1 || nj > N)
                                continue;

                            tree[ni][nj].push_front(1);
                        }
                    }
                }
                food[i][j] += A[i][j]; 
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            ans += tree[i][j].size();

    cout << ans;
    return 0;
}