#include <iostream>

using namespace std;

int main() 
{
    int N;
    int arr[11] = { 0, };
    int answer[11] = { 0, };

    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) 
    {
        int plus = 0;
        for (int j = 1; j <= N; j++) 
        {
            if (arr[i] == plus && answer[j]==0)
            {
                answer[j] = i;
                break;
            }
            else if(answer[j] == 0)
            {
                plus++;
            }
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        cout << answer[i] << ' ';
    }
}
