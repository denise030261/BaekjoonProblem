#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int path[101]={0,}; // 현재 경로
    int robots = routes.size(); // 로봇 개수
    vector<pair<int,int>> cur; // 현재 위치
    bool done[101]={0,};
    
    int map[101][101]={0,}; // 그 위치의 로봇 개수
    for(int i=0;i<routes.size();i++)
    {
        cur.push_back({points[routes[i][0]-1][0],points[routes[i][0]-1][1]});
        map[points[routes[i][0]-1][0]][points[routes[i][0]-1][1]]++;
        
    }
    
    while(robots!=0)
    {
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(map[i][j]>=2)
                {
                    answer++;
                }
            }
        }
        
        for(int i=0;i<cur.size();i++)
        {
            if(done[i])
            {
                map[cur[i].first][cur[i].second]--;
                pair<int,int> Init= {0,0};
                cur[i]=Init;
                continue;
            }
            
            map[cur[i].first][cur[i].second]--;
            if(cur[i].first-points[routes[i][path[i]+1]-1][0]<0)
            {
                pair<int,int> move = {cur[i].first+1,cur[i].second};
                cur[i]=move;
            } // i쪽이 음수
            else if(cur[i].first-points[routes[i][path[i]+1]-1][0]>0)
            {
                pair<int,int> move = {cur[i].first-1,cur[i].second};
                cur[i]=move;
            } // i쪽이 양수
            else if(cur[i].first-points[routes[i][path[i]+1]-1][0]==0)
            {
                if(cur[i].second-points[routes[i][path[i]+1]-1][1]<0)
                {
                    pair<int,int> move = {cur[i].first,cur[i].second+1};
                    cur[i]=move;
                } // j쪽이 음수
                else if(cur[i].second-points[routes[i][path[i]+1]-1][1]>0)
                {
                    pair<int,int> move = {cur[i].first,cur[i].second-1};
                    cur[i]=move;
                } // j쪽이 양수
            } // i쪽이 0일 때
            
            if(cur[i].first-points[routes[i][path[i]+1]-1][0]==0 &&
              cur[i].second-points[routes[i][path[i]+1]-1][1]==0)
            {
                path[i]++;
                if(path[i]==routes[i].size()-1)
                {
                    robots--;
                    done[i]=true;
                    map[cur[i].first][cur[i].second]++;
                    continue;
                }
            }
            
            map[cur[i].first][cur[i].second]++;
        }
    }
    
    
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(map[i][j]>=2)
                {
                    answer++;
                }
            }
        }
    
    return answer;
}