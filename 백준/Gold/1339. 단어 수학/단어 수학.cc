#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int arr[26] = { 0, };
    int num[26] = { 0, };
    vector<pair<int, int>> v; // 자릿수의 값, 알파벳 위치의 값
    vector<string> strs;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        strs.push_back(str);
        reverse(str.begin(), str.end());
        int ten = 1;
        for (int j = 0; j < str.length(); j++)
        {
            arr[str[j] - 'A'] += ten;
            ten *= 10;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            v.push_back({ arr[i],i });
        }
    }
    sort(v.begin(), v.end(),greater<>());
    
    int loc = 9;
    for (int i = 0; i < v.size(); i++)
    {
        num[v[i].second] = loc;
        loc--;
    }

    int answer = 0;
    for (int i = 0; i < strs.size(); i++)
    {
        int ten = 0;
        for (int j = 0; j < strs[i].length(); j++)
        {
            ten = pow(10, strs[i].length() - j - 1);
            answer += ten * num[strs[i][j] - 'A'];
        }
    }
    cout << answer;
}