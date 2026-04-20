#include <iostream>
#include <vector>

using namespace std;

int s, N, K, R1, R2, C1, C2;

int getColor(int len, int r, int c) 
{
    if (len == 1) 
        return 0;

    int prev_len = len / N;
    int black_start = (N - K) / 2 * prev_len;
    int black_end = black_start + K * prev_len;

    if (r >= black_start && r < black_end && c >= black_start && c < black_end) 
    {
        return 1;
    }

    return getColor(prev_len, r % prev_len, c % prev_len);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

    int length = 1;

    while (R2 > length || C2 > length)
    {
        length *= N;
    }

    for (int i = R1; i <= R2; i++)
    {
        for (int j = C1; j <= C2; j++)
        {
            cout << getColor(length, i, j);
        }
        cout << '\n';
    }
}