#include "Carta.h"

Carta::Carta(){//Costruttore senza parametri
    //ctor
    nome=' ';
    valore=0;
    seme=' ';
}

Carta::Carta(char n, int v, char s){//Costruttore con parametri
    nome=n;
    valore=v;
    seme=s;
}

Carta::~Carta()
{
    //dtor
}
char Carta::getNome(){
    return nome;
}

void Carta::setNome(char n){
    nome=n;
}

int Carta::getValore(){
    return valore;
}

void Carta::setValore(int v){
    valore=v;
}

char Carta::getSeme(){
    return seme;
}

void Carta::setSeme(char s){
    seme=s;
}
