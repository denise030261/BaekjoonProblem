#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, K;
    cin >> t;
    while (t!=0)
    {
        cin >> n >> K;
        vector<int> v;
        int answer = 0;
        int diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());

        int start = 0;
        int end = v.size() - 1;
        while (start < end)
        {
            if (diff > abs(K-(v[start] + v[end])))
            {
                diff = abs(K - (v[start] + v[end]));
                answer = 1;
            }
            else if (diff == abs(K - (v[start] + v[end])))
            {
                answer++;
            }

            if (v[start] + v[end] > K)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        cout << answer << '\n';
        t--;
    }
}