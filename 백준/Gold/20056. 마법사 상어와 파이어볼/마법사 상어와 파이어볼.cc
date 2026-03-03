#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

struct Feature {
    int mess;
    int speed;
    int direction;
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, K;
    queue<pair<int, Feature>> order; // 불 순서 
    queue<Feature> info[2500]; // 해당 인덱스(위치)에 대한 불 정보
    int map[50][50] = { 0, };
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        int index = (r - 1) * N + (c - 1);
        Feature feat = { m,s,d };

        info[index].push(feat);
        order.push({ index,feat });
    }

    while (K != 0)
    {
        while (!order.empty())
        {
            int index = order.front().first;
            int r = index / N;
            int c = index % N;

            Feature feat = order.front().second;
            order.pop();

            int m = feat.mess;
            int d = feat.direction;
            int s = feat.speed;

            info[index].pop();

            if (r + dx[d] * s < 0)
            {
                r = r + dx[d] * s;
                while (r < 0)
                {
                    r += N;
                }
            }
            else
            {
                r = (r + dx[d] * s) % N;
            }

            if (c + dy[d] * s < 0)
            {
                c = c + dy[d] * s;
                while (c < 0)
                {
                    c += N;
                }
            }
            else
            {
                c = (c + dy[d] * s) % N;
            }

            index = r * N + c;
            info[index].push(feat);

            //cout << index << '\n';
        } // 이동

        for (int i = 0; i < 2500; i++)
        {
            if (info[i].size() == 1)
            {
                order.push({ i,info[i].front() });
            }
            else if (info[i].size() != 0) // 공 4가지 분리
            {
                int total = info[i].size();
                int sum_mess = 0;
                int sum_speed = 0;
                int dir = -1;
                bool cur_even = true;
                bool even = true;

                while (!info[i].empty())
                {
                    Feature feat = info[i].front();
                    info[i].pop();

                    int m = feat.mess;
                    int d = feat.direction;
                    int s = feat.speed;

                    sum_mess += m;
                    sum_speed += s;
                    if (dir == -1)
                    {
                        if(d%2==0)
                        {
                            cur_even = true;
                        }
                        else
                        {
                            cur_even = false;
                        }
                        dir = d;
                    }
                    else if (!even)
                    {
                        continue;
                    }
                    else
                    {
                        if (((d % 2 == 0) && !cur_even) 
                            || ((d % 2 == 1) && cur_even))
                        {
                            even = false;
                        }
                        
                    }
                } // 합하는 과정

                if (sum_mess / 5 != 0)
                {
                    int m = sum_mess / 5;
                    int s = sum_speed / total;
                    int r = i / N;
                    int c = i % N;

                    int j = 0;
                    if (!even)
                    {
                        j = 1;
                    }

                    for (j; j < 8; j += 2)
                    {
                        Feature feat = { m,s,j };
                        info[i].push(feat);
                        order.push({ i,feat });
                    }
                } // 분해 과정
            }
        }

        K--;
    }

    int answer = 0;
    while (!order.empty())
    {
        int final_mess = order.front().second.mess;
        answer += final_mess;
        order.pop();
    }
    cout << answer;
}