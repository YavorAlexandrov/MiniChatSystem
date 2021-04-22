#pragma once
#include<ctime>
#include<fstream>
class DateTime {
	int year;
	int month;
	int day;
	int hours;
	int minutes;
	int seconds;

	void monthToString(int month, std::ofstream& f) const;
	void monthToString(int month) const;
	const char* monthToString2(int month) const;
public:
	DateTime();
	void printTime() const;
	void printTime(std::ofstream& f) const;
	
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void setHour(int hour);
	void setMinute(int min);
	void setSeconds(int sec);

	const char* getTimeAsString() const;
	

	
};
