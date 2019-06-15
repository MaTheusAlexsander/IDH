#ifndef IDH_H
#define IDH_H
#include <QObject>
#include <QtCore/qmath.h>
#include <iostream>


class Idh
{
    private:
     double esperanca_vida;
     double anos_medios ;
     double anos_esperados;
     double pib;
     QString paises;
     QString continente;
     QString status;


public:
    Idh();



    bool setPaises(const QString &pais);
    QString getPaises() const;

    bool setContinente(const QString &cont);
    QString getContinente() const;

    bool setEsperanca_vida(double vida);
    double getEsperanca_vida();

    bool setAnos_medios(double value);
    double getAnos_medios();

    bool setAnos_esperados(double value);
    double getAnos_esperados();

    double getIdh();

    bool setPib(double value);
    double getPib();

    QString getStatus();

    double calcularIdh();
    double calcularIndice_educacao();
    double calcularPib();
    double calcularEsperanca_vida();


};

#endif // IDH_H
