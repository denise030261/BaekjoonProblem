#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

vector<pair<double, double>> v;
int n;
double arr[100][100] = { 0, };
bool visited[100] = { 0, };
double answer = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    int index = 0;
    int minX = 2000;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        v.push_back({ x,y });
        
        if (minX > x)
        {
            index = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = sqrt(pow((v[i].first - v[j].first), 2) + pow((v[i].second - v[j].second), 2));
            //cout << arr[i][j] << ' ';
        }
        //cout << '\n';
    }

    priority_queue<pair<double, int>,vector<pair<double, int>>, greater<pair<double, int>>> pq;
    bool visited[100] = { 0, };
    pq.push({ 0,0 });

    while (!pq.empty())
    {
        double cost = pq.top().first;
        int current = pq.top().second;

        pq.pop();

        if (visited[current])
            continue;
    
        //cout << current << ' ' << cost << '\n';
        answer += cost;
        visited[current] = true;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                //cout << i << ' ' << arr[current][i] << '\n';
                pq.push({ (arr[current][i]),i });
            }
        }
        //cout << "-----------------\n";
    }

    cout << std::fixed << setprecision(2);
    cout << answer;
}