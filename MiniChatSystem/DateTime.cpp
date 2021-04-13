#pragma warning(disable : 4996)
#include "DateTime.h"
#include<iostream>
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

void DateTime::monthToString(int month) {
	
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

void DateTime::printTime() {
	cout << day << '/';
	monthToString(month);
	cout<< '/' << year << ' ' << hours << ':' << minutes << ':' << seconds << endl;
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
