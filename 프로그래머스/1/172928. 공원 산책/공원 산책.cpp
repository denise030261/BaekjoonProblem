#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int row = park[0].length();
    int col = park.size();
    vector<int> curLoc;
    
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            if(park[i][j]=='S')
            {
                curLoc.push_back(i); // y
                curLoc.push_back(j); // x
            }
        }
    }
    
    for(int i=0;i<routes.size();i++)
    {
        int moves = routes[i][2]-'0';
        
        if(routes[i][0]=='E')
        {
            if(moves+curLoc[1]>=row)
            {
                continue;
            }
            else
            {
                bool isCorrect=true;
                for(int j=1;j<=moves;j++)
                {
                    if(park[curLoc[0]][j+curLoc[1]]=='X')
                    {
                        isCorrect = false;
                        break;
                    }
                }
                if(isCorrect)
                {
                    curLoc[1]+=moves;
                }
            }
        }
        else if(routes[i][0]=='W')
        {
            if(curLoc[1]-moves<0)
            {
                continue;
            }
            else
            {
                bool isCorrect=true;
                for(int j=1;j<=moves;j++)
                {
                    if(park[curLoc[0]][curLoc[1]-j]=='X')
                    {
                        isCorrect = false;
                        break;
                    }
                }
                if(isCorrect)
                {
                    curLoc[1]-=moves;
                }
            }
        }
        else if(routes[i][0]=='S')
        {
            if(curLoc[0]+moves>=col)
            { 
               continue;
            }
            else
            {
                bool isCorrect=true;
                for(int j=1;j<=moves;j++)
                {
                    if(park[curLoc[0]+j][curLoc[1]]=='X')
                    {
                        isCorrect = false;
                        break;
                    }
                }
                if(isCorrect)
                {
                    curLoc[0]+=moves;
                }
            }
        }
        else if(routes[i][0]=='N')
        {
            if(curLoc[0]-moves<0)
            {
                continue;
            }
            else
            {
                bool isCorrect=true;
                for(int j=1;j<=moves;j++)
                {
                    if(park[curLoc[0]-j][curLoc[1]]=='X')
                    {
                        isCorrect = false;
                        break;
                    }
                }
                if(isCorrect)
                {
                    curLoc[0]-=moves;
                }
            }
        }
    }
    answer=curLoc;
    return answer;
}