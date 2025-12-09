#include <iostream> 
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    char d;
    cin >> n >> d;

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        string str;
        str = to_string(i);
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == d)
            {
                answer++;
            }
        }
    }

    cout << answer;
}