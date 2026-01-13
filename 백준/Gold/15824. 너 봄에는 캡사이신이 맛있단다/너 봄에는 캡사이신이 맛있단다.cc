#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#define DIV 1000000007;

using namespace std;

long long int binary[300001] = { 0, };

long long int calculate(int bottom, int exponent)
{
    long long int num = 0;
    if (exponent <= 1)
    {
        return 2;
    }

    if (binary[exponent / 2]==0)
    {
        binary[exponent / 2] = calculate(bottom, exponent / 2)%DIV;
    }
    if (binary[exponent - (exponent / 2)] == 0)
    {
        binary[exponent - (exponent / 2)] = calculate(bottom, exponent - (exponent / 2)) % DIV;
    }

    binary[exponent] = (binary[exponent / 2] * binary[exponent - (exponent / 2)]) % DIV;

    return binary[exponent];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    vector<int> v;
    long long int answer = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    binary[0] = 1;
    for (int i = N; i >= 1; i--)
    {
        calculate(2, i);
    }

    for (int i = 0; i < N; i++)
    {
        answer = (answer + v[i] * (binary[i] - binary[N - 1 - i] + 1000000007)) % DIV;
    }

    cout << answer;
}