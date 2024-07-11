#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    vector<string> arr(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    int length = arr[0].size();
    for (int k = 1; k <= length; k++)
    {
        bool isCorrect = true;
        for (int i = 0; i < N; i++)
        {
            string sub_i = arr[i].substr(length - k, k);
            for (int j = i + 1; j < N; j++)
            {
                string sub_j = arr[j].substr(length - k, k);
                if (sub_i == sub_j)
                {
                    isCorrect = false;
                    break;
                }
            }
            if (!isCorrect)
            {
                break;
            }
        }
        if (isCorrect) 
        {
            cout << k << '\n';
            return 0;
        }
    }
}
