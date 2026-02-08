#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int arr[100000][3] = { 0, };
    int answer[3] = { 0, };
    int prev[3] = { 0, };
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    } 

    prev[0] = arr[0][0]; prev[1] = arr[0][1]; prev[2] = arr[0][2];

    for (int i = 1; i < N; i++)
    {
        answer[0] = max(prev[0], prev[1]) + arr[i][0];
        answer[1] = max(prev[0], max(prev[1], prev[2])) + arr[i][1];
        answer[2] = max(prev[2], prev[1]) + arr[i][2];

        prev[0] = answer[0]; prev[1] = answer[1]; prev[2] = answer[2];
    }

    if (N == 1)
    {
        cout << max(prev[0], max(prev[1], prev[2])) << ' ';
    }
    else
    {
        cout << max(answer[0], max(answer[1], answer[2])) << ' ';
    }
    prev[0] = arr[0][0]; prev[1] = arr[0][1]; prev[2] = arr[0][2];

    for (int i = 1; i < N; i++)
    {
        answer[0] = min(prev[0], prev[1]) + arr[i][0];
        answer[1] = min(prev[0], min(prev[1], prev[2])) + arr[i][1];
        answer[2] = min(prev[2], prev[1]) + arr[i][2];

        prev[0] = answer[0]; prev[1] = answer[1]; prev[2] = answer[2];
    }

    if (N == 1)
    {
        cout << min(prev[0], min(prev[1], prev[2]));
    }
    else
    {
        cout << min(answer[0], min(answer[1], answer[2]));
    }
}