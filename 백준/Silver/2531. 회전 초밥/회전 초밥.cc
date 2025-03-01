#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, d, k, c; // 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
    cin >> N >> d >> k >> c;

    vector<int> sushi(N);
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }

    unordered_map<int, int> sushiCount;  
    int kindCount = 0; 
    int maxCount = 0;

    for (int i = 0; i < k; i++) {
        if (sushiCount[sushi[i]] == 0) kindCount++;  
        sushiCount[sushi[i]]++;
    }

    if (sushiCount[c] == 0) maxCount = kindCount + 1;
    else maxCount = kindCount;

    for (int i = 1; i < N; i++) {
        int removeIdx = i - 1;  
        int addIdx = (i + k - 1) % N;  

        // 초밥 제거
        sushiCount[sushi[removeIdx]]--;
        if (sushiCount[sushi[removeIdx]] == 0) kindCount--;  

        // 초밥 추가
        if (sushiCount[sushi[addIdx]] == 0) kindCount++;  
        sushiCount[sushi[addIdx]]++;

        if (sushiCount[c] == 0) maxCount = max(maxCount, kindCount + 1);
        else maxCount = max(maxCount, kindCount);
    }

    cout << maxCount;
    return 0;
}
