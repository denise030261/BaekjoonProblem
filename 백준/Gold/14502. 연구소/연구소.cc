#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int arr[8][8] = { 0, };
int temp[8][8] = { 0, };
vector<pair<int, int>> v; // 벽을 배치될 빈 공간
vector<pair<int, int>> infection; // 바이러스 
bool placed[8][8] = { 0, };
bool visited[8][8] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;

void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            temp[i][j] = arr[i][j];
            visited[i][j] = false;
        }
    }
}

void bfs()
{
    init();

    queue<pair<int, int>> q;
    for (int i = 0; i < infection.size(); i++)
    {
        int x = infection[i].first;
        int y = infection[i].second;
        q.push({ x,y });
        visited[x][y] = true;
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
            {
                if (temp[next_x][next_y] == 0 && !visited[next_x][next_y])
                {
                    visited[next_x][next_y] = true;
                    temp[next_x][next_y] = 2;
                    q.push({ next_x,next_y });
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp[i][j] == 0)
            {
                sum++;
            }
        }
    }
    answer = max(sum, answer);
} // 감염 및 계산

void place(int index, int length)
{
    if (length == 3)
    {
        bfs();
        return;
    } // 벽 배치 완료

    for (int i = index; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        if (!placed[x][y])
        {
            placed[x][y] = true;
            arr[x][y] = 1;
            place(i + 1, length + 1);
            arr[x][y] = 0;
            placed[x][y] = false;
        }
    }
} // 빈 곳 벽 배치

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 0)
            {
                v.push_back({ i,j });
            }
            else if (arr[i][j] == 2)
            {
                infection.push_back({ i,j });
            }
        }
    }

    place(0, 0);

    cout << answer;
}