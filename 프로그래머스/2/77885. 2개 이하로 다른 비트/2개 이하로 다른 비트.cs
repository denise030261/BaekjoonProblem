using System;
using System.Collections.Generic;

public class Solution {
    public long[] solution(long[] numbers) {
        long[] answers = new long[numbers.Length] ;
        
        for(int i=0;i<numbers.Length;i++)
        {
            long number = numbers[i];
            
            if(number%2==0)
            {
                answers[i] = number+1;
            }
            else
            {
                int index=0;
                while((number&(1L<<index))!=0)
                {
                    index++;
                }
                number |= 1L<<index;
                number &= ~(1L<<(index-1));
                answers[i] = number;
            }
        }
        return answers;
    }
}