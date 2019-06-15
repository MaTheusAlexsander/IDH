#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pais.h"
#include "idh.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboContinente_currentIndexChanged(const QString &arg1)
{
    ui->comboPaises->clear();
    ui->comboPaises->addItem(selecionar);
      if(arg1=="Africa"){
        africa.clear();
        QFile file("Z:/IDH/continente/africa.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           return;
        }
        QTextStream in(&file);
        QString line;
        while (in.readLineInto(&line)) {
            africa << line;
    }
        file.close();
        std::sort(africa.begin(),africa.end());
        for(int i=0; i<africa.size(); i++)
        ui->comboPaises->addItems(africa);
    }

    else if (arg1=="América do Norte"){

        std::sort(americanorte.begin(),americanorte.end());

        ui->comboPaises->addItems(americanorte);
    }

    else if (arg1=="América do Sul"){
        americasul.clear();
        QFile file("Z:/IDH/continente/americasul.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           return;
        }
        QTextStream in(&file);
        QString line;
        while (in.readLineInto(&line)) {
            americasul << line;
         }
        file.close();
        std::sort(americasul.begin(),americasul.end());
        for(int i=0; i<americasul.size(); i++)
           qDebug() << americasul[i] << endl;
        ui->comboPaises->addItems(americasul);
    }


   else if (arg1=="Oceania"){
        oceania.clear();
        QFile file("Z:/IDH/continente/oceania.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           return;
        }
        QTextStream in(&file);
        QString line;
        while (in.readLineInto(&line)) {
             oceania << line;
         }
        file.close();
        std::sort(oceania.begin(),oceania.end());
        for(int i=0; i<oceania.size(); i++)
           qDebug() << oceania[i] << endl;
        ui->comboPaises->addItems(oceania);
    }


   else if (arg1=="Europa"){
        europa.clear();
        QFile file("Z:/IDH/continente/europa.txt");
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           return;
        }
        QTextStream in(&file);
        QString line;
        while (in.readLineInto(&line)) {
             europa << line;
         }
        file.close();
        std::sort(europa.begin(),europa.end());
        for(int i=0; i<europa.size(); i++)
           qDebug() << europa[i] << endl;
        ui->comboPaises->addItems(europa);
    }


   else if (arg1=="Asia"){
        asia.clear();
        QFile file("Z:/IDH/continente/asia.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           return;
        }
        QTextStream in(&file);
        QString line;
        while (in.readLineInto(&line)) {
             asia << line;
         }
        file.close();
        std::sort(asia.begin(),asia.end());
        for(int i=0; i<asia.size(); i++)
           qDebug() << asia[i] << endl;

        ui->comboPaises->addItems(asia);
    }



   else if (arg1=="América Central"){
        americacentral.clear();
        QFile file("Z:/IDH/continente/americacentral.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           return;
        }
        QTextStream in(&file);
        QString line;
        while (in.readLineInto(&line)) {
             americacentral << line;
         }
        file.close();
        std::sort(americacentral.begin(),americacentral.end());
        for(int i=0; i<americacentral.size(); i++)
           qDebug() << americacentral[i] << endl;
        ui->comboPaises->addItems(americacentral);
    }




}

void MainWindow::on_pushButton_clicked()
{
    ui->label_pib->clear();
    ui->label_vida->clear();
    ui->label_medio->clear();
    ui->label_esperado->clear();

    if(!idh.setContinente(QString(ui->comboContinente->currentText()))){
        QMessageBox::warning(this,"Continente","Selecione um Continente");
        return;
    }

    else if(!idh.setPaises(QString(ui->comboPaises->currentText()))){
        QMessageBox::warning(this,"País","Selecione um Pais");
        return;
    }
    else if(!idh.setEsperanca_vida(QString(ui->expectativa->text()).toDouble())){
        QMessageBox::warning(this,"Expectativa de Vida","Digite um valor válido");
        ui->label_vida->setText("Informação inválida");
      return;
    }
    else if(!idh.setAnos_medios(QString(ui->anos_medios->text()).toDouble())){
        QMessageBox::warning(this,"Anos Médios de Escolaridade","Digite um valor válido");
      ui->label_medio->setText("Informação inválida");
      return;
    }
    else if(!idh.setAnos_esperados(QString(ui->anos_esperados->text()).toDouble())){
        QMessageBox::warning(this,"Anos Esperados de Escolaridades","Digite um valor válido");
      ui->label_esperado->setText("Informação inválida");
      return;
    }

    else if(!idh.setPib(QString(ui->pib->text()).toDouble())){
        QMessageBox::warning(this,"PIB","Digite um PIB válido");
         ui->label_pib->setText("PIB Inválido");
        return;
    }

    idh.setPaises(ui->comboPaises->currentText());
    idh.setContinente(ui->comboContinente->currentText());
    idh.calcularPib();
    idh.calcularEsperanca_vida();
    idh.calcularIndice_educacao();



    if(idh.getContinente()=="<Selecionar Continente>"){
        return;}
    if(idh.getPaises()=="<Selecionar País>"){
        return;}

        pais.inserirIdh(idh);

        int verifica = ui->tabela_dados->rowCount();
        ui->tabela_dados->insertRow(verifica-1);
        ui->pib->clear();
        ui->anos_medios->clear();
        ui->anos_esperados->clear();
        ui->expectativa->clear();
        ui->comboPaises->setCurrentText("<Selecionar País>");
        ui->comboContinente->setCurrentText("<Selecionar Continente>");
        inserirDados();
}

void MainWindow::inserirDados()
{
    for(int j=0;j<pais.size();j++){
    ui->tabela_dados->setItem(j,0, new QTableWidgetItem(pais[j].getContinente()));
    ui->tabela_dados->setItem(j,1, new QTableWidgetItem(pais[j].getPaises()));
    ui->tabela_dados->setItem(j,2, new QTableWidgetItem(QString::number(pais[j].calcularIdh(),'g',3)));
    ui->tabela_dados->setItem(j,3, new QTableWidgetItem(pais[j].getStatus()));
    ui->tabela_dados->setItem(j,4, new QTableWidgetItem(QString::number(pais[j].getPib())));
    ui->tabela_dados->setItem(j,5, new QTableWidgetItem(QString::number(pais[j].getAnos_medios())));
    ui->tabela_dados->setItem(j,6, new QTableWidgetItem(QString::number(pais[j].getAnos_esperados())));
    ui->tabela_dados->setItem(j,7, new QTableWidgetItem(QString::number(pais[j].getEsperanca_vida())));

    }
}

void MainWindow::atualizarTabela()
{
  ui->tabela_dados->clearContents();
    for(int i=0; i<pais.size();i++){
        inserirDados();
    }
}

void MainWindow::inserirAfrica()
{
    for(int i=0;i<3;i++){
    ui->tabela_africa_1->setItem(i,0, new QTableWidgetItem(afr[i].getPaises()));
    ui->tabela_africa_1->setItem(i,1, new QTableWidgetItem(QString::number(afr[i].calcularIdh(),'g',3)));
    }
}


void MainWindow::on_OrdenarContinente_clicked()
{
    ui->tabela_dados->clearContents();

      pais.ordenarPorCont();
      inserirDados();
}

void MainWindow::on_OrdenarPais_clicked()
{
    ui->tabela_dados->clearContents();

      pais.ordenarPorPais();
      inserirDados();
}

void MainWindow::on_OrdenanrIDH_clicked()
{
    ui->tabela_dados->clearContents();

      pais.ordenarPorIdh();
      inserirDados();
}

void MainWindow::on_OrdenarPib_clicked()
{
    ui->tabela_dados->clearContents();

      pais.ordenarPorPib();
      inserirDados();
}

void MainWindow::on_OrdenarExpectativa_clicked()
{
    ui->tabela_dados->clearContents();

      pais.ordenarPorExpectativa();
      inserirDados();
}

void MainWindow::on_tabela_dados_cellDoubleClicked(int row, int column)
{
    Idh edit;
    if(column == 4){
        QMessageBox::StandardButton box = QMessageBox::question(this, "Editar PIB", "Deseja alterar o valor do PIB?");

        if(box == QMessageBox::Yes){
            bool ok;
            QString txt = QInputDialog::getText(this, "Alterar PIB", "PIB:", QLineEdit::Normal, "", &ok);
            if(ok and !txt.isEmpty()){
                edit.setPib(txt.toDouble());
                edit.setContinente(pais[row].getContinente());
                edit.setPaises(pais[row].getPaises());
                edit.setAnos_medios(pais[row].getAnos_medios());
                edit.setAnos_esperados(pais[row].getAnos_esperados());
                edit.setEsperanca_vida(pais[row].getEsperanca_vida());
                edit.calcularPib();
                edit.calcularEsperanca_vida();
                edit.calcularIndice_educacao();


                pais.inserirIdh(edit);
                ui->tabela_dados->setItem(row,4,new QTableWidgetItem(QString::number(edit.getPib())));
            }
        }
    }
    else if(column == 5){
        Idh edit;
            QMessageBox::StandardButton box = QMessageBox::question(this, "Editar Anos Médios", "Deseja alterar o valor de Anos médios?");

            if(box == QMessageBox::Yes){
                bool ok;
                QString txt = QInputDialog::getText(this, "Alterar Anos Médios", "Anos Médios de Escolaridades:", QLineEdit::Normal, "", &ok);
                if(ok and !txt.isEmpty()){
                    edit.setPib(pais[row].getPib());
                    edit.setContinente(pais[row].getContinente());
                    edit.setPaises(pais[row].getPaises());
                    edit.setAnos_medios(txt.toDouble());
                    edit.setAnos_esperados(pais[row].getAnos_esperados());
                    edit.setEsperanca_vida(pais[row].getEsperanca_vida());
                    edit.calcularPib();
                    edit.calcularEsperanca_vida();
                    edit.calcularIndice_educacao();

                    pais.inserirIdh(edit);
                    ui->tabela_dados->setItem(row,5,new QTableWidgetItem(QString::number(edit.getAnos_medios())));
         }
        }
    }
    else if(column == 6){
        Idh edit;
            QMessageBox::StandardButton box = QMessageBox::question(this, "Editar Anos Esperados", "Deseja alterar o valor de anos esperados?");

            if(box == QMessageBox::Yes){
                bool ok;
                QString txt = QInputDialog::getText(this, "Alterar anos esperados", "Anos Esperados de Escolaridades:", QLineEdit::Normal, "", &ok);
                if(ok and !txt.isEmpty()){
                    edit.setPib(pais[row].getPib());
                    edit.setContinente(pais[row].getContinente());
                    edit.setPaises(pais[row].getPaises());
                    edit.setAnos_medios(pais[row].getAnos_medios());
                    edit.setEsperanca_vida(pais[row].getEsperanca_vida());
                    edit.setAnos_esperados(txt.toDouble());
                    edit.calcularPib();
                    edit.calcularEsperanca_vida();
                    edit.calcularIndice_educacao();

                    pais.inserirIdh(edit);
                    ui->tabela_dados->setItem(row,6,new QTableWidgetItem(QString::number(edit.getAnos_esperados())));
                }
            }
    }
    else if(column == 7){
        Idh edit;
            QMessageBox::StandardButton box = QMessageBox::question(this, "Editar Expectativa de Vida", "Deseja alterar o valor de expactativa de vida ao nascer?");

            if(box == QMessageBox::Yes){
                bool ok;
                QString txt = QInputDialog::getText(this, "Alterar expectativa de vida", "Expectativa de Vida ao nascer:", QLineEdit::Normal, "", &ok);
                if(ok and !txt.isEmpty()){
                    edit.setPib(pais[row].getPib());
                    edit.setContinente(pais[row].getContinente());
                    edit.setPaises(pais[row].getPaises());
                    edit.setAnos_medios(pais[row].getAnos_medios());
                    edit.setAnos_esperados(pais[row].getAnos_esperados());
                    edit.setEsperanca_vida(txt.toDouble());
                    edit.calcularPib();
                    edit.calcularEsperanca_vida();
                    edit.calcularIndice_educacao();

                    pais.inserirIdh(edit);
                    ui->tabela_dados->setItem(row,6,new QTableWidgetItem(QString::number(edit.getAnos_esperados())));
                }
            }
    }

}

void MainWindow::on_actionSalvar_triggered()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,
                                                           "IDH_ano_",
                                                           "",
                                                           "CSV(*.csv)");
        pais.salvarIdh(nomeArquivo);

        QMessageBox::information(this,"Salvar", "Arquivo salvo com Sucesso!");
}

void MainWindow::on_actionCarregar_triggered()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,
                                                           "IDH_ano_",
                                                           "",
                                                           "CSV(*.csv)");
    pais.carregarIdh(nomeArquivo);
        for(int i=0;i<pais.size();i++){
            ui->tabela_dados->insertRow(i);
            inserirDados();
    }
}


void MainWindow::on_OrdenarMed_clicked()
{
    ui->tabela_dados->clearContents();

      pais.ordenarPorAnos_Med();
      inserirDados();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tabela_dados->clearContents();

      pais.ordenarPorAnos_Esper();
      inserirDados();
}
