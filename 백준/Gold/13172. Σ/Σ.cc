#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int mod = 1000000007;
	long long int answer = 0;
	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
        int S, N;
        cin >> N >> S;

        long long int result = 1;
        long long int base = N; 
        long long int exp = mod - 2;

        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * base) % mod;
            }
            base = (base * base) % mod; 
            exp /= 2;
        }

        answer += (S * result) % mod; 
        answer %= mod;
	}

	cout << answer;
}