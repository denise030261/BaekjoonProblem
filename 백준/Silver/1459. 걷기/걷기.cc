#include <iostream> 
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int X, Y, W, S;
    cin >> X >> Y >> W >> S;

    long long int answer = abs(X + Y) * W;
    answer = min(answer, min(X, Y) * S + ((max(X, Y)-min(X,Y)) * W));
    if ((X + Y) % 2 == 0)
    {
        answer = min(answer, max(X,Y) * S);
    }
    else
    {
        answer = min(answer, (max(X, Y)-1) * S + W);
    }
    
    cout << answer;
}