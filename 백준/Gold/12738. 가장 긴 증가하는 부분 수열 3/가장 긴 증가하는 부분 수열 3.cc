#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	vector<int> arr;
	arr.push_back(v[0]);
	for (int i = 1; i < N; i++)
	{
		if (arr.back() < v[i])
		{
			arr.push_back(v[i]);
		}
		else
		{
			int start = 0;
			int end = arr.size()-1;
			int mid = -1;
			
			while (start < end)
			{
				mid = (start + end) / 2;
				if (arr[mid] >= v[i])
				{
					end = mid;
				}
				else
				{
					start = mid + 1;
				}
			}

			arr[end] = v[i];
		}
	}

	cout << arr.size();
}