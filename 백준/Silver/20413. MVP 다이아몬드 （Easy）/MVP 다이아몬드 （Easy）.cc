#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    vector <int> grade(4);
    string str;
    cin >> N;
    vector <int> answers(N + 1);

    for (int i = 0; i < 4; i++) 
    {
        cin >> grade[i];
    }
    cin >> str;

    for (int i = 0; i < N; i++) 
    {
        if (str[i] == 'B') 
        {
            answers[i + 1] = grade[0] - 1 - answers[i];
        }
        else if (str[i] == 'S') 
        {
            answers[i + 1] = grade[1] - 1 - answers[i];
        }
        else if (str[i] == 'G')
        {
            answers[i + 1] = grade[2] - 1 - answers[i];
        }
        else if (str[i] == 'P') 
        {
            answers[i + 1] = grade[3] - 1 - answers[i];
        }
        else 
        {
            answers[i + 1] = grade[3];
        }

    }
    int sum = 0;
    for (int i = 0; i < N + 1; i++) 
    {
        sum += answers[i];
    }
    std::cout << sum;
}
