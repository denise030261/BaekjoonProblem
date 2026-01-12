#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string str;
        cin >> str;

        int one = 0;
        int zero = 0;
        bool correct = true;
        for (int j = str.length() - 1; j >= 0; j--)
        {
            if (str[j] == '0')
            {
                if (zero == 0 && one == 0)
                {
                    correct = false;
                    break;
                }

                zero++;
            }
            else
            {
                if (zero == 1 && one == 1)
                {
                    zero = 0;
                    one = 0;
                }
                else if (one >= 2 && zero == 1)
                {
                    correct = false;
                    break;
                }
                else if (one >= 1 && zero >= 2)
                {
                    zero = 0;
                    one = 0;
                    continue;
                }

                one++;
            }
        }

        if (one == 1 && zero == 1)
        {
            correct = true;
        }
        else if (one != 0 || zero != 0)
        {
            correct = false;
        }

        if (correct)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}