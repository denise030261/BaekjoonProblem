#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n,m;
char map[52][52]={0,};
char nextMap[52][52]={0,};
bool visited[52][52]={0,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void crain(int x,int y, string str)
{
    if(map[y][x]==str[0])
    {
        cout << "y : " << y << ", x : " << x << " => "<<map[y][x]<<' '<<str[0]<<'\n';
        nextMap[y][x]=' ';   
        for(int i=0;i<4;i++)
        {
            int next_x=x+dx[i];
            int next_y=y+dy[i];
            
            if(next_x>=0 && next_x < m && next_y>=0 && next_y<n)
            {
                if(map[next_y][next_x]==str[1])
                {
                    nextMap[next_y][next_x]=' ';  
                    //cout << "y : " << y << ", x : " << x << " => "<<map[y][x]<<' '<<str[1]<<'\n';
                }
            }
        }
    }
}

void folk(int x,int y, char c)
{
    for(int i=0;i<4;i++)
    {
        int next_x=x+dx[i];
        int next_y=y+dy[i];
        
        if(next_x>=0&& next_x<=m+1 && next_y>=0 && next_y<=n+1)
        {
            if(!visited[next_y][next_x])
            {
                visited[next_y][next_x]=true;
                if(map[next_y][next_x]==c)
                {
                   // cout << "y : " << y << ", x : " << x << " => "<<map[next_y][next_x]<<' '<<c<<'\n';
                    nextMap[next_y][next_x]=' ';
                }
                else if(map[next_y][next_x]==' ')
                {
                    folk(next_x,next_y,c);   
                }   
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    n=storage.size();
    m=storage[0].length();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            map[i+1][j+1]=storage[i][j];
            nextMap[i+1][j+1]=map[i+1][j+1];
            answer++;
        }
    }
    for(int i=0;i<=m+1;i++)
    {
        map[0][i]=' ';
        map[n+1][i]=' ';
    }
    for(int i=0;i<=n+1;i++)
    {
        map[i][0]=' ';
        map[i][m+1]=' ';
    }
    
    for(int i=0;i<requests.size();i++)
    {
        if(requests[i].length()==1)
        {
            visited[0][0]=true;
            folk(0,0,requests[i][0]);
            visited[0][0]=false;
        }
        else
        {
            for(int p=1;p<=n;p++)
            {
                for(int q=1;q<=m;q++)
                {
                    crain(q,p,requests[i]);
                }
            }
        }
        fill_n(visited[0],52*52,0);
        
        for(int p=1;p<=n;p++)
        {
            for(int q=1;q<=m;q++)
            {
                map[p][q]=nextMap[p][q];
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(nextMap[i][j]==' ')
                answer--;
        }
    }
    
    return answer;
}