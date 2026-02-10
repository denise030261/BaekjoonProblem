#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int N, M, L, K;
    cin >> N >> M >> L >> K;
    
    vector<pair<int, int>> stars(K);
    for (int i = 0; i < K; i++)
    {
        cin >> stars[i].first >> stars[i].second;
    }
    
    int maxCaught = 0;
    
    // 모든 별 쌍에 대해 트램펄린 위치 시도
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            // 트램펄린의 왼쪽 아래를 (stars[i].first, stars[j].second)로 설정
            int x = stars[i].first;
            int y = stars[j].second;
            
            int count = 0;
            // 이 위치에서 잡을 수 있는 별의 개수 계산
            for (int k = 0; k < K; k++)
            {
                if (x <= stars[k].first && stars[k].first <= x + L &&
                    y <= stars[k].second && stars[k].second <= y + L)
                {
                    count++;
                }
            }
            maxCaught = max(maxCaught, count);
        }
    }
    
    // 튕겨낼 수 밖에 없는 별의 개수
    cout << K - maxCaught;
    
    return 0;
}