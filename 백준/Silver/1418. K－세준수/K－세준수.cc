#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<bool> isPrime(N + 1, true);
    vector<int> largePrim(N + 1, 0);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= N; i++) 
    {
        if (isPrime[i]) 
        {
            for (int j = i; j <= N; j += i) 
            {
                isPrime[j] = false;
                largePrim[j] = i;
            }
            isPrime[i] = true; 
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) 
    {
        if (largePrim[i] <= K)
        {
            answer++;
        }
    }

    cout << answer << '\n';
}
