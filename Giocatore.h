#ifndef GIOCATORE_
#define GIOCATORE_

#include <iostream>
#include <cstring>
#include "Mazzo.h"
#include "Carta.h"
using namespace std;

class Giocatore{
    private:
        string nome;
        int punteggio;
        int punteggioalto;
        int punteggiobasso;
        int soldi;
        bool manoterminata;
        int numerocarte;
        bool asso;
        bool cartarichiesta;
        Carta mano[12];

    public:
        Giocatore();//Costruttore senza parametri
        Giocatore(string nom);//Costruttore con solo Nome giocatore come parametro
        Giocatore(string nom, int p, int pa, int pb, int sold, bool manter, int numcar, bool ass, bool cartrich);//Costruttore con paramtri
        virtual ~Giocatore();

        Carta getCarta(int indice);

        void setMano(Carta c, int indice);

        void reset_giocatore();


        //INIZIO GETTER E SETTER
        string getNome();
        void setNome(string nom);

        int getPunteggio();
        void setPunteggio(int p);

        int getPunteggioAlto();
        void setPunteggioAlto(int pa);

        int getPunteggioBasso();
        void setPunteggioBasso(int pb);

        int getSoldi();
        void setSoldi(int sold);

        bool getManoTerminata();
        void setManoTerminata(bool manter);

        int getNumeroCarte();
        void setNumeroCarte(int numcar);

        bool getAsso();
        void setAsso(bool ass);

        bool getCartarichiesta();
        void setCartarichiesta(bool cartrich);
        //FINE GETTER E SETTER

        //INIZIO FUNZIONI PER IL GIOCO DEL BLACKJACK
        int gioca_il_turno(Mazzo mazzo, int & cartdistr);

        void stampa_punteggio(Giocatore g);

        void chiedi_carta(Carta nuovacarta);
        bool carta_richiesta(Carta);

        bool verifica_blackjack();

        void stampa_carte();

        int controlla_input_scelta(int numeroopzioni, int scelta);

        void stampa_statistiche_giocatore();
        //FINE FUNZIONI PER IL GIOCO DEL BLACKJACK



};

#endif // GIOCATORE_
