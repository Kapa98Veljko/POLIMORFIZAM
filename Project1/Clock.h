#ifndef CLOCK
#define CLOCK

#include<iostream>
#include<string>
using namespace std;

class Clock {

public:
	Clock();
	Clock(int h, int m, int s);

	//Kljucna rec virtual omogucava redefiniciju  metodam koje ce biti koriscene u izvedenim klasama
	virtual void tick();
	virtual void printTime();
	void setTime(int h,int m,int s);

	//protected oznacava da su polja tu navedena polja kojima ce biti omogucen pristup iz izvedenih klasa
protected:
	int h, m, s;
};

#endif CLOCK