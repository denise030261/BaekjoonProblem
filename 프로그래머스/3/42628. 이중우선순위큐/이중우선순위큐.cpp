#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms; // 중복 허용하며 정렬되는 컨테이너
    for (const string& op : operations) {
        if (op[0] == 'I') {
            // "I 숫자" 명령어에서 숫자 추출
            int num = stoi(op.substr(2));
            ms.insert(num);
        } else if (!ms.empty()) { // D 1 또는 D -1 명령어
            if (op == "D 1") {
                // 최댓값 삭제
                ms.erase(--ms.end());
            } else if (op == "D -1") {
                // 최솟값 삭제
                ms.erase(ms.begin());
            }
        }
    }

    if (ms.empty()) {
        return {0, 0};
    } else {
        // 최댓값: *--ms.end(), 최솟값: *ms.begin()
        return {*--ms.end(), *ms.begin()};
    }
}