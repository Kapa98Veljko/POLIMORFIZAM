#include "ClockWithDate.h"
#include<iomanip>
#include<iostream>
using namespace std;

ClockWithDate::ClockWithDate():Clock()
{
	setDate(1950,1,1);
}

ClockWithDate::ClockWithDate(int y, int m, int d) :Clock()
{
	setDate(y, m, d);

}

ClockWithDate::ClockWithDate(int y, int m, int d, int hh, int mm, int ss):Clock(hh,mm,ss)
{
	setDate(y,m,d);
}

void ClockWithDate::tick()
{

	Clock::tick();
	//So now i ticked one secunde and now i need to check if the time is 23:59:59 this is when i need to change date so i would need to check should i change month and yeat in that instance
	//How the fuck i get the things from base class
	//Easy shit because i marked the m,s,h as protected so i can access them from child class
	if (s == 0 && m == 0 && h == 0) {
		//uvecao sam dan
		day++;
		//uvecao sam mesec
		switch (month) {
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			if (day > 31) { day = 1; month++; }
			break;
		case 4:case 6:case 9:case 11:

			if (day > 30) { day = 1; month++; }
			break;
			//treba ispitati da li je godina prestupna
		case 2:
			//ako je jebena prestupna
			if (year % 400 == 0 || (year && 4 == 0 && year % 100 != 0)) {
				if (day > 29) { day = 1; month++; }
			}
			else
				if (day > 28) { day = 1; month++; }
			break;
		
		}
		if (month > 12) { month = 1; year++; }
		if (year > 2099) { year = 1950; }
	}

}

void ClockWithDate::printTime()
{
	cout << year << ':' << setw(2) << setfill('0') << month <<':'<<
		setw(2) << setfill('0') << day << ' ';
	Clock::printTime();
	
}

void ClockWithDate::setDate(int y,int m,int d)
{
	month = (m<=12&&m>=1) ? m: 1;
	year = (y>=1950 && y<=2099) ? y : 1950;
	
	switch (month) {
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		day = (d >= 1 && d <= 31) ? d : 1;
		break;
	case 4:case 6:case 9:case 11:

		day = (d >= 1 && d <= 30) ? d : 1;
		break;
		//treba ispitati da li je godina prestupna
	case 2:
		if (year % 400 == 0 || (year && 4 == 0 && year % 100 != 0)) {
			day = (d >= 1 && d <= 28) ? d : 1;
		}
		else
			day = (d >= 1 && d <= 29) ? d : 1;
		break;
	}
}
