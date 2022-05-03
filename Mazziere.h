#ifndef MAZZIERE_H
#define MAZZIERE_H

#include "Carta.h"
#include "Mazzo.h"

class Mazziere{
    private:
        int punteggio;
        int numerocarte;
        int punteggiobasso;
        bool asso;
        bool manoterminata;
        Carta manomazziere[12];

    public:
        Mazziere();//Costruttore senza parametri
        Mazziere(int p, int numcar);//Costruttore con parametri
        virtual ~Mazziere();

        Carta getCarta(int indice);

        void setMano(Carta c, int indice);

        void reset_mazziere();

        //INIZIO GETTER E SETTER
        int getPunteggio();
        void setPunteggio(int p);

        int getNumeroCarte();
        void setNumeroCarte(int numcar);

        int getPunteggioBasso();
        void setPunteggioBasso(int pb);

        bool getAsso();
        void setAsso(bool ass);

        bool getManoTerminata();
        void setManoTerminata(bool manter);
        //FINE GETTER E SETTER

        //INIZIO FUNZIONI PER IL GIOCO DEL BLACKJACK
        void chiedi_carta(Carta nuovacarta);
        bool verifica_blackjack();
        void gioca_il_turno(Mazziere & dealer, Mazzo mazzocarte, int & cartdistr);
        void stampa_carte();
        void stampa_punteggio(Mazziere m);
        //FINE FUNZIONI PER IL GIOCO DEL BLACKJACK



};

#endif // MAZZIERE_H
