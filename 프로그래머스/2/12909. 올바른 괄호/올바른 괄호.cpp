#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==')')
        {
            if(st.empty())
            {
                answer=false;
                return answer;
            }
            else
            {
                st.pop();   
            }
        }
        else
        {
            st.push('(');
        }
    }
    
    if(st.empty())
    {
        answer=true;
    }
    else
    {
        answer=false;
    }
    return answer;
}