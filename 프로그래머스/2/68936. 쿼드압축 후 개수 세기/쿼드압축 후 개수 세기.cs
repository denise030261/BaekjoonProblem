using System;

public class Solution {
    int [,] map = new int[1024,1024];
    int zero=0;
    int one=0;
    
    void DivConq(int size, int c, int r)
    {
        if(size==1)
        {
            if(map[c,r]==0)
            {
                zero++;
            }
            else
            {
                one++;
            }
            return;
        }
        
        bool possible=true;
        int init=-1;
        for(int i=c;i<c+size;i++)
        {
            if(!possible) break;
            
            for(int j=r;j<r+size;j++)
            {
                if(init==-1)
                {
                    init=map[i,j];
                }
                else if(init!=map[i,j])
                {
                    possible=false;
                    break;
                }
            }
        }
        
        if(possible)
        {
            if(init==1)
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        else
        {
            DivConq(size/2,c,r);
            DivConq(size/2,c+(size/2),r);
            DivConq(size/2,c,r+(size/2));
            DivConq(size/2,c+(size/2),r+(size/2));
        }
    }
    
    public int[] solution(int[,] arr) {
        int[] answer = new int[2];
        for(int i=0;i<arr.GetLength(0);i++)
        {
            for(int j=0;j<arr.GetLength(1);j++)
            {
                map[i,j] = arr[i,j];
            }
        }
        
        DivConq(arr.GetLength(0),0,0);
        answer[0]=zero;
        answer[1]=one;
        
        return answer;
    }
}