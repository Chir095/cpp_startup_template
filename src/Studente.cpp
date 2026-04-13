#include "Studente.h"

Studente::Studente(){
    matricola = 0;
    nome = "";
    cognome = "";
    eta = 0;
    mediaVoti = 0.0;
    provincia = "";
    residenza = "";
    sesso = ' ';
}

Studente::Studente(int m, const string &n, const string &c, int e, float mv, const string &p, const string &r, char s){
    matricola = m;
    nome = n;
    cognome = c;
    eta = e;
    mediaVoti = mv;
    provincia = p;
    residenza = r;
    sesso = s;
}

int Studente::getMatricola(){
    return matricola;
}

string Studente::getNome(){
    return nome;
}

string Studente::getCognome(){
    return cognome;
}

int Studente::getEta(){
    return eta;
}

float Studente::getMediaVoti(){
    return mediaVoti;
}

string Studente::getProvincia(){
    return provincia;
}

string Studente::getResidenza(){
    return residenza;
}

char Studente::getSesso(){
    return sesso;
}

void Studente::setMatricola(int m){
    matricola = m;
}

void Studente::setNome(const string &n){
    nome = n;
}

void Studente::setCognome(const string &c){
    cognome = c;
}

void Studente::setEta(int e){
    eta = e;
}

void Studente::setMediaVoti(float mv){
    mediaVoti = mv;
}

void Studente::setProvincia(const string &p){
    provincia = p;
}

void Studente::setResidenza(const string &r){
    residenza = r;
}

void Studente::setSesso(char s){
    sesso = s;
}

void Studente::setStudente(){
    int mat;
    string nom, cog, pro, res;
    unsigned char et;
    float mv;
    char ses;
    
    cout<<"INSERIMENTO NUOVO STUDENTE"<<endl;
    cout<<endl<<"INSERISCI NUMERO DI MATRICOLA";
    mat = leggiInt();
    setMatricola(mat);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    cout<<endl<<"INSERISCI NOME: ";
    getline(cin, nom);
    setNome(nom);
    
    cout<<endl<<"INSERISCI COGNOME: ";
    getline(cin, cog);
    setCognome(cog);
    
    cout<<endl<<"INSERISCI ETA: ";
    et = leggiUchar();
    setEta(et);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    cout<<endl<<"INSERISCI MEDIA VOTI: ";
    mv = leggiFloat();
    setMediaVoti(mv);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    cout<<endl<<"INSERISCI PROVINCIA: ";
    getline(cin, pro);
    setProvincia(pro);
    
    cout<<endl<<"INSERISCI RESIDENZA: ";
    getline(cin, res);
    setResidenza(res);
    
    cout<<endl<<"INSERISCI SESSO: ";
    ses = leggiChar();
    setSesso(ses);
}

void Studente::stampaStudente(){
    cout<<endl<<"STAMPA STUDENTE"<<endl;
    
    cout<<endl<<"MATRICOLA: "<<getMatricola();
    cout<<endl<<"NOME: "<<getNome();
    cout<<endl<<"COGNOME: "<<getCognome();
    cout<<endl<<"ETA: "<<getEta();
    cout<<endl<<"MEDIA VOTI: "<<getMediaVoti();
    cout<<endl<<"PROVINCIA: "<<getProvincia();
    cout<<endl<<"RESIDENZA: "<<getResidenza();
    cout<<endl<<"SESSO: "<<getSesso();
}

unsigned char leggiUchar(){
    
    int temp=0;
    while(!(cin>>temp && temp>=0 && temp<=255)){
        cout<<"INSERISCI: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return static_cast<unsigned char>(temp);
}

int leggiInt(){
    int temp=0;
    while(!(cin>>temp && temp>=0)){
        cout<<"INSERISCI: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return temp;
}

float leggiFloat(){
    float temp=0;
    while(!(cin>>temp && temp>=0)){
        cout<<"INSERISCI: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return temp;
}

char leggiChar(){
    int scelta=0;
    bool fine=false;
    char s;
    do{
        cout<<"INSERISCI SESSO: [1]M or [2]F";
        scelta = leggiUchar();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
        switch(scelta){
            case 1:
                s= 'M';
                fine=true;
            break;
            
            case 2:
                s= 'F';
                fine=true;
            break;
            
            default:
                cout<<endl<<"SELEZIONE NON VALIDA, INSERISCI UN VALORE TRA 1 e 2";
        } 
        
    }while(!fine);
    
    return s;
}




