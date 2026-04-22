using System;
using System.Collections.Generic;

public class Solution {
    bool[] visited = new bool[200];
    List<int>[] list = new List<int>[200];
    
    void dfs(int current)
    {
        foreach(int element in list[current])
        {
            if(!visited[element])
            {
                visited[element]=true;
                dfs(element);    
            }
        }
        /*for(int i=0;i<list[current].Length;i++)
        {
            int next = list[current][i];
            if(!visited[next])
            {
                visited[next]=true;
                dfs(next);    
            }
        }*/
    }
    
    public int solution(int n, int[,] computers) {
        int answer = 0;
        for(int i=0;i<n;i++)
        {
            list[i] = new List<int>();
            visited[i]=false;
            
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                
                int connect = computers[i,j];
                if(connect==1)
                {
                    list[i].Add(j);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                answer++;
                dfs(i);
            }
        }
        
        return answer;
    }
}