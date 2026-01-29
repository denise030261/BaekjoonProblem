#include <iostream> 
#include <vector>
#include <string>

using namespace std;
char map[50][50];

int answer = -1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N;

void calculate(int x, int y)
{
    int sum = 1;
    bool plus = true;
    bool minus = true;
    for (int i = 1; i < N; i++)
    {
        if (i + x < N && plus)
        {
            if (map[x][y] == map[i + x][y])
            {
                sum++;
            }
            else 
            {
                plus = false;
            }
        }

        if (x-i >= 0 && minus)
        {
            if (map[x][y] == map[x - i][y])
            {
                sum++;
            }
            else
            {
                minus = false;
            }
        }
    }
    answer = max(answer, sum);

    sum = 1;
    plus = true;
    minus = true;
    for (int i = 1; i < N; i++)
    {
        if (i + y < N && plus)
        {
            if (map[x][y] == map[x][y+i])
            {
                sum++;
            }
            else
            {
                plus = false;
            }
        }
        if (y - i >= 0 && minus)
        {
            if (map[x][y] == map[x][y-i])
            {
                sum++;
            }
            else
            {
                minus = false;
            }
        }
    }
    answer = max(answer, sum);
}

void search(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
        {
            if (map[x][y] != map[next_x][next_y])
            {
                swap(map[x][y], map[next_x][next_y]);
                calculate(x, y);
                calculate(next_x, next_y);
                swap(map[x][y], map[next_x][next_y]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            map[i][j] = str[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            calculate(i, j);
            search(i, j);
        }
    }

    cout << answer;
}