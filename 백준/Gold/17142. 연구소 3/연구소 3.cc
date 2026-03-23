#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int N, M; // 연구소 크기, 놓을 수 있는 바이러스의 크기
int arr[50][50] = { 0, };
bool visited[50][50] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<pair<int, int>> virus; // 모든 바이러스
vector<int> placed_virus; // 놓을 바이러스
int answer = INT_MAX;
int area = 0;

void infect()
{
    int temp = area;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < placed_virus.size(); i++)
    {
        int index = placed_virus[i];
        int x = virus[index].first;
        int y = virus[index].second;

        pq.push({ -0,{x,y} });
    } // 바이러스 활성화

    while (!pq.empty())
    {
        int second = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (visited[x][y])
        {
            continue;
        }

        if(arr[x][y]==0)
        {
            temp--;
        }
        visited[x][y] = true;

        if (temp == 0)
        {
            answer = min(answer, second);
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
            {
                if (!visited[next_x][next_y] && (arr[next_x][next_y] == 0 || arr[next_x][next_y] == 2))
                {
                    pq.push({ -(second + 1),{next_x,next_y} });
                }
            }
        }
    }

}

void place(int index)
{
    if (placed_virus.size() == M)
    {
        infect();
        return;
    }

    for (int i = index; i < virus.size(); i++)
    {
        placed_virus.push_back(i);
        place(i + 1);
        placed_virus.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 0)
            {
                area++;
            }
            else if (arr[i][j] == 2)
            {
                virus.push_back({ i,j });
            }
        }
    }

    if (area == 0)
    {
        cout << 0;
        return 0;
    }
 
    place(0);
    if (answer == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}