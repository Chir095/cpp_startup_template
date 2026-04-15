#include "funzioniMenu.h"
#include <cstdlib>

//DEFINIZIONE COSTRUTTORE DI DEFAULT
Menu::Menu()
{
	numeroVoci = 0;
	scelta=0;
}

//DEFINIZIONE METODO PER STAMPA DI UNA LINEA
void Menu::stampaLinea()
{
	for(int i=0;i<=50;i++)
		cout<<"-";
	cout<<endl;
}

//DEFINIZIONE FUNZIONE GETTER PER NUMERO VOCI
int Menu::getNumeroVoci()
{
	return numeroVoci;
}
//DEFINIZIONE FUNZIONE SETTER PER NUMERO VOCI
void Menu::setNumeroVoci(int n)
{
	numeroVoci=n;
}

//DEFINIZIONE METODO PER AGGIUNGERE VOCE AL MENU
void Menu::aggiungiVoce(const string &voce)
{
	
	if(numeroVoci<10)
		opzioni[numeroVoci++]=voce;
	else
	   cout<<"HAI RAGGIUNTO IL NUMERO MASSIMO DI VOCI"<<endl;
}

//DEFINIZIONE METODO PER LA STAMPA DEL MENU
void Menu::stampaMenu()
{
	for(int i=0;i<numeroVoci;i++)
	   cout<<"["<<i+1<<"]"<<opzioni[i]<<endl;
	do
	{
		cout<<"FAI LA TUA SCELTA: ";
		cin>>scelta;
	  	// Controlla se l'input Ã¨ valido
         if (cin.fail()) 
         {
            cin.clear(); // Ripristina lo stato di cin
            cin.ignore(1000, '\n'); // Scarta l'input non valido
            cout << "DEVI INSERIRE UN NUMERO "<< endl;
            scelta = -1; // Imposta scelta a un valore non valido per ripetere il ciclo
         }
    } while (scelta < 0); // Condizione: scelta deve essere >= 0 (ad esempio)
    
}
//DEFINIZIONE METODO PER LA CONVALIDA DELLA SCELTA EFFETTUATA
bool Menu::sceltaValida()
{
	if(scelta!=numeroVoci)
	   return true;
	else
	   return false;
}

//DEFINIZIONE METODO PER ESEGUIRE UN'OPERAZIONE A SECONDA DELLA SCELTA ESEGUITA
void Menu::eseguiOperazione()
{
	
	if(scelta<=numeroVoci)
	{
			stampaLinea();
			
			switch(scelta)
			{
				case 1:
						cout<<"SCELTO "<<opzioni[scelta-1]<<endl;
						for(int i=0;i<10;i++){
							s[i].setStudente();
						}	   
				break;
				
				case 2:
					
					   cout<<"SCELTO "<<opzioni[scelta-1]<<endl;
					   for(int i=0;i<10;i++){
							s[i].stampaStudente();
						}					
				break;
				
				case 3:
						cout<<"SCELTO "<<opzioni[scelta-1]<<endl;
						//ORDINA ARRAY STUDENTE BUBBLE SORT
						for(int i=0;i<10-1;i++){
							for(int j=0;j<10-i-1;j++){
								if(s[j].getMatricola()>s[j+1].getMatricola()){
									Studente temp=s[j];
									s[j]=s[j+1];
									s[j+1]=temp;
								}
							}
						}
				break;
				
				case 4:
						cout<<"SCELTO "<<opzioni[scelta-1]<<endl;
						//RICERCA ARRAY STUDENTE RICERCA SEQUENZIALE
						int matricolaDaCercare;
						cout<<"INSERISCI LA MATRICOLA DA CERCARE: ";
						cin>>matricolaDaCercare;
						bool trovato=false;
						for(int i=0;i<10;i++){
							if(s[i].getMatricola()==matricolaDaCercare){
								s[i].stampaStudente();
								trovato=true;
								break;
							}
						}
						if(!trovato){
							cout<<"STUDENTE NON TROVATO"<<endl;
						}
				break;
				
				case 5:
					
						cout<<"SCELTO "<<opzioni[scelta-1]<<endl;
						//ELIMINA ARRAY STUDENTE
						int matricolaDaEliminare;
						cout<<"INSERISCI LA MATRICOLA DA ELIMINARE: ";
						cin>>matricolaDaEliminare;
						bool eliminato=false;
						for(int i=0;i<10;i++){
							if(s[i].getMatricola()==matricolaDaEliminare){
								s[i].setMatricola(0);
								eliminato=true;
								break;
							}
						}
						if(!eliminato){
							cout<<"STUDENTE NON TROVATO"<<endl;
						}
				break;
				
				default:
					cout<<"LE SCELTE POSSIBILI VANNO DA 1-10"<<endl;
			
			}//FINE SWITCH
			
			stampaLinea();
			system("pause");
		  	system("cls");
	
	}
	else
	{
	 	  stampaLinea();
		  cout<<"HAI SOLO "<<numeroVoci<<" VOCI NEL MENU"<<endl;
		  stampaLinea();
		  system("pause");
		  system("cls");
	}
	
}
