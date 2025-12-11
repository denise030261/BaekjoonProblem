#include <iostream> 
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int P;
    cin >> P;
    for (int i = 0; i < P; i++)
    {
        int T;
        cin >> T;

        deque<int> d;
        for (int j = 0; j < 20; j++)
        {
            int num;
            cin >> num;
            d.push_back(num);
        }

        int answer = 0;
        vector<int> v;
        v.push_back(d.front());
        d.pop_front();
        while (!d.empty())
        {
            if (v.back() > d.front())
            {
                int change = d.front();
                d.pop_front();
                while (!v.empty())
                {
                    if (v.back() > change)
                    {
                        answer++;
                        d.push_front(v.back());
                        v.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                v.push_back(change);
            }
            else
            {
                v.push_back(d.front());
                d.pop_front();
            }
        }

        cout << T << ' ' << answer << '\n';
    }
}