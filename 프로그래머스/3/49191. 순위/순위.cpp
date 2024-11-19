#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> v(n+1,vector<bool>(n+1,false));
    
    for(int i=0;i<results.size();i++)
    {
        v[results[i][0]][results[i][1]]=true;
    }
    
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=n;k++)
            {
                if(v[i][j] && v[j][k])
                {
                    v[i][k]=true;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        int count=0;
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            if(v[i][j] || v[j][i])
                count++;
        }
        
        if(count==n-1)
        {
            answer++;
        }
    }
    
    return answer;
}