#include <iostream>
#include <map>

using namespace std;

int main() {
    int A_Size, B_Size;
    cin >> A_Size >> B_Size;
    map<int,int> m;

    for(int i=0;i<A_Size;i++)
        {
            int num;
            cin >> num;
            m[num]++;
        }

    for(int i=0;i<B_Size;i++)
        {
            int num;
            cin >> num;
            m.erase(num);
        }

    cout << m.size() << '\n';
    for (auto iter = m.begin() ; iter !=  m.end(); iter++)
	{
		cout << iter->first<<' ';
    }
    return 0;
}