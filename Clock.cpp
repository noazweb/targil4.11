/*noa zwebner 324989714*/
#include "Clock.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
Clock::Clock() {     //default constractor
	hour = 0;
	min = 0;
	sec = 0;
}
Clock::Clock(int h = 0, int m = 0, int s = 0) {   //constractor 
	hour = h;
	min = m;
	sec = s;
}
Clock::Clock(int h) {     //constractor
	hour = h;
}
Clock::Clock(const Clock& p) {     //copy-constractor
	hour = p.hour;
	min = p.min;
	sec = p.sec;
}
int Clock::getHour() {
	return hour;
}
int Clock::getMin() {
	return min;
}
int Clock::getSec() {
	return sec;
}
void Clock::setHour(int h) {
	if (h > 23)    //in case the hours are too big
		throw string("Invalid time - more than 24 hours.\n");
	if (h < 0)     //in case the hours are negative
		throw string("Invalid time - negative number of hours.\n");
}

void Clock::setMin(int m) {
	if (m > 59)      //in case the minutes are too big
		throw string("Invalid time - more than 60 minutes.\n");
	if (m < 0)     //in case the minutes are negative
		throw string("Invalid time - negative number of minutes.\n");
}
void Clock::setSec(int s) {
	if (s > 59)     //in case the seconds are too big
		throw string("Invalid time - more than 60 seconds.\n");
	if (s < 0)    //in case the seconds are negative
		throw string("Invalid time - negative number of seconds.\n");
}
ostream& operator<<(ostream& os, Clock r)
{
	if (r.hour < 10)      //we need 2 digits
		os << "0" << r.hour << ":";
	else
		os << r.hour << ":";
	if (r.min < 10)     //we need 2 digits
		os << "0" << r.min << ":";
	else
		os << r.min << ":";
	if (r.sec < 10)     //we need 2 digits
		os << "0" << r.sec << endl;
	else
		os << r.sec << endl;

	return os;
}
istream& operator>>(istream& is, Clock r)
{
	char c;
	if (r.hour > 23 || r.hour < 0 || r.min>59 || r.min < 0 || r.sec>59 || r.sec < 0)
		throw string("Wrong time format.\n");   //in case the time is Invalid
	is >> r.hour >> c >> r.min >> c >> r.sec;
	return is;
}
void Clock::operator+=(int r) {
	int sub = r;
	sec = sec + r;
	if (sec > 59) {     //in case we need to promote the minutes
		sub = sec / 60;
		min += sub;
		sec = sec - (sub * 60);
	}
	if (min > 59) {  //in case we need to promote the hours
		sub = min / 60;
		hour += sub;
		min = min - (sub * 60);
	}
	if (hour > 23)   //in case the time is Invalid
		throw string("Wrong time format.\n");
}