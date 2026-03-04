#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[499][499] = { 0, };

int cur_x = N / 2;
int cur_y = N / 2;
int move = 1;
int total = 0;
int dir = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int answer = 0;
int sum = 0;

void blow(int next_x,int next_y, int move_x,int move_y,int& sand, int value, bool alpha)
{
    if (alpha)
    {
        if ((move_x >= 0 && move_x < N)
            && (move_y >= 0 && move_y < N))
        {
            map[move_x][move_y] += value;
        }
        else
        {
            answer += value;
        }
        return;
    }

    if ((move_x >= 0 && move_x < N)
        && (move_y >= 0 && move_y < N))
    {
        map[move_x][move_y] += (sand * value) / 100;
    }
    else
    {
        answer += (sand * value) / 100;
    }
    sum += (sand * value) / 100;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    int move = 1;
    cur_x = N / 2;
    cur_y = N / 2;
    int turn_x = cur_x + dx[dir] * move;
    int turn_y = cur_y + dy[dir] * move;
    while (!(cur_x <= 0 && cur_y <= 0))
    {
        int next_x = cur_x + dx[dir];
        int next_y = cur_y + dy[dir];

        //cout << next_x << ' ' << next_y << ' ' << turn_x << ' ' << turn_y << '\n';

        int sand = map[next_x][next_y];
        // 5%
        int move_x = next_x + (dx[dir] * 2);
        int move_y = next_y + (dy[dir] * 2);
        blow(next_x, next_y, move_x, move_y, sand, 5,false);
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        // 1%
        move_x = next_x + (dx[(dir + 2) % 4] * 1) + (dx[(dir + 1) % 4] * 1);
        move_y = next_y + (dy[(dir + 2) % 4] * 1) + (dy[(dir + 1) % 4] * 1);
        blow(next_x, next_y, move_x, move_y, sand, 1, false);
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        move_x = next_x + (dx[(dir + 2) % 4] * 1) + (dx[(dir + 3) % 4] * 1);
        move_y = next_y + (dy[(dir + 2) % 4] * 1) + (dy[(dir + 3) % 4] * 1);
        blow(next_x, next_y, move_x, move_y, sand, 1, false);
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        // 7%
        move_x = next_x + (dx[(dir + 1) % 4] * 1);
        move_y = next_y + (dy[(dir + 1) % 4] * 1);
        blow(next_x, next_y, move_x, move_y, sand, 7, false);
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        move_x = next_x + (dx[(dir + 3) % 4] * 1);
        move_y = next_y + (dy[(dir + 3) % 4] * 1);
        blow(next_x, next_y, move_x, move_y, sand, 7, false);
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        // 2%
        move_x = next_x + (dx[(dir + 1) % 4] * 2);
        move_y = next_y + (dy[(dir + 1) % 4] * 2);
        blow(next_x, next_y, move_x, move_y, sand, 2, false);
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        move_x = next_x + (dx[(dir + 3) % 4] * 2);
        move_y = next_y + (dy[(dir + 3) % 4] * 2);
        blow(next_x, next_y, move_x, move_y, sand, 2, false);
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        // 10%
        move_x = next_x + (dx[dir % 4] * 1) + (dx[(dir + 1) % 4] * 1);
        move_y = next_y + (dy[dir % 4] * 1) + (dy[(dir + 1) % 4] * 1);
        blow(next_x, next_y, move_x, move_y, sand, 10, false);
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        move_x = next_x + (dx[dir % 4] * 1) + (dx[(dir + 3) % 4] * 1);
        move_y = next_y + (dy[dir % 4] * 1) + (dy[(dir + 3) % 4] * 1);
        blow(next_x, next_y, move_x, move_y, sand, 10, false);
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        // alpha
        move_x = next_x + (dx[dir] * 1);
        move_y = next_y + (dy[dir] * 1);
       // cout << sand << ' ' << sum << '\n';
        blow(next_x, next_y, move_x, move_y, sand, abs(sand-sum), true);
        sum = 0;
        //cout << move_x << ' ' << move_y << ' ' << sand << '\n';

        cur_x = next_x;
        cur_y = next_y;
        map[cur_x][cur_y] = 0;
    
        if (turn_x == cur_x && turn_y == cur_y)
        {
            if (total + 1 >= 2)
            {
                total = 0;
                move++;
            }
            else
            {
                total++;
            }

            dir = (dir + 1) % 4;
            turn_x = next_x + dx[dir] * move;
            turn_y = next_y + dy[dir] * move;
        }
        //cout << cur_x << ' ' << cur_y << '\n';
    }
    cout << answer;
}