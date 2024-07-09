#include <iostream>

using namespace std;

int main() 
{
    int N;
    int arr[11] = { 0, };
    int answer[11] = { 0, };

    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) 
    {
        int plus = 0;
        for (int j = 0; j < N; j++) 
        {
            if (arr[i] == plus) 
            {
                if (!answer[j]) 
                {
                    answer[j] = i + 1;
                    break;
                }
            }
            else 
            {
                if (!answer[j]) 
                {
                    plus++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) 
    {
        cout << answer[i] << ' ';
    }
}
