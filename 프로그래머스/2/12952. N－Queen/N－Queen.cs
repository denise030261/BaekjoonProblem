using System;

public class Solution {
    int answer = 0;
    int[] arr = new int[12]; // 어느 행에 배치되어있는지가 value값
    
    void Queen(int length, int row, int n)
    {
        if(length==n)
        {
            answer++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==-1)
            {
                bool possible=true;
                
                for(int j=0;j<n;j++)
                {
                    if(arr[j]==-1)
                    {
                        continue;
                    }
                    
                    if(Math.Abs(arr[j]-(length))==Math.Abs(i-j))
                    {
                        possible=false;
                        break;
                    }
                }
                
                if(!possible)
                    continue;
                
                arr[i]=length;
                Queen(length+1,i,n);
                arr[i]=-1;
            }
        }
    }
    
    public int solution(int n) {
        for(int i=0;i<n;i++)
        {
            arr[i]=-1;
        }
        
        for(int i=0;i<n;i++)
        {
            arr[i]=0;
            Queen(1,i,n);
            arr[i]=-1;
        }
        return answer;
    }
}