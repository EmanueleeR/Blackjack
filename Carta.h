#ifndef CARTA_
#define CARTA_


class Carta{
    private:
        char nome;
        int valore;
        char seme;

    public:
        Carta();//Costruttore senza parametri
        Carta(char n, int v, char s);//Costruttore con parametri
        virtual ~Carta();//Distruttore
        char getNome();
        void setNome(char n);
        int getValore();
        void setValore(int v);
        char getSeme();
        void setSeme(char s);

};

#endif // CARTA_
