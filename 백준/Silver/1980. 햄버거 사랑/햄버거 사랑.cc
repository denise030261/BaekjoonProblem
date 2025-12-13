#include <iostream> 
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, t;
    cin >> n >> m >> t;

    int hamburger = 0, coke = 0;
    
    int shr = min(n, m);
    int log = 0;
    if (shr==n)
    {
        log = m;
    }
    else
    {
        log = n;
    }

    int answer_ham = -1, answer_coke = INT_MAX;
    for (int i = 0; i <= t / m; i++)
    {
        int sum = 0;
        int time = t;

        if (i != 0)
        {
            sum += i;
        }
        time -= i * m;
        sum += time / n;
        time -= (time / n)*n;
        if ((answer_coke > time) || answer_coke == time && answer_ham < sum)
        {
            answer_ham = sum;
            answer_coke = time;
        }
    }

    cout << answer_ham << ' ' << answer_coke;
}