#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


struct Node 
{
    map<string, Node> children;
};


void printTrie(Node& node, int depth) 
{
    for (auto& element : node.children) 
    {
        for (int i = 0; i < depth; i++)
        {
            cout << "--";
        }
        cout << element.first << '\n';


        printTrie(element.second, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    Node root;

    for (int i = 0; i < N; i++) 
    {
        int K;
        cin >> K;

        Node* currentNode = &root; 

        for (int j = 0; j < K; j++)
        {
            string food;
            cin >> food;

            currentNode = &(currentNode->children[food]);
        }
    }

    printTrie(root, 0);
}