using System;
using System.Collections.Generic;

public class Solution {
    bool[,] arr = new bool[101,101];
    bool[,] visited = new bool[101,101];
    int[] dx = new int[4]{0,0,1,-1};
    int[] dy = new int[4]{1,-1,0,0};
    
    public int solution(int[,] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;
        for(int i=0;i<rectangle.GetLength(0);i++)
        {
            int firstX = rectangle[i,0];
            int firstY = rectangle[i,1];
            int secondX = rectangle[i,2];
            int secondY = rectangle[i,3];
            
            for(int j=firstX*2;j<=secondX*2;j++)
            {
                for(int k=firstY*2;k<=secondY*2;k++)
                {
                    arr[j,k]=true;
                }
            }
        }
        
        // 테두리 맞추기
        for(int i=0;i<rectangle.GetLength(0);i++)
        {
            int firstX = rectangle[i,0];
            int firstY = rectangle[i,1];
            int secondX = rectangle[i,2];
            int secondY = rectangle[i,3];
            
            for(int j=firstX*2+1;j<=secondX*2-1;j++)
            {
                for(int k=firstY*2+1;k<=secondY*2-1;k++)
                {
                    arr[j,k]=false;
                }
            }
        }
        
        var s = new SortedSet<(int dist,int x,int y)>();
        s.Add((0,characterX*2,characterY*2));
        visited[characterX*2,characterY*2]=true;
        while(s.Count>0)
        {
            var current = s.Min;
            int cur_dist = current.dist;
            int cur_x = current.x;
            int cur_y = current.y;
            s.Remove(s.Min);
            
            if(cur_x==itemX*2 && cur_y==itemY*2)
            {
                answer=cur_dist;
                break;
            }
            
            for(int i=0;i<4;i++)
            {
                int next_x=cur_x+dx[i];
                int next_y=cur_y+dy[i];
                
                if(next_x>0 && next_x<=100 && next_y>0 && next_y<=100)
                {
                    if(!visited[next_x,next_y] && arr[next_x,next_y])
                    {
                        s.Add((cur_dist+1, next_x,next_y));
                        visited[next_x,next_y]=true;
                    }
                }
            }
        }
        answer/=2;
        return answer;
    }
}