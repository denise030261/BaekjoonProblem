using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution {
    int[] dx = new int[4]{1,0,0,-1};
    int[] dy = new int[4]{0,-1,1,0};
    string[,] arr_str = new string[50,50];
    int target_x=0;
    int target_y=0;
    int bound_x=0;
    int bound_y=0;
    string answer = "";
    
    void dfs(int cur_x, int cur_y, int k, StringBuilder str)
    {
        if (answer != "") return;

        int dist = Math.Abs(cur_x - target_x) + Math.Abs(cur_y - target_y);
        int remains = k - str.Length;
        if (dist > remains || (remains - dist) % 2 != 0) return;

        if (remains == 0)
        {
            answer = str.ToString();
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= 0 && next_x < bound_x && next_y >= 0 && next_y < bound_y)
            {
                char dir = i == 0 ? 'd' : i == 1 ? 'l' : i == 2 ? 'r' : 'u';

                str.Append(dir);            
                dfs(next_x, next_y, k, str); 
                str.Remove(str.Length - 1, 1); 
            }
        }
    }
    
    public string solution(int n, int m, int x, int y, int r, int c, int k) {
        x--; y--; r--; c--;
        bound_x=n;
        bound_y=m;
        target_x=r;
        target_y=c;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr_str[i,j]="";
            }
        }
        
        StringBuilder sb = new StringBuilder();
        dfs(x,y,k,sb);
        
        if(answer=="")
        {
            answer="impossible";
        }

        return answer;
    }
}