#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    int student[1001][6] = { 0 }; 
    int count[1001] = { 0 };      

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> student[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++) 
        {
            for (int k = 1; k <= 5; k++) 
            {
                if (student[i][k] == student[j][k])
                {
                    count[i]++;
                    count[j]++;
                    break; 
                }
            }
        }
    }

    int answer = 1;
    for (int i = 2; i <= N; i++) 
    {
        if (count[i] > count[answer]) 
        {
            answer = i;
        }
    }

    cout << answer << '\n';
}
