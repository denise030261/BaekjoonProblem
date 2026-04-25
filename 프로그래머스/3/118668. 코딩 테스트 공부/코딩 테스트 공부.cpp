#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
// 문제를 푸는데 필요한 알고력, 문제를 푸는데 필요한 코딩력
// 문제를 풀었을 때 증가하는 알고력, 문제를 풀었을 때 증가하는 코딩력
// 문제를 푸는데 드는 시간
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = INT_MAX;
    int times[151][151]={0,};
    
    for(int i=0;i<=150;i++)
    {
        for(int j=0;j<=150;j++)
        {
            int cal_alp = (i-alp<=0)?0:i-alp;
            int cal_cop = (j-cop<=0)?0:j-cop;
            times[i][j] = cal_alp+cal_cop;
        }
    }
    
    // 풀 수 있는 문제
    for(int i=0;i<=150;i++)
    {
        for(int j=0;j<=150;j++)
        {
            if(i+1<=150) times[i+1][j] = min(times[i+1][j], times[i][j]+1);
            if(j+1<=150) times[i][j+1] = min(times[i][j+1], times[i][j]+1);
            
            for(int k=0;k<problems.size();k++)
            {
                int alp_req=problems[k][0];
                int cop_req=problems[k][1];
                int alp_rwd=problems[k][2];
                int cop_rwd=problems[k][3];
                int cost=problems[k][4];
                
                if(i<alp_req || j<cop_req) continue;
                
                int alp_value = i+alp_rwd>150?150:i+alp_rwd;
                int cop_value = j+cop_rwd>150?150:j+cop_rwd;
                times[alp_value][cop_value]=min(times[alp_value][cop_value], 
                    times[i][j]+cost);
            }
        }
    }
    
    int max_alp=0;
    int max_cop=0;
    for(int i=0;i<problems.size();i++)
    {
        int alp_req=problems[i][0];
        int cop_req=problems[i][1];
        max_alp=max(max_alp, alp_req);
        max_cop=max(max_cop, cop_req);
    }
    
    for(int i=max_alp;i<=150;i++)
    {
        for(int j=max_cop;j<=150;j++)
        {
            answer=min(answer, times[i][j]);
        }
    }
    
    return answer;
}