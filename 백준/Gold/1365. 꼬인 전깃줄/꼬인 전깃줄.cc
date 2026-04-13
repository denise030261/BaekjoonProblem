#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int arr[100001] = { 0, };
    vector<int> v;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        arr[num] = i;
    }

    v.push_back(arr[1]);
    for (int i = 2; i <= N; i++)
    {
        if (v[v.size() - 1] < arr[i])
        {
            v.push_back(arr[i]);
            continue;
        }
       
        int start = 0;
        int end = v.size();
        int replace = 0;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (v[mid] > arr[i])
            {
                replace = mid;
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        v[replace] = arr[i];
    }

    cout << N - v.size();
}