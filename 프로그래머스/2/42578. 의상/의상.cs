using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(string[,] clothes) {
        Dictionary<string,int> dic = new Dictionary<string,int>();
        List<int> valueList = new List<int>();
        int answer = 1;
        for(int i=0;i<clothes.GetLength(0);i++)
        {
            string cloth=clothes[i,0];
            string kind = clothes[i,1];
            
            if(dic.ContainsKey(kind))
            {
                dic[kind]++;
            }
            else
            {
                dic.Add(kind,1);
            }
        }
        
        valueList = dic.Values.ToList();
        
        for(int i=0;i<valueList.Count;i++)
        {
            answer*=valueList[i]+1;
        }
        answer--;
        
        return answer;
    }
}