#include <iostream> 
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    bool arr[101];
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1)
        {
            for (int j = num; j <= N; j += num)
            {
                arr[j] = !arr[j];
            }
        } // 남학생
        else
        {
            arr[num] = !arr[num];
            for (int j = 1; j <= N / 2; j++)
            {
                int front = num - j;
                int back = num + j;

                if (front <= 0 || back > N)
                {
                    break;
                }

                if (arr[front] == arr[back])
                {
                    arr[front] = !arr[front];
                    arr[back] = !arr[back];
                }
                else
                {
                    break;
                }
            }
        } // 여학생
    }

    for (int i = 1; i <= N; i++)
    {
        cout << (int)arr[i] << ' ';
        
        if (i % 20 == 0)
        {
            cout << '\n';
        }
    }
}