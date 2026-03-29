#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool correct(int start, int end, string str)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }

        start++; end--;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string str;
        cin >> str;

        int end = str.length() - 1;
        int start = 0;
        
        int circle = 0;
        while (start<end && circle!=2)
        {
            if (str[start] != str[end])
            {
                if (circle == 1)
                {
                    circle = 2;
                    break;
                }// 또 틀림

                bool possible = false;
                if (str[start] == str[end - 1] && !possible)
                {
                    if(correct(start+1,end-2,str))
                    {
                        possible = true;
                        end--;
                        circle = 1;
                        break;
                    }
                }
                if (str[start + 1] == str[end] && !possible)
                {
                    if (correct(start + 2, end - 1, str))
                    {
                        possible = true;
                        start++;
                        circle = 1;
                        break;
                    }
                }
                
                if(!possible)
                {
                    circle = 2;
                }
            }

            start++; end--;
        }
        cout << circle << '\n';
    }
}
