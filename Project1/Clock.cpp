#include "Clock.h"

Clock::Clock()
{
	setTime(0, 0, 0);
}

Clock::Clock(int h, int m, int s)
{
	setTime(h,m,s);
}

void Clock::tick()
{

}

void Clock::printTime()
{
	cout <<setw(2)<<setfill('0')<< h << ':'
		<< setw(2) << setfill('0') << m << ':' 
		<< setw(2) << setfill('0') << s << endl;
}

void Clock::setTime(int h, int m, int s)
{
	this->h = (h < 0 || h>24) ? 0 : h;
	this->m = (m < 0 || m >= 60) ? 0 : m;
	this->s = (s < 0 || s >= 60) ? 0 : s;
}
