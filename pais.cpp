#include "pais.h"

Pais::Pais()
{

}

void Pais::inserirIdh(Idh jota)
{
  pais.push_back(jota);

      if(jota.getContinente() == "Africa"){
           afr.push_back(jota);
      }
          else if(jota.getContinente() == "Asia"){
           asi.push_back(jota);
      }
          else if(jota.getContinente() == "América Central"){
           amc.push_back(jota);
      }
          else if(jota.getContinente() == "América do Norte"){
           ant.push_back(jota);
      }
          else if(jota.getContinente() == "América do Sul"){
           ams.push_back(jota);
      }
          else if(jota.getContinente() == "Oceania"){
           oce.push_back(jota);
      }
          else if(jota.getContinente() == "Europa"){
            eur.push_back(jota);
}
  }


Idh Pais::operator[](int i){
  return pais[i];

}

int Pais::size()
{
   return pais.size();
}

int Pais::alfa(){
    return afr.size();
}


void Pais::ordenarPorCont(){
  std::sort(pais.begin(),pais.end(),compCont);
}

void Pais::ordenarPorPais(){
  std::sort(pais.begin(),pais.end(),compPais);
}

void Pais::ordenarPorPib(){
    std::sort(pais.begin(),pais.end(),compPib);
}

void Pais::ordenarPorAfrica()
{
    std::sort(afr.begin(),afr.end(),compIdh);
}

void Pais::ordenarPorIdh(){
  std::sort(pais.begin(),pais.end(),compIdh);
}

void Pais::ordenarPorExpectativa(){
    std::sort(pais.begin(),pais.end(),compExpectativa);
}

void Pais::ordenarPorAnos_Med()
{
    std::sort(pais.begin(),pais.end(), compAnos_medios);
}

void Pais::ordenarPorAnos_Esper()
{
    std::sort(pais.begin(),pais.end(), compAnos_esperados);
}

bool compCont(Idh a, Idh b){
  return a.getContinente()<b.getContinente();
}
bool compPais(Idh a, Idh b){
  return a.getPaises()<b.getPaises();
}
bool compExpectativa(Idh a, Idh b){
  return a.getEsperanca_vida()>b.getEsperanca_vida();
}
bool compPib(Idh a, Idh b){
  return a.getPib()>b.getPib();
}
bool compIdh(Idh a, Idh b){
  return a.calcularIdh()>b.calcularIdh();
}


bool Pais::salvarIdh(QString arquivo)
{
    QFile file(arquivo);
      QString linha;
      if(!file.open(QIODevice::WriteOnly))
          return false;

      for(Idh a : pais){
          linha = a.getContinente() + ',' + a.getPaises() + ',' + QString::number(a.getAnos_medios()) + ',' + QString::number(a.getAnos_esperados()) + ',' + QString::number(a.getEsperanca_vida()) + ',' + QString::number(a.getPib()) + '\n';
          file.write(linha.toLocal8Bit());
      }
      return true;

}

bool Pais::carregarIdh(QString arquivo)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QString linha;
    Idh a;
    while(!file.atEnd()){
        linha = file.readLine();
        QStringList dados = linha.split(",");
        a.setContinente(dados[0]);
        a.setPaises(dados[1]);
        a.setPib(dados[5].toDouble());
        a.setEsperanca_vida(dados[4].toDouble());
        a.setAnos_medios(dados[2].toDouble());
        a.setAnos_esperados(dados[3].toDouble());

        inserirIdh(a);


    }
    return true;
}

bool compAfrica(Idh a, Idh b)
{
      return a.calcularIdh()>b.calcularIdh();
}

bool compAnos_medios(Idh a, Idh b)
{
    return a.getAnos_medios()>b.getAnos_medios();
}

bool compAnos_esperados(Idh a, Idh b)
{
    return a.getAnos_esperados()>b.getAnos_esperados();
}
