#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include "pais.h"
#include "idh.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void on_comboContinente_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_OrdenarContinente_clicked();

    void on_OrdenarPais_clicked();

    void on_OrdenanrIDH_clicked();

    void on_OrdenarPib_clicked();

    void on_OrdenarExpectativa_clicked();

    void on_tabela_dados_cellDoubleClicked(int row, int column);

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

    void on_OrdenarMed_clicked();

    void on_pushButton_2_clicked();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    QStringList  africa, asia, europa, oceania, americasul, americacentral;
    QStringList  americanorte = {"Canadá", "Estados Unidos", "México"};
    QString selecionar = {"<Selecionar País>"};
    Idh  idh;
    Pais pais;
    Pais afr;

        void inserirDados();
        //void atualizarDados();
        void atualizarTabela();
        void inserirAfrica();
};

#endif // MAINWINDOW_H
