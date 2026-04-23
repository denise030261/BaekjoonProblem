using System;
using System.Collections.Generic;

class Solution
{
    public int solution(int[] sticker)
    {
        int answer = 0;
        int N=sticker.Length;
        var sum0 = new int[N]; // 맨 앞 스티커 뜯는 경우
        var sum1 = new int[N]; // 맨 앞 스티커 뜯지 않은 경우
        
        sum0[0] = sticker[0];
        if(N==1)
        {
            return sum0[0];
        }
        sum0[1] = sum0[0];
        sum1[1] = sticker[1];
        answer=Math.Max(sum0[1],sum1[1]);
        
        for(int i=2;i<sticker.Length;i++)
        {
             if(i == sticker.Length-1)
             {
                 sum1[i] = Math.Max(sum1[i-1], sum1[i-2]+sticker[i]);
                 answer=Math.Max(sum0[i-1],sum1[i]);
                 break;
             } // 맨 마지막은 sum1만
            
            sum0[i] = Math.Max(sum0[i-1], sum0[i-2]+sticker[i]);
            sum1[i] = Math.Max(sum1[i-1], sum1[i-2]+sticker[i]);
            answer=Math.Max(sum0[i],sum1[i]);
        }
        
        return answer;
    }
}