using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[,] jobs) {
        int answer = 0;
        var pq = new SortedSet<(int,int,int)>(); // 작업 소요시간, 작업 요청시간, 작업 번호
        var arr = new List<(int,int,int)>();
        
        // 요청순으로 정렬
        for(int i=0;i<jobs.GetLength(0);i++)
        {
            int call = jobs[i,0];
            int cost = jobs[i,1];
            
            arr.Add((call, cost,i)); // 작업 요청시간,작업 소요시간,작업 번호
        }
        arr.Sort((a,b)=>a.Item1.CompareTo(b.Item1));
        
        pq.Add((arr[0].Item2, arr[0].Item1,arr[0].Item3)); // 작업 소요시간, 작업 요청시간, 작업 번호
        int total=0;
        int time=arr[0].Item1; // 첫 요청시간
        int idx=1;
        
        bool done=true;
        for(int i=idx;i<jobs.GetLength(0);i++)
        {
            if(time==arr[i].Item1)
            {
                pq.Add((arr[i].Item2, arr[i].Item1,arr[i].Item3));
            }
            else
            {
                done=false;
                idx=i;
                break;
            }
        }
        if(done)
        {
            idx=jobs.GetLength(0);
        }
        
        while(pq.Count>0)
        {
            int cost = pq.Min.Item1;
            int call = pq.Min.Item2;
            int num = pq.Min.Item3;
            pq.Remove(pq.Min);
            
            time=Math.Max(time,call);
            time+=cost;
            total+=time-call;
            Console.Write($"{cost} {call} {num}");
            done=true;
            for(int i=idx;i<jobs.GetLength(0);i++)
            {
                if(time>=arr[i].Item1)
                {
                    pq.Add((arr[i].Item2, arr[i].Item1,arr[i].Item3));
                }
                else if(i==idx && pq.Count==0)
                {
                    pq.Add((arr[i].Item2, arr[i].Item1,arr[i].Item3));
                }
                else
                {
                    done=false;
                    idx=i;
                    break;
                }
            }
            if(done)
            {
                idx=jobs.GetLength(0);
            }
        }
        
        answer=total/jobs.GetLength(0);
        
        return answer;
    }
}