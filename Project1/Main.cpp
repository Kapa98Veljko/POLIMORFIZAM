#include"Clock.h"
#include"ClockWithDate.h"

#include<iostream>

using namespace std;

int main() {

	Clock* pClk1 = new Clock(12, 30, 0);
	Clock* pClk2 = new Clock();

	ClockWithDate* pClk3 = new ClockWithDate();
	ClockWithDate* pClk4 = new ClockWithDate(2019, 10, 28);
	// Pravilo supstitucije: Pokazivac na osnovnu klasu moze da pokazuje na objekat izvedene klase
	// Odnosno postoji implicitna konverziija ClockWithDate* -> Clock*
	Clock* pClk5 = new ClockWithDate(2019, 10, 28, 16, 24, 0);

	// Zbog tog pravila mozemo u jedinstvenom nizu pokazivaca na podatke osnovne klase cuvati objekte bilo koje izvedene klase
	// Ovaj niz pokazivaca na Clock sadrzi 2 objekta tipa Clock i 3 objekta tipa ClockWithDate
	Clock* clocks[] = { pClk1, pClk2, pClk3, pClk4, pClk5 };

	// Pozivom neke metode koje je oznacena sa virtual preko pokazivaca osnovne klase (Clock*) pozivamo onu implementaciju metode koja odgovara pokazivanom objektu - POLIMORFIZAM
	// Na ovaj nacin mozemo jednostavnim prolaskom kroz niz i pozivom metode printTime ispisati vremena, odnosno datum i vreme svih objekata u nizu
	// Implementacija metode koja se poziva se bira u trenutku izvrsavanja na osnovu tipa objekta na koji pokazuje dati pokazivac
	for (int i = 0; i < 5; i++) clocks[i]->printTime();

	delete pClk1;
	delete pClk2;
	delete pClk3;
	delete pClk4;
	delete pClk5;

	return 0;


}