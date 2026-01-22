#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() //크기가 작고 색이 다른 공
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    vector<pair<pair<int, int>, int>> v;
    int answer[200001] = { 0, };
    int sums[200001] = { 0, };
    bool visited[200001] = { 0, };
    int total = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int color, size;
        cin >> color >> size;
        v.push_back({ {-size,color},i });

        sums[color] += size;
        total += size;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        int size = -v[i].first.first;
        int color = v[i].first.second;
        int index = v[i].second;

        //cout << index << " : " << total << ' ' << sums[color] << ' ' << size << ' ';
        int next = 0;
        while (i+next<N)
        {
            if (-v[i + next].first.first != size)
            {
                break;
            }

            if (-v[i + next].first.first == size && !visited[i+next])
            {
                visited[i + next] = true;
                int nextColor = v[i + next].first.second;
                total -= size;
                sums[nextColor] -= size;
                next++;
            }
            else
            {
                break;
            }
        }

        answer[index] = total - sums[color];
        //cout << answer[index] << '\n';
    }

    for (int i = 0; i < N; i++)
    {
        cout << answer[i] << '\n';
    }
}