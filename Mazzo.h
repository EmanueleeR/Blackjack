#ifndef MAZZO_H
#define MAZZO_H

#include "Carta.h"
#include <iostream>
#include <ctime>
using namespace std;

class Mazzo{
    private:
        const static int dimensione_mazzo=52;
        const static int numero_semi=4;
        const static int numero_carte=13;
        char simboli[numero_semi]={'C','Q','F','P'};
        char nomicarte[numero_carte]={'A','2','3','4','5','6','7','8','9','D','J','Q','K'};

        Carta mazzodicarte[dimensione_mazzo];

    public:
        Mazzo();
        virtual ~Mazzo();
        void creazione_mazzo();
        void mischiare_mazzo();
        void stampa_mazzo();

        Carta getCarta(int & cartedistribuite);
        int conteggio_carte();
};

#endif // MAZZO_H
