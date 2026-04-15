#include "funzioniMenu.h"

int main() 
{
	Menu m;
	m.aggiungiVoce("INSERIMENTO");
	m.aggiungiVoce("STAMPA");
	m.aggiungiVoce("ORDINA ARRAY STUDENTE");
	m.aggiungiVoce("RICERCA ARRAY STUDENTE");
	m.aggiungiVoce("ELIMINA ARRAY STUDENTE");
	m.aggiungiVoce("ESCI");
	
	do
	{
		
		m.stampaMenu();
		m.eseguiOperazione();
		
	}while(m.sceltaValida());
	
	
	return 0;
}
