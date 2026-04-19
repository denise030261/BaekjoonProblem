#include <iostream>
#include <vector>

using namespace std;

long int N;

void solve(long long total_len, int k, long long n) 
{
    long long prev_len = (total_len - (k + 3)) / 2;

    if (n <= prev_len) 
    {
        solve(prev_len, k - 1, n);
    }
    else if (n <= prev_len + (k + 3)) 
    {
        if (n - prev_len == 1) 
            cout << "m";
        else 
            cout << "o";
        return;
    }
    else 
    {
        solve(prev_len, k - 1, n - (prev_len + k + 3));
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int k = 0;
    int L = 3;
    int prev = 3;
    while (L < N)
    {
        k++;
        L = prev + (k + 3) + prev;
        prev = L;
    }
    solve(L, k, N);
}