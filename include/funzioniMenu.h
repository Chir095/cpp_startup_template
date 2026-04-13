#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "Studente.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Menu
{
	public:
		Menu();
		int getNumeroVoci();
		void setNumeroVoci(int);
		void aggiungiVoce(const string &v);
		void stampaMenu();
		bool sceltaValida();
		void eseguiOperazione();
		void stampaLinea();
	private:
		string opzioni[10];			//VETTORE DELLE SCELTE
		int numeroVoci;				//ATTRIBUTO PER NUMERO VOCI
		int scelta;					//ATTRIBUTO PER MEMORIZZARE LA SCELTA ESEGUITA
		Studente s;
};



#endif
