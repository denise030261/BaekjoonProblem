#include <iostream> 
#include <set> 
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    set<string> s;
    vector<pair<string, string>> v;

    s.insert("ChongChong");
    string dance = "ChongChong";
    for (int i = 0; i < N; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        
        for (auto name : s)
        {
            if (str1 == name)
            {
                s.insert(str2);
                break;
            }
            else if (str2 == name)
            {
                s.insert(str1);
                break;
            }
        }
    }
    cout << s.size();
}