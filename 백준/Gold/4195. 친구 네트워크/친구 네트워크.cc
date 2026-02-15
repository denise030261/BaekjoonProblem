#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<string, string> m;
map<string, int> answers;

string find(string str)
{
    if (m[str]==str)
    {
        return str;
    }

    return find(m[str]);
}

void Union(string str1, string str2)
{
    //cout << str1 << ' ' << str2 << " -> ";
    str1 = find(str1);
    str2 = find(str2);
    //cout << str1 << ' ' << str2 << " : ";
    //cout << answers[str1] << ' ' << answers[str2] << "\n";

    if (str1 < str2)
    {
        m[str2] = str1;
        answers[str1] += answers[str2];
        answers[str2] = answers[str1];
    }
    else if(str1>str2)
    {
        m[str1] = str2;
        answers[str2] += answers[str1];
        answers[str1] = answers[str2];
    }
    cout << answers[str1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    while (T != 0)
    {
        int F;
        m.clear();
        answers.clear();

        set<string> s;
        vector<pair<string, string>> v;
        cin >> F;
        for (int i = 0; i < F; i++)
        {
            string str1, str2;
            cin >> str1 >> str2;
            s.insert(str1);
            s.insert(str2);
            v.push_back({ str1,str2 });
        }

        for (string str : s)
        {
            m.insert({str,str});
            answers.insert({ str,1 });
        }
        
        for (int i = 0; i < v.size(); i++)
        {
            string str1 = v[i].first;
            string str2 = v[i].second;

            //cout << "Union 중\n";
            Union(str1, str2);

           // cout << max(answers[str1], answers[str2]) << '\n';
        }

        T--;
    }
}