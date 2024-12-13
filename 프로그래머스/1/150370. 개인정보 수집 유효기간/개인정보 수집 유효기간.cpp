#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string calculateExpirationDate(string date, int termMonths) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2)) - 1; 

    if (day <= 0) {
        day += 28;
        month--;
    }

    if (month <= 0) {
        month += 12;
        year--;
    }

    month += termMonths;
    if (month > 12) {
        year += month / 12;
        month %= 12;
        if (month == 0) {
            month = 12;
            year--;
        }
    }

    string strYear = to_string(year);
    string strMonth = (month < 10 ? "0" : "") + to_string(month);
    string strDay = (day < 10 ? "0" : "") + to_string(day);

    return strYear + "." + strMonth + "." + strDay;
}

bool isExpired(const string& today, const string& expirationDate) {
    if (stoi(today.substr(0, 4)) > stoi(expirationDate.substr(0, 4)))
        return true;
    if (stoi(today.substr(0, 4)) < stoi(expirationDate.substr(0, 4)))
        return false;

    if (stoi(today.substr(5, 2)) > stoi(expirationDate.substr(5, 2)))
        return true;
    if (stoi(today.substr(5, 2)) < stoi(expirationDate.substr(5, 2)))
        return false;

    return stoi(today.substr(8, 2)) > stoi(expirationDate.substr(8, 2));
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    unordered_map<char, int> termMap;
    for (const string& term : terms) {
        char type = term[0];
        int duration = stoi(term.substr(term.find(" ") + 1));
        termMap[type] = duration;
    }

    for (int i = 0; i < privacies.size(); i++) {
        string date = privacies[i].substr(0, 10);
        char type = privacies[i].back();

        string expirationDate = calculateExpirationDate(date, termMap[type]);

        if (isExpired(today, expirationDate)) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}