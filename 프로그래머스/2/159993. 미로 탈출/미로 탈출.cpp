#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool visited[100][100]={0,};
priority_queue<pair<int,pair<int,int>>> pq;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M;

int bfs(pair<int,int> start, pair<int,int> end,vector<string> maps)
{
    int dis=987654321;
    pq.push({0,{start.first, start.second}});
    memset(visited,0,sizeof(visited));
    
    while(!pq.empty())
    {
        int x = pq.top().second.first;
        int y=pq.top().second.second;
        int sum = -pq.top().first;
        pq.pop();
        
        if(x==end.first && y==end.second)
        {
            dis=min(dis,sum);
            //return dis;
        }
        
        for(int i=0;i<4;i++)
        {
            int next_x = x+dx[i];
            int next_y=y+dy[i];
            
            if(next_x>=0 && next_x<N && next_y>=0 && next_y<M)
            {
                if(!visited[next_x][next_y] && maps[next_x][next_y] != 'X')
                {
                    pq.push({-(sum+1),{next_x, next_y}});
                    visited[next_x][next_y]=true;
                }
            }
        }
    }
    return dis;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    pair<int,int> lever;
    pair<int,int> s;
    pair<int,int> exit;
    for(int i=0;i<maps.size();i++)
    {
        for(int j=0;j<maps[i].size();j++)
        {
            if(maps[i][j]=='S')
            {
                s = {i,j};
            }
            else if(maps[i][j]=='L')
            {
                lever = {i,j};
            }
            else if(maps[i][j]=='E')
            {
                exit={i,j};
            }
        }
    }
    N=maps.size();
    M=maps[0].size();
  //  cout << s.first<< ' ' <<s.second<<'\n';
    //cout << lever.first<< ' ' <<lever.second<<'\n';
    //cout << exit.first<< ' ' <<exit.second<<'\n';
    
    visited[s.first][s.second]=true;
    int sum = bfs(s,lever,maps);
    if(sum==987654321)
        {return -1;}
    else
       { answer+=sum;}
    //cout << sum<<'\n';
    
    sum=bfs(lever,exit,maps);
    if(sum==987654321)
        {return -1;}
    else
        {answer+=sum;}
    //cout << sum;
    
    return answer;
}