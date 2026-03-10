#include <iostream>
#include <vector>
#define DIV  1000000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> dp1(N);
    vector<int> dp2(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        dp1[i] = 1;
        dp2[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for (int i = N-1; i >=0 ; i--)
    {
        for (int j = N-1; j > i; j--)
        {
            if (v[i] > v[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        answer = max(dp1[i] + dp2[i] - 1, answer);
    }
    cout << answer;
}