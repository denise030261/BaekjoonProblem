#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    vector<int> height(N + 1);
    vector<int> answers(N + 1);
    stack<int> st;

    for (int i = 1; i <= N; i++) 
    {
        cin >> height[i];
    }

    for (int i = 1; i <= N; i++) 
    {
        while (!st.empty() && height[st.top()] <= height[i]) 
        {
            st.pop();
        }

        if (st.empty()) 
        {
            answers[i] = 0;
        }
        else 
        {
            answers[i] = st.top();
        }

        st.push(i);
    }

    for (int i = 1; i <= N; i++) 
    {
        cout << answers[i] << ' ';
    }
}
