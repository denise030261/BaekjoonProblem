#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

int solution(int n, vector<int> cores) {
    if (n <= cores.size()) 
        return n;

    // 0초에 모든 코어가 하나씩 가져가므로, n에서 코어 개수만큼 뺌
    n -= cores.size();

    int start = 1;
    // 최악의 경우: 가장 느린 코어(10,000)가 혼자 모든 작업(n)을 다 할 때
    long long end = 10000LL * n; 
    int time = 0;

    // 2. 이분 탐색으로 n개를 추가 처리할 수 있는 '최소 시간' 찾기
    while (start <= end) 
    {
        int mid = (start + end) / 2;
        long long sum = 0;

        for (int i = 0; i < cores.size(); i++) 
        {
            sum += (mid / cores[i]);
        }

        if (sum >= n) 
        {
            time = mid;
            end = mid - 1;
        } 
        else 
        {
            start = mid + 1;
        }
    }

    // 3. (time - 1)초까지 추가로 처리된 작업의 총합 구하기
    long long total_work = 0;
    for (int i = 0; i < cores.size(); i++) 
    {
        total_work += (time - 1) / cores[i];
    }

    // 4. time초에 새로 작업을 시작하는 코어들 중 n번째 찾기
    for (int i = 0; i < cores.size(); i++) 
    {
        if (time % cores[i] == 0) 
        {
            total_work++;
            if (total_work == n) return i + 1;
        }
    }

    return 0;
}