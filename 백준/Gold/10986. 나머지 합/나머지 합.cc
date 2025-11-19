#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int N, M;
    long long int arr[1001] = { 0, };
    cin >> N >> M;

    long long int sum = 0;
    arr[0]++;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        sum += num;
        arr[sum % M]++;
    }

    long long int answer = 0;
    for (int i = 0; i < M; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        else
        {
            answer += (arr[i] * (arr[i] - 1)) / 2;
        }
    }
    cout << answer;
}