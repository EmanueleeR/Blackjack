#include "Mazzo.h"

Mazzo::Mazzo()
{
    //ctor
}

Mazzo::~Mazzo()
{
    //dtor
}



void Mazzo::creazione_mazzo(){
    int l=0;
    for(int i=0;i<numero_semi;i++){
        for(int j=0;j<numero_carte;j++){
            mazzodicarte[l].setNome(nomicarte[j]);
            if(mazzodicarte[l].getNome()=='J' || mazzodicarte[l].getNome()=='Q' || mazzodicarte[l].getNome()=='K'){
                mazzodicarte[l].setValore(10);
            }else{
                mazzodicarte[l].setValore(j+1);
            }
            mazzodicarte[l].setSeme(simboli[i]);
            l++;
        }
    }
}
void Mazzo::mischiare_mazzo(){
    srand(time(NULL));
    int casuale;
    Carta temp;
    for(int i=0;i<dimensione_mazzo;i++){
        casuale=rand()%52;
        temp=mazzodicarte[i];
        mazzodicarte[i]=mazzodicarte[casuale];
        mazzodicarte[casuale]=temp;
    }
}
void Mazzo::stampa_mazzo(){
    for(int i=0;i<dimensione_mazzo;i++){
        cout<<mazzodicarte[i].getNome()<<" di "<<mazzodicarte[i].getSeme()<<" ha valore equivalente a "<<mazzodicarte[i].getValore()<<endl;
        if((i+1)%13==0){
            cout<<endl;
        }
    }
}


Carta Mazzo::getCarta(int  & cartdistr) {
	Carta nuovacarta = mazzodicarte[cartdistr];
	cartdistr++;
	return nuovacarta;
}


/*int Mazzo::conteggio_carte(int cont){
    if(mazzodicarte.nome=='2' || M[ind].nome=='3' || M[ind].nome=='4' || M[ind].nome=='5' || M[ind].nome=='6'){
        cont=cont+1;
    }else if(M[ind].nome=='D' || M[ind].nome=='J' || M[ind].nome=='Q' || M[ind].nome=='K' || M[ind].nome=='A'){
        cont=cont-1;
    }
    return cont;
}*/

