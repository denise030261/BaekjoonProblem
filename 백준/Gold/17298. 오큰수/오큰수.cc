#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int arr[1000001] = { 0, };
    int answer[1000001] = { 0, };
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;

        int order = pq.size();
        for (int j = 0; j < order; j++)
        {
            if (pq.top().first < num)
            {
                answer[pq.top().second] = num;
                pq.pop();
            }
            else
            {
                break;
            }
        }
        pq.push(make_pair(num, i));
    }

    for (int i = 1; i <= N; i++)
    {
        if (answer[i] != 0)
        {
            cout << answer[i] << ' ';
        }
        else
        {
            cout << -1 << ' ';
        }
    }
}