using System;
using System.Collections.Generic;

public class Solution {
    public string solution(string number, int k) {
        string answer = "";
        var st = new Stack<int>();
        foreach(var c in number)
        {
            int num = c-'0';
            
            if(st.Count==0)
            {
                st.Push(num);
            }
            else if(st.Peek()<num && k!=0)
            {
                while(st.Peek()<num && k!=0)
                {
                    st.Pop();
                    k--;
                    
                    if(st.Count==0)
                        break;
                }
                st.Push(num);
            }
            else
            {
                st.Push(num);
            }
        }
        
        while(k>0)
        {
            st.Pop();
            k--;
        }
        
        char[] answers = new char[st.Count];
        int count = st.Count;
        for (int i = count - 1; i >= 0; i--) 
        {
            answers[i] = (char)(st.Pop() + '0');
        }

        return new string(answers);
    }
}