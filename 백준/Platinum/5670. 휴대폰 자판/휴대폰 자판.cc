#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

double answer = 0;

struct Node {
	map<char, Node> children;
};

void dfs(Node& node,int depth)
{
	int num = node.children.size();

	for (auto& element : node.children)
	{
		if (element.first == '*')
		{
			//cout << depth << '\n';
			answer += depth;
		}
		else if (num == 1)
		{
			dfs(element.second, depth);
		}
		else
		{
			dfs(element.second,depth+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cout << fixed;
	double N;
	while (cin >> N)
	{
		answer = 0;
		Node root;
		Node* current;
		char first = ' ';
		//cin >> N;
		for (int i = 0; i < N; i++)
		{
			current = &root;
			string str;
			cin >> str;

			first = str[0];
			for (int j = 0; j < str.length(); j++)
			{
				current = &(current->children[str[j]]);
			}
			current = &(current->children['*']);
		}

		if (root.children.size() == 1)
		{
			dfs(root.children[first], 1);
		}
		else
		{
			dfs(root, 0);
		}
		cout << answer/N<< '\n';
	}

	return 0;
}
