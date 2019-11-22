#ifndef CLOCK_WITH_DATE
#define CLOCK_WITH_DATE
//MORA SE NAVESTI KLASA IZ KOJE SE IZVODI!!!
#include"Clock.h"
class ClockWithDate:public Clock {
public:
	ClockWithDate();
	ClockWithDate(int y,int m,int d);
	ClockWithDate(int y, int m, int d, int hh, int mm, int ss );
	virtual void tick() override;
	virtual void printTime() override;
	void setDate(int y, int m, int d);
private:
	int day, month, year;
};
#endif CLOCK_WITH_DATE