#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    cin >> str;

    int one = 0;
    int zero = 0;
    bool possible = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
        {
            if (one >= 2 && zero >= 2)
            {
                if (one == 2 && i + 1 < str.length())
                {
                    if (str[i + 1] == '1')
                    {
                        one = 0;
                        zero = 1;
                    }
                    else
                    {
                        //cout << i << " : error\n";
                        possible = false;
                        break;
                    }
                }
                else if (one > 2 && i + 1 < str.length())
                {
                    if (str[i + 1] == '1')
                    {
                        one = 0;
                        zero = 1;
                    }
                    else
                    {
                        one = 1;
                        zero = 1;
                    }
                }
                else
                {
                    //cout << i << " : error\n";
                    possible = false;
                    break;
                }
            }
            else if ((one == 0 && zero == 0) || one >= 1)
            {
                zero++;
            }
            else
            {
                //cout << i << " : error\n";
                possible = false;
                break;
            }
        } // 0일 때
        else
        {
            if ((one >= 1 && zero >= 2) || (one == 0 && zero == 0))
            {
                one++;
            }
            else if (zero == 1 && one == 0)
            {
                zero = 0;
                one = 0;
            }
            else
            {
               // cout << i << " : error\n";
                possible = false;
                break;
            }
        } // 1일 때
    }

    //cout << zero << ' ' << one << '\n';
    if (!((zero == 1 && one == 1) || (one >= 2 && zero >= 2) || (one==0 && zero==0)))
    {
        //cout << "?";
        possible = false;
    }

    if (possible)
    {
        cout << "SUBMARINE";
    }
    else
    {
        cout << "NOISE";
    }
}