#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    int MAX = 10000005;
    int area[201][201]={0,};
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            area[i][j]=MAX;
        }
        area[i][i]=0;
    }
    
    for(int i=0;i<fares.size();i++)
    {
        int first = fares[i][0];
        int second = fares[i][1];
        int cost = fares[i][2];
        
        area[first][second] = min(area[first][second], cost);
        area[second][first] = min(area[second][first], cost);
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                area[i][j] = min(area[i][j], area[i][k]+area[k][j]);
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        answer=min(answer,area[s][i]+area[i][a]+area[i][b]);
    }
    
    answer=min(answer,area[s][a]+area[s][b]);
    return answer;
}