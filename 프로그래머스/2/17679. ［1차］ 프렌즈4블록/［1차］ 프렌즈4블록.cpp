#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    bool keep=true;
    while(keep)
    {
        keep=false;
        vector<pair<int,int>> v;
        for(int i=0;i<m-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if((board[i][j]==board[i][j+1]) && (board[i][j]==board[i+1][j])
                  && (board[i][j]==board[i+1][j+1]) && board[i][j]!='x')
                {
                    v.push_back({i,j});
                    v.push_back({i,j+1});
                    v.push_back({i+1,j});
                    v.push_back({i+1,j+1});
                    keep=true;
                }
            }
        }
        
        for(int i=0;i<v.size();i++)
        {
            int x = v[i].first;
            int y=v[i].second;
            board[x][y]='x';
        }
        
        /*for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        
        cout << "---------------------------------------\n\n";*/
        
        for(int i=0;i<n;i++)
        {
            queue<int> q;
            for(int j=m-1;j>=0;j--)
            {
                if(board[j][i]=='x')
                {
                    q.push(j);
                }
                else if(!q.empty())
                {
                    int drop = q.front();
                    q.pop();
                    board[drop][i]=board[j][i];
                    board[j][i]='x';
                    q.push(j);
                }
            }
        }
        
        /*for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        
        cout << "---------------------------------------\n\n";*/
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='x')
                answer++;
        }
    }
    
    return answer;
}