#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    bool composit[10000001] = { 0, };
    composit[1] = true;

    // 소수
    for (int i = 2; i <= N * 10 + 1; i++)
    {
        if (composit[i])
        {
            continue;
        }

        for (int j = 2; i * j <= N * 10 + 1; j++)
        {
            if (!composit[i * j])
            {
                composit[i * j] = true;
            }
        }
    }

    // 팰린드롬
    for (long long int i = N; i <= N * 10 + 1; i++)
    {
        //cout << i << " : " << composit[i] << '\n';
        if (!composit[i])
        {
            string str = to_string(i);
            string revStr = str;
            reverse(revStr.begin(), revStr.end());
            // << str << ' ' << revStr << '\n';
            if (str == revStr)
            {
                cout << str;
                return 0;
            }
        }
    }
}