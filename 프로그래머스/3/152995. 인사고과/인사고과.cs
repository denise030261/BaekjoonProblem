using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
public class Solution {
    public int solution(int[,] scores) {
        int answer = 0;
        // scores[0]은 완호의 점수이다.
        var v = new List<(int, int, bool)>();
        v.Add((scores[0,0], scores[0,1],true));
        for(int i=1;i<scores.GetLength(0);i++)
        {
            v.Add((scores[i,0], scores[i,1],false));
        } // 완호임을 나타내기
        
        v.Sort((a, b) => { if(a.Item1==b.Item1) return a.Item2.CompareTo(b.Item2);
           return b.Item1.CompareTo(a.Item1);});
        
        int maxPerson = v[0].Item2;
        var incentive = new List<(int,bool)>();
        incentive.Add(((v[0].Item1+maxPerson),v[0].Item3));
        for(int i=1;i<v.Count;i++)
        {
            int work = v[i].Item1;
            int person = v[i].Item2;
            bool oneho = v[i].Item3;
            
            if(maxPerson<=person)
            {
                incentive.Add(((work+person),oneho));
            } // 인센티브 받음
            else if(oneho)
            {
                return -1;
            }
            maxPerson = Math.Max(maxPerson,person);
        }
        
        incentive.Sort((a, b) => b.Item1.CompareTo(a.Item1));
        
        int grade=1;
        int score=-1;
        for(int i=0;i<incentive.Count;i++)
        {
            int total = incentive[i].Item1;
            bool oneho = incentive[i].Item2;
            
            if(score!=total)
            {
                grade = i+1;
            }
            score=total;
            
            if(oneho)
            {
                answer=grade;
                break;
            }
        }
        
        return answer;
    }
}