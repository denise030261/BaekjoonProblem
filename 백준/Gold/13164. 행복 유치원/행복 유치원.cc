#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long int N, K;
    vector<long int> v;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        long int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    vector<long int> diff;
    for (int i = 0; i < v.size() - 1; i++)
    {
        long int result = v[i + 1] - v[i];
        diff.push_back(result);
    }

    sort(diff.begin(), diff.end());

    long int answer = 0;
    for (int i = 0; i < diff.size()-(K-1); i++)
    {
        answer += diff[i];
    }
    cout << answer;
}

