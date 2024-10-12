#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    int map[50][50];
    bool visited[50][50];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    // 지도 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            map[i][j] = (c == 'L' ? 1 : 0); 
        }
    }

    int result = 0;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (map[i][j] == 1) 
            {
                fill(&visited[0][0], &visited[0][0] + 50 * 50, false);

                queue<pair<int, int>> q;
                q.push({ i, j });
                visited[i][j] = true;

                int distance[50][50] = { 0 };  
                int maxDistance = 0;

                while (!q.empty()) 
                {
                    int x = q.front().second;
                    int y = q.front().first;
                    q.pop();

                    for (int k = 0; k < 4; k++) 
                    {
                        int nextX = x + dx[k];
                        int nextY = y + dy[k];

                        if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) 
                        {
                            if (!visited[nextY][nextX] && map[nextY][nextX] == 1) 
                            {
                                visited[nextY][nextX] = true;
                                q.push({ nextY, nextX });
                                distance[nextY][nextX] = distance[y][x] + 1;
                                maxDistance = max(maxDistance, distance[nextY][nextX]);
                            }
                        }
                    }
                }

                result = max(result, maxDistance);  
            }
        }
    }

    cout << result << '\n';
}