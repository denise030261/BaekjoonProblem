#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int answer = 0; 

void move_board(vector<vector<int>>& map, int dir)
{
    if (dir == 0) // 위
    { 
        for (int j = 0; j < N; j++) 
        { 
            queue<int> q;
            for (int i = 0; i < N; i++) 
            {
                if (map[i][j] != 0) 
                {
                    q.push(map[i][j]);
                }
                map[i][j] = 0; 
            }

            int index = 0;
            while (!q.empty()) 
            {
                int data = q.front();
                q.pop();

                if (map[index][j] == 0) 
                { 
                    map[index][j] = data;
                }
                else if (map[index][j] == data) 
                { 
                    map[index][j] *= 2;
                    index++; 
                }
                else 
                { 
                    index++;
                    map[index][j] = data;
                }
            }
        }
    }
    else if (dir == 1) // 아래
    { 
        for (int j = 0; j < N; j++)
        {
            queue<int> q;
            for (int i = N - 1; i >= 0; i--)
            { 
                if (map[i][j] != 0)
                {
                    q.push(map[i][j]);
                }
                map[i][j] = 0;
            }

            int index = N - 1;
            while (!q.empty()) 
            {
                int data = q.front();
                q.pop();

                if (map[index][j] == 0) 
                {
                    map[index][j] = data;
                }
                else if (map[index][j] == data) 
                {
                    map[index][j] *= 2;
                    index--;
                }
                else 
                {
                    index--;
                    map[index][j] = data;
                }
            }
        }
    }
    else if (dir == 2) // 왼쪽
    { 
        for (int i = 0; i < N; i++)
        {
            queue<int> q;
            for (int j = 0; j < N; j++) 
            {
                if (map[i][j] != 0) 
                {
                    q.push(map[i][j]);
                }
                map[i][j] = 0;
            }

            int index = 0;
            while (!q.empty()) 
            {
                int data = q.front();
                q.pop();

                if (map[i][index] == 0) 
                {
                    map[i][index] = data;
                }
                else if (map[i][index] == data) 
                {
                    map[i][index] *= 2;
                    index++;
                }
                else 
                {
                    index++;
                    map[i][index] = data;
                }
            }
        }
    }
    else if (dir == 3) // 오른쪽 
    { 
        for (int i = 0; i < N; i++) 
        {
            queue<int> q;
            for (int j = N - 1; j >= 0; j--) 
            { 
                if (map[i][j] != 0) 
                {
                    q.push(map[i][j]);
                }
                map[i][j] = 0;
            }

            int index = N - 1;
            while (!q.empty()) 
            {
                int data = q.front();
                q.pop();

                if (map[i][index] == 0) 
                {
                    map[i][index] = data;
                }
                else if (map[i][index] == data) 
                {
                    map[i][index] *= 2;
                    index--;
                }
                else 
                {
                    index--;
                    map[i][index] = data;
                }
            }
        }
    }
}

void dfs(vector<vector<int>> map, int length)
{
    if (length == 5) 
    {
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                answer = max(answer, map[i][j]);
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) 
    {
        vector<vector<int>> next_map = map;
        move_board(next_map, i); 
        dfs(next_map, length + 1); 
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> v[i][j];
        }
    }

    dfs(v, 0);
    cout << answer;
}