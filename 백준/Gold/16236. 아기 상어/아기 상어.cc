#include <iostream>
#include <queue>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    int map[22][22];
    int dx[] = { 0, -1, 1, 0 };
    int dy[] = { -1, 0, 0, 1 };
    int startX, startY;
    int result = 0; 
    int count = 0; 
    int shark = 2; 
    bool stop = false; 
    bool eat = false; 

    cin >> N;
    for (int i = 0; i <N; i++)
    {
        for (int j = 0; j <N; j++) 
        {
            cin >> map[i][j];
            if (map[i][j] == 9) 
            {
                startY = i; 
                startX = j;
                map[i][j] = 0;
            }
        }
    }

    while (!stop) 
    {
        bool visit[20][20] = { 0 };
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(make_pair(startX, startY), 0));
        visit[startY][startX] = true;
        int temp; 
        while (!q.empty()) 
        {
            int x = q.front().first.first; 
            int y = q.front().first.second; 
            int cnt = q.front().second; 
            if (map[y][x] > 0 && map[y][x] < shark && temp == cnt) 
            {
                if ((startY > y) || (startY == y && startX > x)) 
                {
                    startY = y; 
                    startX = x;
                    continue;
                }
            }
            q.pop();

            for (int i = 0; i < 4; i++) 
            {
                int nx = x + dx[i]; 
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[ny][nx]) 
                {
                    if (map[ny][nx] <= shark) 
                    {
                        if (map[ny][nx] > 0 && map[ny][nx] < shark && !eat) 
                        { 
                            eat = true; 
                            startX = nx; 
                            startY = ny;
                            temp = cnt + 1;
                            result += temp; 
                        }
                        else 
                        { 
                            q.push(make_pair(make_pair(nx, ny), cnt + 1));
                            visit[ny][nx] = true;
                        }
                    }
                }
            }
        }

        if (eat) 
        { 
            eat = false;
            count += 1; 
            map[startY][startX] = 0; 
            if (count == shark) 
            { 
                shark += 1; 
                count = 0; 
            }
        }
        else 
        { 
            stop = true; 
        }
    }

    cout << result << '\n';
}
