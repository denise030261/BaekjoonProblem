using System;
using System.Collections.Generic;

public class Solution {

    public int solution(int distance, int[] rocks, int n) {
        int answer=0;
        int start=1;
        int end=distance;
        Array.Sort(rocks);
        
        while(start<=end)
        {
            int mid=(start+end)/2;
            int removeRock=0;
            int current=0;
            
            foreach(int rock in rocks)
            {
                if(rock-current<mid)
                {
                    removeRock++;
                }
                else
                {
                    current=rock;
                }
            }
            if(distance-current<mid)
                {
                    removeRock++;
                }
            
            if(removeRock<=n)
            {
                answer=Math.Max(mid, answer);
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return answer;
    }
}