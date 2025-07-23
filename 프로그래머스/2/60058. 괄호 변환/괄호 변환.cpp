#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool judge(string str)
{
    stack<char> st;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            st.push('(');
        }
        else if(str[i]==')' && !st.empty())
        {
            st.pop();
        }
        else if(str[i]==')' && st.empty())
        {
            return false;
        }
    }
    
    if(!st.empty())
        return false;
    else
        return true;
}

string solution(string p) {
     if (p=="") 
     {
        return "";
    }
    
    string answer="";
    int left=0;
    int right=0;
    string u="";
    string v="";
    for(int i=0;i<p.length();i++)
    {
        if('('==p[i])
        {
            left++;
        }
        else
        {
            right++;
        }

        u+=p[i];
        if(left==right)
        {
            break;
        }
    }
    v=p.substr(u.length());
        
    if(judge(u))
    {
        v=solution(v);
        answer=u+v;
        return answer;
    }
    else
    {
        answer+="("+solution(v)+")";
        for(int i=1;i<u.size()-1;i++)
        {
            if(u[i]=='(')
                answer+=')';
            else
                answer+='(';
        }
        return answer;
    }
    
    return answer;
}