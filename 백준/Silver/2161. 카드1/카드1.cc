#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    deque<int> dq;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }

    while (!dq.empty())
    {
        int front = dq.front();
        dq.pop_front();
        cout << front << ' ';
        
        if (!dq.empty())
        {
            front = dq.front();
            dq.pop_front();
            dq.push_back(front);
        }
    }
}