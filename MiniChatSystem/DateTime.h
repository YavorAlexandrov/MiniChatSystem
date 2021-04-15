#pragma once
#include<ctime>
class DateTime {
	int year;
	int month;
	int day;
	int hours;
	int minutes;
	int seconds;

	void monthToString(int month);
public:
	DateTime();
	void printTime();
	
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void setHour(int hour);
	void setMinute(int min);
	void setSeconds(int sec);
	void setPassword(const char* password);
	void setEmail(const char* email);
private:
	void setID(int id);
};
