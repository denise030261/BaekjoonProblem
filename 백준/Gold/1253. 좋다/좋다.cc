#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> v;
bool visited[2000] = { 0, };
int N;
int answer = 0;

void search(int start, int end, int index)
{
    while (start < end && start>=0 && end<N)
    {
        int sum = v[start] + v[end];
        if (start == index)
        {
            start++;
            continue;
        }
        else if (end == index)
        {
            end--;
            continue;
        }

        if (sum == v[index])
        {
            answer++;
            return;
        }
        else if (sum > v[index])
        {
            end--;
        }
        else if (sum < v[index])
        {
            start++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        search(0, N - 1, i);
    }

    cout << answer;
}