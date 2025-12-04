#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int team[20][20] = { 0, };
    int answer = INT_MAX;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> team[i][j];
        }
    }

    for (int i = 0; i < (1 << N); i++)
    {
        vector<int> links;
        vector<int> starts;

        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                links.push_back(j);
                //cout << "links " << j << '\n';
            }
            else
            {
                starts.push_back(j);
                //cout << "starts " << j << '\n';
            }
        }

        int link = 0;
        int start = 0;
        for (int j = 0; j < links.size(); j++)
        {
            for (int k = j + 1; k < links.size(); k++)
            {
                link += team[links[j]][links[k]];
                link += team[links[k]][links[j]];
            }
        }
        for (int j = 0; j < starts.size(); j++)
        {
            for (int k = j + 1; k < starts.size(); k++)
            {
                start += team[starts[j]][starts[k]];
                start += team[starts[k]][starts[j]];
            }
        }
        //cout << link << " : " << start << '\n';

        answer = min(answer, abs(link - start));
    }

    cout << answer;
}