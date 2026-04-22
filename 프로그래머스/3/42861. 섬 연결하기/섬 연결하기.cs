using System;
using System.Collections.Generic;

public class Solution {
    int[,] arr = new int[100,100];
    public int solution(int n, int[,] costs) {
        int answer = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i,j] = 987654321;
            }
            arr[i,i]=0;
        }
        
        for(int i=0;i<costs.GetLength(0);i++)
        {
            int start = costs[i,0];
            int end = costs[i,1];
            int cost = costs[i,2];
            
            arr[start,end]=cost;
            arr[end,start]=cost;
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    arr[i,j] = Math.Min(arr[i,j],arr[i,k]+arr[k,j]);
                }
            }
        }
        
        bool[] visited = new bool[100];
        var sd = new SortedSet<(int, int)>();
        sd.Add((0,0));
        while(sd.Count!=0)
        {
            int cost = sd.Min.Item1;
            int current =sd.Min.Item2;
            sd.Remove(sd.Min);
            
            if(visited[current])
            {
                continue;
            }
            visited[current]=true;
            answer+=cost;
            
            for(int i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    sd.Add((arr[current,i],i));
                }
            }
        }
        return answer;
    }
}