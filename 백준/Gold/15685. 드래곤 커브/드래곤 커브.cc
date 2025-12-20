#include <iostream>
#include <vector>

using namespace std;

int map[101][101] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> dirs;
        dirs.push_back(d); 

        for (int j = 0; j < g; j++) 
        {
            int size = dirs.size();
            for (int k = size - 1; k >= 0; k--)
            {
                dirs.push_back((dirs[k] + 1) % 4);
            }
        }

        map[y][x] = 1; 
        for (int j = 0; j < dirs.size(); j++)
        {
            x += dx[dirs[j]];
            y += dy[dirs[j]];

            if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
            {
                map[y][x] = 1;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (map[i][j] == 1 && map[i][j + 1] == 1 &&
                map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
            {
                answer++;
            }
        }
    }

    cout << answer;
}