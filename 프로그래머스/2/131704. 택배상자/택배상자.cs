using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] order) {
        int answer = 0;
        int current=1;
        int boxes = order.Length;
        Stack<int> st = new Stack<int>();
        
        for(int i=0;i<order.Length;i++)
        {
            int box = order[i];
            bool input=false;
            
            if(st.Count!=0)
            {
                if(st.Peek()==box)
                {
                    answer++;
                    st.Pop();
                    input=true;
                }
            }
            if(input) continue;
            
            for(int j=current;j<=boxes;j++)
            {
                if(box!=j)
                {
                    st.Push(j);
                } // 보조 컨테이너에 넣기
                else
                {
                    input=true;
                    current = j+1;
                    answer++;
                    break;
                }
            }
            if(!input) break;
        }
        return answer;
    }
}