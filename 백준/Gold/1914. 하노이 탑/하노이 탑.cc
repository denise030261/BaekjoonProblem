#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void hanoi(int num, int start, int temp, int end)
{
	if (num == 1)
	{
		cout << start << ' ' << end << '\n';
		return;
	}

	hanoi(num - 1, start, end, temp);
	hanoi(1, start, temp, end);
	hanoi(num - 1, temp, start, end);
}

string add(string s1, string s2) 
{
    string result = "";
    int sum = 0;
    int size1 = s1.size();
    int size2 = s2.size();

    while (size1 > 0 || size2 > 0 || sum > 0) 
    {
        if (size1 > 0) {
            sum += s1[--size1] - '0';
        }
        if (size2 > 0) {
            sum += s2[--size2] - '0';
        }
        result += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int K;
	cin >> K;

    if (K <= 20) 
    {
        cout << (long long)pow(2, K) - 1 << '\n';
        hanoi(K, 1, 2, 3);
    }
    else 
    {
        string num = "2";
        for (int i = 1; i < K; ++i) 
        {
            num = add(num, num); 
        }

        int last_idx = num.length() - 1;
        num[last_idx] -= 1; 

        cout << num << '\n';
    }
}