#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int timeToMinutes(const string& time) 
{
    vector<string> parts;
    stringstream ss(time);
    string part;

    while (getline(ss, part, ':')) 
    {
        parts.push_back(part);
    }

    return stoi(parts[0]) * 60 + stoi(parts[1]);
}

int solution(vector<vector<string>> book_time) {
    vector<int> timeLine; 
    sort(book_time.begin(), book_time.end());

    for (const auto& booking : book_time) {
        int startTime = timeToMinutes(booking[0]);
        int endTime = timeToMinutes(booking[1]) + 10;

        bool assigned = false;

        for (size_t i = 0; i < timeLine.size(); ++i) 
        {
            if (timeLine[i] <= startTime) 
            {
                timeLine[i] = endTime;
                assigned = true;
                break;
            }
        }

        if (!assigned) 
        {
            timeLine.push_back(endTime);
        }
    }

    return timeLine.size();
}