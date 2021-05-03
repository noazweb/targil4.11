/*noa zwebner 324989714*/
#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Clock
{
	int hour = 0;
	int min = 0;
	int sec = 0;
public:
	Clock();
	Clock(int, int, int);
	Clock(int);
	Clock(const Clock&);
	int getHour();
	int getMin();
	int getSec();
	void setHour(int);
	void setMin(int);
	void setSec(int);
	void operator+=(int);
	friend ostream& operator<<(ostream& os, Clock num);
	friend istream& operator>>(istream& is, Clock num);
};

