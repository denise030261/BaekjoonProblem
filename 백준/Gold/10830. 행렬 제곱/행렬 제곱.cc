#include <iostream>
#include <vector>

using namespace std;

long long int N, B;
int arr[5][5] = { 0, };

void calculate(int A[5][5], int B[5][5], int C[5][5])
{
    int temp[5][5] = { 0, };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int sum = 0;
            for (int k = 0; k < N; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            temp[i][j] = sum;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = temp[i][j]%1000;
        }
    }
}

void divAndConq(long long int cur, int cal[5][5])
{
    if (cur == 1)
    {
        calculate(arr, cal, cal);
        return;
    }

    divAndConq(cur / 2, cal);

    calculate(cal, cal, cal);
    if (cur % 2 == 1)
    {
        calculate(cal, arr, cal);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> B;
    int answer[5][5] = { 0, };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];

            if(i==j)
                answer[i][j] = 1;
        }
    }

    divAndConq(B, answer);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}