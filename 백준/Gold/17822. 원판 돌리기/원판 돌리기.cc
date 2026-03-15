#include <iostream>
#include <vector>

using namespace std;

int N, M, T;
int arr[50][50] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 회전
    while (T != 0)
    {
        int x, d, k; // x : 배수, d : 방향 (0:시계, 1:반시계), k : 몇 칸
        cin >> x >> d >> k;
        for (int i = x-1; i < N; i += x)
        {
            int temp[50] = { 0, };
            for (int j = 0; j < M; j++)
            {
                int order = -1;
                if (d == 0)
                {
                    order = (j + k) % M;
                } // 반시계 방향
                else
                {
                    order = (j - (k % M) + M) % M;
                } // 시계 방향
                temp[order] = arr[i][j];
            }

            for (int j = 0; j < M; j++)
            {
                arr[i][j] = temp[j];
            }
        } // 회전 돌리기

        /*cout << "회전하기\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';*/

        // 인접한 수 없애기
        bool exist = false;
        bool visited[50][50] = { 0, };
        vector<pair<int, int>> v;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int next_x = i + dx[k];
                    int next_y = (j + dy[k]) < 0 ? M - 1 : (j + dy[k]) % M;

                    if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
                    {
                        if (arr[i][j] == arr[next_x][next_y] && arr[i][j]!=-1)
                        {
                            if (!visited[i][j])
                            {
                                visited[i][j] = true;
                                v.push_back({ i,j });
                            }
                            if (!visited[next_x][next_y])
                            {
                                visited[next_x][next_y] = true;
                                v.push_back({ next_x,next_y });
                            }
                            exist = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            int rem_x = v[i].first;
            int rem_y = v[i].second;

            arr[rem_x][rem_y] = -1;
        }

        float sum = 0;
        float minus = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (arr[i][j] == -1)
                {
                    minus++;
                    continue;
                }

                sum += arr[i][j];
            }
        }
        sum = sum / (N * M - minus);

        if (!exist) // 인접한 수가 없으면 평균보다 크면 -1, 작으면 +1
        {
            //cout << sum << " 인접한 수가 없습니다\n";
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (arr[i][j] == -1)
                    {
                        continue;
                    }

                    if (arr[i][j] > sum)
                    {
                        arr[i][j]--;
                    }
                    else if(arr[i][j]<sum)
                    {
                        arr[i][j]++;
                    }
                }
            }
        }
        /*cout << "인접한 수\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';*/
        T--;
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            //cout << arr[i][j] << ' ';
            if (arr[i][j] == -1)
            {
                continue;
            }

            answer += arr[i][j];
        }
       // cout << '\n';
    }

    cout << answer;
}