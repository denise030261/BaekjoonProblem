#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<pair<int,int>> A;
	vector<pair<int,int>> B;
	int N, M, num;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A.push_back({ num,i });
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		B.push_back({ num,i });
	}
	
	sort(A.begin(), A.end(), compare);
	sort(B.begin(), B.end(), compare);

	vector<int> answer;
	int index_a = 0, index_b = 0, end_a = 0, end_b = 0;
	while (index_a < N && index_b < M)
	{
		if (A[index_a].first == B[index_b].first)
		{
			if (end_a > A[index_a].second)
				index_a++;
			else if (end_b > B[index_b].second)
				index_b++;
			else
			{
				end_a = A[index_a].second;
				end_b = B[index_b].second;
				answer.push_back(A[index_a].first);
				index_a++;
				index_b++;
			}
		}
		else if (A[index_a].first > B[index_b].first)
			index_a++;
		else
			index_b++;
	}

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << ' ';
	}
}