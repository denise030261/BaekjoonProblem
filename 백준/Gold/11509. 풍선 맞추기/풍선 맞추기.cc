#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> v[i];
    }

    vector<int> top; 
    top.push_back(v[0]);


    for (int i = 1; i < v.size(); i++) 
    {
        bool success = false;
        for (int j = 0; j < top.size(); j++) 
        {
            if (top[j] - 1 == v[i]) 
            {
                success = true;
                top[j]--; 
                break;
            }
        }

        if (!success) 
        {
            top.push_back(v[i]);
        }
    }
    cout << top.size(); 
}