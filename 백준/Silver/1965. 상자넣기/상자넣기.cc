#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    int arr[1000] = { 0, };
    int sum[1000] = { 0, };
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum[i] = 1;
    }

    int answer = sum[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                sum[i] = max(sum[i], sum[j] + 1);
                answer = max(sum[i], answer);
            }
        }
    }

    cout << answer;
}