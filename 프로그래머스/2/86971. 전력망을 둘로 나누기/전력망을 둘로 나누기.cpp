#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> v[101];
bool visited[101]={0,};

int dfs(int current)
{
    int sum=1;
    for(int i=0;i<v[current].size();i++)
    {
        if(!visited[v[current][i]])
        {
            visited[v[current][i]]=true;
            sum+=dfs(v[current][i]);
            //cout << v[current][i]<<' '<<sum<<'\n';
        }
    }
    return sum;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    for(int i=0;i<wires.size();i++)
    {
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i=0;i<wires.size();i++)
    {
        v[wires[i][0]].erase(remove(v[wires[i][0]].begin(),v[wires[i][0]].end(),wires[i][1]), 
                             v[wires[i][0]].end());
        v[wires[i][1]].erase(remove(v[wires[i][1]].begin(),v[wires[i][1]].end(),wires[i][0]), 
                             v[wires[i][1]].end());
        //cout << wires[i][0] << ' '<<wires[i][1]<<" -> "<<'\n';
        memset(visited, 0,sizeof(visited));
        visited[1]=true;
        int nodes = dfs(1);
        //cout << n-nodes<<'\n';
        answer=min(answer,abs((n-nodes)-nodes));
        
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    return answer;
}