#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	map<string, int> m;
	m["January"] = 1;
	m["February"] = 2;
	m["March"] = 3;
	m["April"] = 4;
	m["May"] = 5;
	m["June"] = 6;
	m["July"] = 7;
	m["August"] = 8;
	m["September"] = 9;
	m["October"] = 10;
	m["November"] = 11;
	m["December"] = 12;
	string month;
	string day;
	string time;
	string hour="";
	string minute="";
	int year=0;
	int dayInt;
	int hourInt;
	int minuteInt;
	int monthleap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int monthstandard[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int monthsum = 0;
	double total = 0;

	cin >> month >> day >> year >> time;
	day.pop_back();
	dayInt = stoi(day);
	hour += time[0]; hour += time[1];
	minute += time[3]; minute += time[4];
	hourInt = stoi(hour);
	minuteInt = stoi(minute);

	double all = 0;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		for (int i = 1; i < m[month]; i++)
		{
			monthsum += monthleap[i - 1];
		}
		total = (monthsum + abs(1 - dayInt)) * 24 * 60 + abs(0 - hourInt) * 60 + abs(0 - minuteInt);
		all = 366 * 24 * 60;
	}
	else
	{
		for (int i = 1; i < m[month]; i++)
		{
			monthsum += monthstandard[i - 1];
		}
		total = (monthsum + abs(1 - dayInt)) * 24 * 60 + abs(0 - hourInt) * 60 + abs(0 - minuteInt);
		all = 365 * 24 * 60;
	}
	cout.precision(10);
	cout << (total / all) * 100;
}