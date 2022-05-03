#include "Mazziere.h"

Mazziere::Mazziere(){
    //ctor
    punteggio=0;
    numerocarte=0;
    punteggiobasso=0;
    asso=false;
    manoterminata=false;
}

Mazziere::Mazziere(int p, int numcar){
    punteggio=p;
    numerocarte=numcar;
    punteggiobasso=0;
    asso=false;
    manoterminata=false;
}

Mazziere::~Mazziere(){
    //dtor
}

Carta Mazziere::getCarta(int indice){
    return manomazziere[indice];
}

void Mazziere::setMano(Carta c, int indice){
    manomazziere[indice] = c;
}

void Mazziere::reset_mazziere() {
	punteggio = 0;
	manoterminata = false;
	for (int i = 0; i < 12; i++) {
        manomazziere[i].setNome(' ');
		manomazziere[i].setSeme(' ');
		manomazziere[i].setValore(0);
	}
	numerocarte = 0;
}

//INIZIO GETTER E SETTER
int Mazziere::getPunteggio(){
    return punteggio;
}
void Mazziere::setPunteggio(int p){
    punteggio=p;
}

int Mazziere::getNumeroCarte(){
    return numerocarte;
}
void Mazziere::setNumeroCarte(int numcar){
    numerocarte=numcar;
}

int Mazziere::getPunteggioBasso(){
    return punteggiobasso;
}
void Mazziere::setPunteggioBasso(int pb){
    punteggiobasso=pb;
}

bool Mazziere::getAsso(){
    return asso;
}
void Mazziere::setAsso(bool ass){
    asso=ass;
}

bool Mazziere::getManoTerminata(){
    return manoterminata;
}
void Mazziere::setManoTerminata(bool manter){
    manoterminata=manter;
}
//FINE GETTER E SETTER

//INIZIO FUNZIONI PER IL GIOCO DEL BLACKJACK
void Mazziere::chiedi_carta(Carta nuovacarta){
	manomazziere[numerocarte] = nuovacarta;
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

bool Mazziere::verifica_blackjack(){
	if (punteggio == 21){
        if( (manomazziere[numerocarte].getNome()=='A' && manomazziere[numerocarte-1].getValore()==10) || (manomazziere[numerocarte-1].getNome()=='A' && manomazziere[numerocarte].getValore()==10)){
            return true;
        }
	}else{
		return false;
	}
}
void Mazziere::gioca_il_turno(Mazziere & dealer, Mazzo mazzocarte, int & cartdistr){
	dealer.setManoTerminata(false);
	while (dealer.getManoTerminata() == false) {
		if (dealer.getPunteggio() < 17) {
			dealer.chiedi_carta(mazzocarte.getCarta(cartdistr));
			dealer.stampa_carte();
		}
		else {
			dealer.setManoTerminata(true);
			system("cls");
		}
	}
}




void Mazziere::stampa_carte(){
    for(int i = 0; i < numerocarte; i++){
		cout << manomazziere[i].getNome() << " " << manomazziere[i].getSeme() << endl;
	}
}

void Mazziere::stampa_punteggio(Mazziere m){
	if (m.getAsso() == false || m.getPunteggio() == 21) {
		cout << m.getPunteggio() << endl;
	}
	else {
        cout << m.getPunteggio() << endl;
    }
}
