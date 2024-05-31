#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	string bomb;
	string answer = "";
	bool isLoop = true;

	cin >> str;
	cin >> bomb;

	int check = 0;
	int i = 0;
	int strnum = str.length();
	int bombnum = bomb.length();

    for (int i = 0; i < str.length(); i++)
    {
        answer += str[i]; 
        if (answer.length() >= bombnum) { 
            bool isCheck = true; 
            for (int j = 0; j < bombnum; j++) {
                if (answer[answer.length() - bombnum + j] != bomb[j]) {
                    isCheck = false;
                    break;
                } 
            }

            if (isCheck)
                answer.erase(answer.end() - bombnum, answer.end());
        }
    }

    if (answer.empty()) 
        cout << "FRULA" << '\n';
    else
        cout << answer << '\n';
}