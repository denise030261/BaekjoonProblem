#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool canReach(int x1, int y1, int x2, int y2) 
{
    return abs(x1 - x2) + abs(y1 - y2) <= 1000;
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> locations(n + 2); 
        vector<bool> visited(n + 2, false);     

        for (int i = 0; i < n + 2; i++) 
        {
            cin >> locations[i].first >> locations[i].second;
        }

        queue<int> q;
        q.push(0);           
        visited[0] = true;

        bool isHappy = false;

        while (!q.empty()) 
        {
            int current = q.front();
            q.pop();

            if (current == n + 1) 
            {
                isHappy = true;
                break;
            }

            for (int i = 0; i < n + 2; i++) 
            {
                if (!visited[i] && canReach(locations[current].first, locations[current].second, locations[i].first, locations[i].second)) 
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        cout << (isHappy ? "happy" : "sad") << '\n';
    }
}