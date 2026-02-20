#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

char map[10][10];

void move(int& x, int& y, int dx, int dy, int& d, bool& hole) 
{
    d = 0;
    while (map[x + dx][y + dy] != '#' && map[x][y] != 'O') 
    {
        x += dx;
        y += dy;
        d++; 

        if (map[x][y] == 'O')
        {
            hole = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    pair<int, int> Blue;
    pair<int, int> goal;
    int answer = INT_MAX;

    cin >> N >> M;
    pair<int, int> Red;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            map[i][j] = c;

            if (map[i][j] == 'B')
            {
                Blue.first = i;
                Blue.second = j;
            }
            else if (map[i][j] == 'R')
            {
                Red.first = i;
                Red.second = j;
            }
        }
    }

    bool visited[10][10][10][10] = { 0, };
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    queue < pair<int, pair<pair<int, int>, pair<int, int>>>> q;
    q.push({ 0,{Red,Blue} });
    while (!q.empty())
    {
        int cost = q.front().first;
        int red_x = q.front().second.first.first;
        int red_y = q.front().second.first.second;
        int blue_x = q.front().second.second.first;
        int blue_y = q.front().second.second.second;
        pair<int, int> Prev_R = { red_x ,red_y};
        pair<int, int> Prev_B = { blue_x ,blue_y };
        q.pop();

        if (visited[red_x][red_y][blue_x][blue_y] || cost>=10)
        {
            continue;
        }
        visited[red_x][red_y][blue_x][blue_y] = true;

        for (int i = 0; i < 4; i++)
        {
            red_x = Prev_R.first;
            red_y = Prev_R.second;
            blue_x = Prev_B.first;
            blue_y = Prev_B.second;

            int red_dist = 0;
            int blue_dist = 0;
            bool red_hole = false;
            bool blue_hole = false;

            move(red_x, red_y, dx[i], dy[i], red_dist, red_hole);
            move(blue_x, blue_y, dx[i], dy[i], blue_dist, blue_hole);

            if (red_hole && !blue_hole)
            {
                answer = min(answer, cost + 1);
            }
            
            if (red_x == blue_x && red_y == blue_y)
            {
                if (red_dist < blue_dist)
                {
                    blue_x -= dx[i];
                    blue_y -= dy[i];
                }
                else 
                {
                    red_x -= dx[i];
                    red_y -= dy[i];
                }
            }
            if (!red_hole && !blue_hole)
            {
                Red.first = red_x;
                Red.second = red_y;
                Blue.first = blue_x;
                Blue.second = blue_y;
                q.push({ cost + 1,{Red,Blue} });
            }
        }
    }

    if (answer == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}