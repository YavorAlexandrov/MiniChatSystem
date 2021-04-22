#pragma warning(disable : 4996)
#include "DateTime.h"
#include<iostream>
#include<fstream>
using namespace std;

DateTime::DateTime() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	setYear(ltm->tm_year+1900);
	setMonth(ltm->tm_mon+1);
	setDay(ltm->tm_mday);
	setHour(ltm->tm_hour);
	setMinute(ltm->tm_min);
	setSeconds(ltm->tm_sec);
}

void DateTime::monthToString(int month) const{
	
	switch (month)
	{
	case 1:cout << "January"; break;
	case 2:cout << "February"; break;
	case 3:cout << "March"; break;
	case 4:cout << "April"; break;
	case 5:cout << "May"; break;
	case 6:cout << "June"; break;
	case 7:cout << "July"; break;
	case 8:cout << "August"; break;
	case 9:cout << "September"; break;
	case 10:cout << "October"; break;
	case 11:cout << "November"; break;
	case 12:cout << "December"; break;

	default:
		break;
	}
	
}
void DateTime::monthToString(int month, ofstream& f) const {
	
	switch (month)
	{
	case 1:f << "January"; break;
	case 2:f << "February"; break;
	case 3:f << "March"; break;
	case 4:f << "April"; break;
	case 5:f << "May"; break;
	case 6:f << "June"; break;
	case 7:f << "July"; break;
	case 8:f << "August"; break;
	case 9:f << "September"; break;
	case 10:f << "October"; break;
	case 11:f << "November"; break;
	case 12:f << "December"; break;

	default:
		break;
	}

}
const char* DateTime::monthToString2(int month) const {
	char buff[12]{ "" };
	switch (month)
	{
	case 1:strcpy(buff,"January"); break;
	case 2:strcpy(buff, "February"); break;
	case 3:strcpy(buff, "March"); break;
	case 4:strcpy(buff, "April"); break;
	case 5:strcpy(buff, "May"); break;
	case 6:strcpy(buff, "June"); break;
	case 7:strcpy(buff, "July"); break;
	case 8:strcpy(buff, "August"); break;
	case 9:strcpy(buff, "September"); break;
	case 10:strcpy(buff, "October"); break;
	case 11:strcpy(buff, "November"); break;
	case 12:strcpy(buff, "December"); break;

	default:
		break;
	}
	return buff;
}

void DateTime::printTime() const{
	cout << day << '/';
	monthToString(month);
	cout<< '/' << year << ' ' << hours << ':' << minutes << ':' << seconds << endl;
}
void DateTime::printTime(ofstream& f) const {
	
	f << day << '/';
	monthToString(month, f);
	f << '/' << year << ' ' << hours << ':' << minutes << ':' << seconds << endl;
	
}

void DateTime::setYear(int year){
	this->year = year;
}
void DateTime::setMonth(int month){
	this->month = month;
}void DateTime::setDay(int day){
	this->day = day;
}
void DateTime::setHour(int hours){
	this->hours = hours;
}
void DateTime::setMinute(int min){
	this->minutes = min;
}
void DateTime::setSeconds(int sec){
	this->seconds = sec;
}

const char* DateTime::getTimeAsString() const{
	char buff[32] = { "" };
	char buff2[8] = { "" };
	strcat(buff, itoa(day, buff2, 10));
	strcat(buff, "/");
	strcat(buff, monthToString2(month));
	strcat(buff, "/");
	strcat(buff, itoa(year, buff2, 10));
	strcat(buff, "-");
	if (hours < 10)
		strcat(buff, "0");
	strcat(buff, itoa(hours, buff2, 10));
	strcat(buff, ":");
	if (minutes < 10)
		strcat(buff, "0");
	strcat(buff, itoa(minutes, buff2, 10));
	strcat(buff, ":");
	if (seconds < 10)
		strcat(buff, "0");
	strcat(buff, itoa(seconds, buff2, 10));
	strcat(buff, "\0");
	return buff;

}

