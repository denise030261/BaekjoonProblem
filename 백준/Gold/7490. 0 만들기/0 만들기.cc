#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <set>

using namespace std;

int N;
set<string> answer;

void dfs(stack<char> s, int num)
{
    if (num - 1 == N)
    {
        string str = "";
        
        int sum = 0;
        int temp = 0;
        int num = 0;
        int length = 0;
        while (!s.empty())
        {
            char c = s.top();
            str += c;
            s.pop();

            if (c == '+')
            {
                num += pow(10, length) * temp;
                sum += num;
                temp = 0;
                num = 0;
                length = 0;
            }
            else if (c == '-')
            {
                num += pow(10, length) * temp;
                sum -= num;
                temp = 0;
                num = 0;
                length = 0;
            }
            else if (c == ' ')
            {
                num += pow(10, length) * temp;
                temp = 0;
                length++;
            }
            else
            {
                temp += c - '0';
            }
        }
        num += pow(10, length) * temp;
        sum += num;

        if (sum == 0)
        {
            reverse(str.begin(), str.end());
            answer.insert(str);
        }

        return;
    }


    s.push('+'); s.push(num + '0');
    dfs(s, num + 1);
    s.pop(); s.pop();
    
    s.push('-'); s.push(num + '0');
    dfs(s, num + 1);
    s.pop(); s.pop();

    s.push(' '); s.push(num + '0');
    dfs(s, num + 1);
    s.pop(); s.pop();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        answer.clear();
        cin >> N;
        stack<char> s;
        s.push('1');
        dfs(s, 2);
    
        for (string element : answer)
        {
            cout << element << '\n';
        }
        cout << '\n';
    }
}

