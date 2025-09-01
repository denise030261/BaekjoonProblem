#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visited[101][101]={0,};

int dfs(int x,int y, vector<string> maps)
{
    int sum=0;
    for(int i=0;i<4;i++)
    {
        int next_x=x+dx[i];
        int next_y=y+dy[i];
        if(next_x>=0&&next_x<maps.size() && next_y>=0 && next_y<maps[0].size())
        {
            if(!visited[next_x][next_y]&& maps[next_x][next_y]!='X')
            {
                visited[next_x][next_y]=true;
                sum+=dfs(next_x,next_y,maps)+maps[next_x][next_y]-'0'; 
            }
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(int i=0;i<maps.size();i++)
    {
        for(int j=0;j<maps[i].size();j++)
        {
            int sum=0;
            if(!visited[i][j] && maps[i][j]!='X')
            {
                visited[i][j]=true;
                sum=dfs(i,j,maps)+maps[i][j]-'0';
                answer.push_back(sum);
            }
        }
    }
    
    if(answer.empty())
        answer.push_back(-1);
    
    sort(answer.begin(), answer.end());
    return answer;
}