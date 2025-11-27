#include <iostream>
#include <queue>
#include <string>

using namespace std;

int Left(int num)
{
    num *= 10;
    int one = num / 10000;
    num %= 10000;
    num += one;
    return num;
}

int Right(int num)
{
    int one = num % 10;
    num /= 10;
    num += one * 1000;
    return num;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T != 0)
    {
        int a, b;
        cin >> a >> b;
        queue<pair<int, string>> q;
        bool visited[10000] = { 0, };
        visited[a] = true;
        q.push({ a,"" });

        while (!q.empty())
        {
            int num = q.front().first;
            string str = q.front().second;
            //cout << "current : " << num << ' ' <<str << '\n';
            q.pop();

            if (num == b)
            {
                cout << str << '\n';
                break;
            }

            int cal = num * 2 % 10000;
            if(!visited[num * 2 % 10000])
            {
                visited[cal] = true;
                q.push({ cal,str.append("D")});
                str.pop_back();
            }

            cal = num - 1 < 0 ? 9999 : num - 1;
            if (!visited[cal])
            {
                visited[cal] = true;
                q.push({ cal,str.append("S")});
                str.pop_back();
            }

            cal = Left(num);
            if (!visited[cal])
            {
                visited[cal] = true;
                q.push({ cal, str.append("L")});
                str.pop_back();
            }

            cal = Right(num);
            if (!visited[cal])
            {
                visited[cal] = true;
                q.push({ cal,str.append("R") });
                str.pop_back();
            }
        }
        T--;
    }
}