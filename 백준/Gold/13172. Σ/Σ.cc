#include <iostream>
#define DIV 1000000007

using namespace std;

long long int calculate(int a,int b)
{
    long long int answer = 1;

    if (a == 1)
    {
        return b;
    }

    if (a % 2 == 1)
    {
        answer = (answer * b)%DIV;
    }
    long long half = calculate(a / 2, b) % DIV;
    answer = (answer *( (half * half) % DIV))%DIV;

    return answer;
}

long long int gcd(long long int a, long long int b)
{
    long long int c;

    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M;
    long long int answer = 0;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int N, S;
        cin >> N >> S;
        
        long long int div = gcd(S, N);
        N /= div;
        S /= div;

        long long int result = calculate(DIV - 2, N) % DIV;
        answer = (answer+((S * result) % DIV))% DIV;
    }

    cout << answer;
}