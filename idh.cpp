#include "idh.h"
#include "pais.h"


Idh::Idh()
{

}

bool Idh::setPaises(const QString &pais)
{
    if(pais == "<Selecionar País>"){
        return false;
    }else{
         paises = pais;
         return true;
    }

}

QString Idh::getPaises() const
{
    return paises;
}

bool Idh::setContinente(const QString &cont)
{
    if(cont =="<Selecionar Continente>"){
        return false;
    }else{
    continente = cont;
    return true;
}
}

QString Idh::getContinente() const
{
    return continente;
}

bool Idh::setEsperanca_vida(double vida)
{
    if(vida<85 and vida>20.0){
       esperanca_vida = vida;
       return true;
    }else{
        return false;
    }
}

double Idh::getEsperanca_vida()
{
    return esperanca_vida;
}

bool Idh::setAnos_medios(double value)
{
    if(value<15 and value>1.0){
       anos_medios = value;
       return true;
    }else{
        return false;
    }
}

double Idh::getAnos_medios()
{
    return anos_medios;
}

bool Idh::setAnos_esperados(double value)
{
    if(value<22 and value>1.0){
       anos_esperados = value;
       return true;
    }else{
      return false;
    }

}

double Idh::getAnos_esperados()
{
    return anos_esperados;
}

bool Idh::setPib(double value)
{
    if(value<108211.0 and value>163.0){
       pib = value;
       return true;
    }else{
        return false;
    }

}

double Idh::getPib()
{
    return pib;
}



double Idh::calcularEsperanca_vida(){

return ((esperanca_vida-20.0)/(83.2-20.0));

}


double Idh::calcularIndice_educacao(){

double iam;
double iae;

iam=((anos_medios))/(13.2-0.0);
iae=((anos_esperados))/(20.6-0.0);

return((qSqrt(iae*iam))/(0.951-0.0));

    }


double Idh::calcularPib(){

return(((qLn(pib))-qLn(163.0))/(qLn(108211.0)-qLn(163.0)));

    }

double Idh::calcularIdh(){

    double idh;
    idh=qPow(calcularEsperanca_vida()*calcularIndice_educacao()*calcularPib(),(1.0/3.0));

    return idh;
    }

QString Idh::getStatus(){

if(calcularIdh()>0.8){
    return("Muito Elevado");
    }
else if(calcularIdh()<0.8 and calcularIdh()>0.7){
    return("Elevado");
    }
else if(calcularIdh()<.7 and calcularIdh()>0.55){
    return("Médio");
    }
else if(calcularIdh()<0.55){
    return("Baixo");
    }
}
