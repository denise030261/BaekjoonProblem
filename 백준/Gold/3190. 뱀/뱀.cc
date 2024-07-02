#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K, L;
    int time = 0;
    int col[4] = { 1, 0, -1, 0 }; 
    int row[4] = { 0, 1, 0, -1 };
    int arr[101][101] = { 0 };
    bool check[101][101] = { false };
    vector<pair<int, char>> v;
    deque<pair<int, int>> dq;

    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1; 
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int X;
        char C;
        cin >> X >> C;
        v.push_back({ X, C });
    }

    int direction = 0; // 0 : right, 1 : down, 2 : left, 3 : up
    int i = 0;
    int current_row = 1;
    int current_col = 1;
    dq.push_front(make_pair(current_row, current_col));
    check[current_row][current_col] = true; 

    while (true)
    {
        time++;
        int next_row = current_row + row[direction];
        int next_col = current_col + col[direction];

        if (next_row <= 0 || next_row > N || next_col <= 0 || next_col > N || check[next_row][next_col])
        {
            break; 
        }

        current_row = next_row;
        current_col = next_col;
        check[current_row][current_col] = true;
        dq.push_front(make_pair(current_row, current_col));

        if (arr[current_row][current_col] == 0) 
        {
            int end_row = dq.back().first;
            int end_col = dq.back().second;
            check[end_row][end_col] = false;
            dq.pop_back(); 
        }
        else
        {
            arr[current_row][current_col] = 0; 
        }

        if (i < L && time == v[i].first)
        {
            if (v[i].second == 'D')
            {
                direction = (direction + 1) % 4; 
            }
            else
            {
                direction = (direction + 3) % 4; 
            }
            i++;
        }
    }

    cout << time << '\n';

    return 0;
}
