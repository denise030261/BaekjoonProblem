#include <iostream> 
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    int answer = n / 5;
    int num = n % 5;

    while (answer>=0)
    {
        if (num % 2 == 0)
        {
            answer += num / 2;
            break;
        }
        else
        {
            answer--;
            num += 5;
        }
    }

    if (answer == 0)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}