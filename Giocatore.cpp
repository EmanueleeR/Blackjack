#include "Giocatore.h"

Giocatore::Giocatore(){//Costruttore senza parametri
    //ctor
    nome="Giocatore 1";
    punteggio=0;
    punteggioalto=0;
    punteggiobasso=0;
    soldi=1000;
    manoterminata=false;
    numerocarte=0;
    asso=false;
    cartarichiesta=false;
}

Giocatore::Giocatore(string nom){//Costruttore con solo Nome giocatore come parametro
    nome=nom;
    punteggio=0;
    punteggioalto=0;
    punteggiobasso=0;
    soldi=1000;
    manoterminata=false;
    numerocarte=0;
    asso=false;
    cartarichiesta=false;
}

Giocatore::Giocatore(string nom, int p, int pa, int pb, int sold, bool manter, int numcar, bool ass, bool cartrich){//Costruttore con paramtri
    nome=nom;
    punteggio=p;
    punteggioalto=pa;
    punteggiobasso=pb;
    soldi=sold;
    manoterminata=manter;
    numerocarte=numcar;
    asso=ass;
    cartarichiesta=cartrich;
}


Giocatore::~Giocatore(){
    //dtor
}



Carta Giocatore::getCarta(int indice){
    return mano[indice];
}

void Giocatore::setMano(Carta c, int indice){
    mano[indice] = c;
}

void Giocatore::reset_giocatore(){
	punteggio = 0;
	punteggiobasso = 0;
	manoterminata = false;
	for(int i = 0; i < 12; i++){
		mano[i].setNome(' ');
		mano[i].setSeme(' ');
		mano[i].setValore(0);

	}
	numerocarte = 0;
	asso = false;
	cartarichiesta = false;
}

//INIZIO GETTER E SETTER
string Giocatore::getNome(){
    return nome;
}
void Giocatore::setNome(string nom){
    nome=nom;
}

int Giocatore::getPunteggio(){
    return punteggio;
}
void Giocatore::setPunteggio(int p){
    punteggio=p;
}

int Giocatore::getPunteggioAlto(){
    return punteggioalto;
}
void Giocatore::setPunteggioAlto(int pa){
    punteggioalto=pa;
}

int Giocatore::getPunteggioBasso(){
    return punteggiobasso;
}
void Giocatore::setPunteggioBasso(int pb){
    punteggiobasso=pb;
}

int Giocatore::getSoldi(){
    return soldi;
}
void Giocatore::setSoldi(int sold){
    soldi=sold;
}

bool Giocatore::getManoTerminata(){
    return manoterminata;
}
void Giocatore::setManoTerminata(bool manter){
    manoterminata=manter;
}

int Giocatore::getNumeroCarte(){
    return numerocarte;
}
void Giocatore::setNumeroCarte(int numcar){
    numerocarte=numcar;
}

bool Giocatore::getAsso(){
    return asso;
}
void Giocatore::setAsso(bool ass){
    asso=ass;
}
bool Giocatore::getCartarichiesta(){
    return cartarichiesta;
}
void Giocatore::setCartarichiesta(bool cartrich){
    cartarichiesta=cartrich;
}
//FINE GETTER E SETTER

//INIZIO FUNZIONI PER IL GIOCO DEL BLACKJACK
void Giocatore::chiedi_carta(Carta nuovacarta){
	mano[numerocarte] = nuovacarta;
	if (nuovacarta.getNome() == 'A'){
        if(punteggio + 11 > 21){
            if(punteggiobasso + 11 > 21){
                asso = false;
            }else{
                punteggiobasso += 1;
            }
            punteggio += 1;
        }else{
            asso = true;
            punteggio += nuovacarta.getValore();
            punteggiobasso = punteggio - 10;
        }
	}else{
		punteggio += nuovacarta.getValore();
		if(asso == true){
			punteggiobasso += nuovacarta.getValore();
		}
		if(asso == true && punteggio > 21 && punteggiobasso < 21){
			punteggio = punteggiobasso;
			asso = false;
		}
	}
	numerocarte++;
}

int Giocatore::gioca_il_turno(Mazzo mazzocarte, int & cartdistr){
	while (getManoTerminata() == false) {
		stampa_carte();
		cout << "1) Chiedi Carta" << endl << "2) Stai" << endl;
		int opzione;
		cin >> opzione;
        opzione = controlla_input_scelta(2, opzione);

		int numerocarte = 2;
		if (opzione == 1){
		    chiedi_carta(mazzocarte.getCarta(cartdistr));
			setCartarichiesta(true);
			if (getPunteggio() >= 21) {
				setManoTerminata(true);
			}
		}
		else if (opzione == 2) {
			setManoTerminata(true);
		}
		system("cls");
	}
	return cartdistr;
}

void Giocatore::stampa_punteggio(Giocatore g){
	if (g.getAsso() == false || g.getPunteggio() == 21) {
		cout << g.getPunteggio() << endl;
	}
	else {
        cout << g.getPunteggio() << endl;
    }
}

bool Giocatore::verifica_blackjack(){
	if (punteggio == 21){
        if( (mano[numerocarte].getNome()=='A' && mano[numerocarte-1].getValore()==10) || (mano[numerocarte-1].getNome()=='A' && mano[numerocarte].getValore()==10)){
            return true;
        }
	}else{
		return false;
	}
}

void Giocatore::stampa_carte(){
    for(int i = 0; i < numerocarte; i++){
		cout << mano[i].getNome() << " di " << mano[i].getSeme() << endl;
	}
}


int Giocatore::controlla_input_scelta(int numeroopzioni, int scelta){
    while (scelta > numeroopzioni || scelta < 1) {
		cout << "Opzione non esistente. Inserisci un numero compreso tra 1 e " <<
			numeroopzioni << endl;
		cin >> scelta;
	}
	return scelta;
}


void Giocatore::stampa_statistiche_giocatore(){
	cout << "Statistiche del giocatore di nome: " << nome << endl;
	cout << "Soldi a fine partita: " << soldi << endl;
}
//FINE FUNZIONI PER IL GIOCO DEL BLACKJACK


