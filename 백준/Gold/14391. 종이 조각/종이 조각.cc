#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    int arr[4][4] = {0,};
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    int answer = 0;
    for (int i = 0; i < (1 << N*M); i++)
    {
        int sum = 0;
        string str = "";

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if ((i & (1 << j*M+k)) == 0)
                {
                    str += ('0' + arr[j][k]);
                }
                else
                {
                    if (str != "")
                    {
                        sum += stoi(str);
                        str = "";
                    }
                }
            }

            if (str != "")
            {
                sum += stoi(str);
                str = "";
            }
        }

        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if ((i & (1 << k*M+j)) != 0)
                {
                    str += ('0' + arr[k][j]);
                }
                else
                {
                    if (str != "")
                    {
                        sum += stoi(str);
                        str = "";
                    }
                }
            }
            if (str != "")
            {
                sum += stoi(str);
                str = "";
            }
        }

        answer = max(answer, sum);
    }

    cout << answer;
}