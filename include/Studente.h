#ifndef STUDENTE_H
#define STUDENTE_H
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Studente{
    private:
        int matricola;
        string nome;
        string cognome;
        int eta;
        float mediaVoti;
        string provincia;
        string residenza;
        char sesso;

    public:
        Studente();
        Studente(int, const string &, const string &, int, float, const string &, const string &, char);
        int getMatricola();
        string getNome();
        string getCognome();
        int getEta();
        float getMediaVoti();
        string getProvincia();
        string getResidenza();
        char getSesso();
        void setMatricola(int); 
        void setNome(const string &);
        void setCognome(const string &);
        void setEta(int);
        void setMediaVoti(float);
        void setProvincia(const string &);
        void setResidenza(const string &);
        void setSesso(char);
        void setStudente();
        void stampaStudente();
};

unsigned char leggiUchar();
int leggiInt();
float leggiFloat();
char leggiChar();

#endif