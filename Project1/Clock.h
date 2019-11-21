#ifndef CLOCK
#define CLOCK

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Clock {

public:
	Clock();
	Clock(int h, int m, int s);

	virtual void tick();
	virtual void printTime();
	void setTime(int h,int m,int s);
protected:
	int h, m, s;
};

#endif CLOCK