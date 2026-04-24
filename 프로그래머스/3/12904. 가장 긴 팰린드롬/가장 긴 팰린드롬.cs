using System;

public class Solution {
    public int solution(string s) {
        int answer = 0;

        for(int i=0;i<s.Length;i++)
        {
            int sum=1;
            for(int j=1;j<s.Length;j++)
            {
                int next =i+j;
                int pre=i-j;
                
                if(next<s.Length && pre>=0)
                {
                    if(s[next]==s[pre])
                    {
                        sum+=2;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            answer=Math.Max(answer,sum);
        }
        
        for(int i=0;i<s.Length-1;i++)
        {
            if(s[i]!=s[i+1]) continue;
            
            int sum=2;
            for(int j=1;j<s.Length;j++)
            {
                int next =i+j+1;
                int pre=i-j;
                
                if(next<s.Length && pre>=0)
                {
                    if(s[next]==s[pre])
                    {
                        sum+=2;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            answer=Math.Max(answer,sum);
        }
        return answer;
    }
}