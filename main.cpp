#include <iostream>
#include "Carta.h"
#include "Mazzo.h"
#include "Giocatore.h"
#include "Mazziere.h"
#include <string>
#include <iomanip>
using namespace std;

string menu_richiesta_nome();
int verifica_correttezza_puntata(Giocatore & g, int punt);
void reset(Giocatore & g1, Mazziere & dealer, int & cartdistr);
void reset_statistiche(Giocatore & g1, Mazziere & dealer, int & cartdistr);
void confronta_punteggi(Giocatore & g1, Mazziere & dealer, bool bj, bool bjdealer, int puntata, int puntegg);
void avvio_gioco(string n);

int main() {
	string nome = menu_richiesta_nome();
	avvio_gioco(nome);


	return 0;
}

string menu_richiesta_nome(){
	cout << "Benvenuto al gioco del Blackjack!" << endl << "Per favore digita il tuo nome: " << endl;
	string nome;
	cout << "Nome: ";
	cin >> nome;
	cout << endl;
	return nome;
}

int verifica_correttezza_puntata(Giocatore & g, int punt){
    while(punt<=0 || punt>g.getSoldi()){
        if(punt<0){
            cout<<"Errore! Non puoi scommettere una cifra minore di 0"<<endl;
            cout<<"Inserisci nuovamente la tua puntata: ";
        }else if(punt==0){
            cout<<"Errore! Non puoi scommettere una cifra equivalente a 0"<<endl;
            cout<<"Inserisci nuovamente la tua puntata: ";
        }else if(punt>g.getSoldi()){
            cout<<"Errore! Non puoi scommettere una cifra maggiore dei tuoi "<<g.getSoldi()<<" euro"<<endl;
            cout<<"Inserisci nuovamente la tua puntata: ";
        }
        cin>>punt;
        cout<<endl;
    }
    return punt;
}

void reset(Giocatore & g1, Mazziere & dealer, int & cartdistr){
    g1.reset_giocatore();
	dealer.reset_mazziere();
	cartdistr=0;
}

void reset_statistiche(Giocatore & g1, Mazziere & dealer, int & cartdistr){
    reset(g1, dealer, cartdistr);
	g1.setSoldi(1000);
}

void confronta_punteggi(Giocatore & g1, Mazziere & dealer, bool bj, bool bjdealer, int puntata, int puntegg){
	// Confronto i punteggi del giocatore e del dealer e pago al giocatore la puntata quando gli è dovuto
	int vincita = 0;
	if (bj == true && dealer.verifica_blackjack() == false) {
		system("cls");
		g1.stampa_carte();
		dealer.stampa_carte();
		dealer.stampa_punteggio(dealer);
		cout << "HAI FATTO BLACKJACK! Il Dealer ha un punteggio pari a " << dealer.getPunteggio() << endl;
		vincita = 2.5 * (double)puntata;
		cout << "Hai vinto" << vincita << endl;
		g1.setSoldi(g1.getSoldi() + vincita);
	}
	else if (puntegg > 21) {
		cout << "HAI SBALLATO! Hai perso questa mano. Avevi un punteggio pari a " << puntegg << ". Il dealer aveva " << dealer.getPunteggio() << endl;
	}
	else if (puntegg > dealer.getPunteggio()) {
		cout << "Hai vinto. Avevi un punteggio pari a " << puntegg << ". Il dealer aveva " << dealer.getPunteggio() << endl;
		vincita = 2 * puntata;
		cout << "Hai vinto" << vincita << endl;
		g1.setSoldi(g1.getSoldi() + vincita);
	}
	else if (dealer.getPunteggio() > 21) {
		cout << "Hai vinto. Avevi un punteggio pari a " << puntegg << ". Il dealer aveva " << dealer.getPunteggio() << endl;
		vincita = 2 * puntata;
		cout << "Hai vinto" << vincita << endl;
		g1.setSoldi(g1.getSoldi() + vincita);
	}
	else if (puntegg < dealer.getPunteggio()) {
		cout << "Hai perso. Avevi un punteggio pari a " << puntegg << ". Il dealer aveva " << dealer.getPunteggio() << endl;
	}
	else {
		cout << "Pari. Sia tu che il dealer avevate un punteggio pari a " << puntegg << endl;
		g1.setSoldi(g1.getSoldi() + vincita);
	}
}

void avvio_gioco(string n){
    //Variabili per le classi
	Giocatore p1;
	Mazziere dealer;
	p1.setNome(n);
	Mazzo mazzo1;
	mazzo1.creazione_mazzo();
	bool gameOver = false;

	// Variabili di gioco
    int cartedistribuite = 0;
    bool blackjack = false;
    bool blackjackdealer = false;
	int scommessa;

	//inizio del gioco
	while (gameOver == false) {
		cout << "Soldi Giocatore: " << p1.getSoldi() << endl << "Puntata: " << endl;
		cin >> scommessa;
		scommessa = verifica_correttezza_puntata(p1, scommessa);
		p1.setSoldi(p1.getSoldi() - scommessa);
		mazzo1.mischiare_mazzo();



		// Distribuisco 2 carte ciascuno
		for (int i = 0; i < 2; i++) {
			p1.chiedi_carta(mazzo1.getCarta(cartedistribuite));
			dealer.chiedi_carta(mazzo1.getCarta(cartedistribuite));
		}


		// Turno Giocatore e Dealer
		if (blackjack == false && blackjackdealer == false) {
			p1.gioca_il_turno(mazzo1, cartedistribuite);
			dealer.gioca_il_turno(dealer, mazzo1, cartedistribuite);
		}
		p1.stampa_carte();
		dealer.stampa_carte();
		dealer.stampa_punteggio(dealer);
        confronta_punteggi(p1, dealer, blackjack, blackjackdealer, scommessa, p1.getPunteggio());



		// Dopo la prima mano chiedo se l'utente vuole nuovamente giocare e controlla che non abbia finito i soldi
		if (p1.getSoldi() == 0) {
			cout << "GAME OVER! Hai finito i soldi." << endl;
			p1.stampa_statistiche_giocatore();
			int playAgain;
			cout << "Vuoi giocare nuovamente?" << endl << "1) Si" << endl << "2) No" << endl;
			cin >> playAgain;
			playAgain = p1.controlla_input_scelta(2, playAgain);
			if (playAgain == 1) {
				reset_statistiche(p1, dealer, cartedistribuite);
			}
			else {
				gameOver = true;
			}
		}
		else {
			cout << "1) Gioca ancora" << endl << "2) Stampa statistiche " << endl << "3) Esci" << endl;
			int restart;
			cin >> restart;
			restart = p1.controlla_input_scelta(3, restart);
			if (restart == 2) {
				while (restart == 2) {
					p1.stampa_statistiche_giocatore();
                    cout << "1) Gioca ancora" << endl << "2) Stampa statistiche " << endl << "3) Esci" << endl;
					cin >> restart;
					restart = p1.controlla_input_scelta(3, restart);
				}
			}
			if (restart == 1) {
				reset(p1, dealer, cartedistribuite);
			}
			else {
				gameOver = true;
			}
		}
		system("cls");
	}

}

