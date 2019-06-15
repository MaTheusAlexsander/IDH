#ifndef PAIS_H
#define PAIS_H
#include <QVector>
#include <algorithm>
#include <QFile>
#include <QTextStream>
#include "idh.h"

class Pais
{
     private:

        QVector<Idh> pais;
        QVector<Idh> afr;
        QVector<Idh> asi;
        QVector<Idh> ant;
        QVector<Idh> ams;
        QVector<Idh> amc;
        QVector<Idh> oce;
        QVector<Idh> eur;

    public:
        Pais();
        void inserirIdh (Idh jota);
        Idh operator [](int i);

        void ordenarPorCont();
        void ordenarPorPais();
        void ordenarPorExpectativa();
        void ordenarPorAnos_Med();
        void ordenarPorAnos_Esper();
        void ordenarPorIdh();
        void ordenarPorPib();

        void ordenarPorAfrica();

        int size();
        int alfa();

        bool salvarIdh(QString arquivo);
        bool carregarIdh(QString arquivo);



    protected:

};

bool compCont(Idh a, Idh b);
bool compPais(Idh a, Idh b);
bool compExpectativa(Idh a, Idh b);
bool compPib(Idh a, Idh b);
bool compIdh(Idh a, Idh b);
bool compAnos_medios(Idh a, Idh b);
bool compAnos_esperados(Idh a, Idh b);

bool compAfrica(Idh a, Idh b);



#endif // PAIS_H
