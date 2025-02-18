#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int cheeses[100][100] = { 0, };
bool visited[100][100] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int hour = 0;

void outair()
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> air;
    air.push({ 0,0 });
    while (!air.empty())
    {
        int x = air.front().first;
        int y = air.front().second;
        air.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N)
            {
                if (!visited[next_y][next_x] && (cheeses[next_y][next_x]==0|| cheeses[next_y][next_x]==2))
                {
                    visited[next_y][next_x] = true;
                    cheeses[next_y][next_x] = 2;
                    air.push({ next_x,next_y });
                }
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cheese_num = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> cheeses[i][j];
            if (cheeses[i][j] == 1)
                cheese_num++;
        }
    }

    outair();
    while (cheese_num != 0)
    {
        queue<pair<int, int>> search;  

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                if (cheeses[i][j] == 1) 
                {
                    int outside = 0;

                    for (int k = 0; k < 4; k++) 
                    {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (cheeses[ny][nx] == 2) outside++;
                    }

                    if (outside >= 2) 
                    {
                        search.push({ i, j });
                    }
                }
            }
        }

        if (search.empty()) 
            break; 

        while (!search.empty()) 
        {
            int y = search.front().first;
            int x = search.front().second;
            search.pop();
            cheeses[y][x] = 2;  
            cheese_num--;
        }

        outair();
        hour++;
    }
    cout << hour;
}
