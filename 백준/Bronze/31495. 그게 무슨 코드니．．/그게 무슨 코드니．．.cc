#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; 
    getline(cin, str); 
    
    if (str[0] == '"' && str[str.length() - 1] == '"' && str.length()>=3)
    {
        str.pop_back();
        str.erase(0,1);
        cout << str;
    }
    else
    {
        cout << "CE";
    }
}