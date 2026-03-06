#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int map[20][20] = { 0, };
int dice[6] = { 1,2,3,4,5,6 };
int temp[6] = { 0, };
int dir = 0; // 0 : 오른쪽, 1은 아래, 2는 왼쪽, 3은 위
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int cur_x = 0;
int cur_y = 0;

void Init()
{
    for (int i = 0; i < 6; i++)
    {
        temp[i] = dice[i];
    }
}

void roll_R()
{
    Init();
    dice[2] = temp[0];
    dice[5] = temp[2];
    dice[0] = temp[3];
    dice[3] = temp[5];
}

void roll_L()
{
    Init();
    dice[3] = temp[0];
    dice[5] = temp[3];
    dice[0] = temp[2];
    dice[2] = temp[5];
}

void roll_U()
{
    Init();
    dice[1] = temp[0];
    dice[5] = temp[1];
    dice[4] = temp[5];
    dice[0] = temp[4];
}

void roll_D()
{
    Init();
    dice[4] = temp[0];
    dice[5] = temp[4];
    dice[0] = temp[1];
    dice[1] = temp[5];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, K;
    int answer = 0;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    while (K != 0)
    {
        int next_x = cur_x + dx[dir];
        int next_y = cur_y + dy[dir];

        // 주사위 움직이기
        if (next_x < 0)
        {
            dir = 1;
            next_x += 2;
        }
        else if (next_x >= N)
        {
            dir = 3;
            next_x -= 2;
        }
        else if (next_y < 0)
        {
            dir = 0;
            next_y += 2;
        }
        else if (next_y >= M)
        {
            dir = 2;
            next_y -= 2;
        }
        cur_x = next_x;
        cur_y = next_y;
        int B = map[next_x][next_y];

        // 밑 바닥
        if (dir == 0)
        {
            roll_R();
        }
        else if (dir == 1)
        {
            roll_D();
        }
        else if (dir == 2)
        {
            roll_L();
        }
        else if (dir == 3)
        {
            roll_U();
        }
        int A = dice[5];

        bool visited[20][20] = { 0, };
        queue <pair<int, int>> q;
        q.push({ cur_x,cur_y });
        int C = 0;
        int cost = map[cur_x][cur_y];
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (visited[x][y])
            {
                continue;
            }
            visited[x][y] = true;
            C++;

            for (int i = 0; i < 4; i++)
            {
                int nx_x = x + dx[i];
                int nx_y = y + dy[i];

                if (nx_x >= 0 && nx_x < N && nx_y >= 0 && nx_y < M)
                {
                    if (!visited[nx_x][nx_y] && cost == map[nx_x][nx_y])
                    {
                        q.push({ nx_x,nx_y });
                    }
                }
            }
        }
        answer += B * C;

        if (A > B)
        {
            dir = (dir + 1) % 4;
        }
        else if (A < B)
        {
            dir = (dir - 1 + 4) % 4;
        }

        K--;
    }

    cout << answer;
}