#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QIODevice"
#include "QMessageBox"
#include "QDebug"
#include "somefunctions.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_InsertBTM_clicked(){

    QString text=ui->metaaInsertion->text();

    MA.push_back(text);


    ui->metaaList->addItem(text);
    ui->metaaInsertion->clear();


}

void MainWindow::on_metaaInsertion_returnPressed()
{
    on_InsertBTM_clicked();
}

void MainWindow::on_removeBTM_clicked()
{
    int ListSize[2] ={ complete.size()};
    int currentROW = ui->metaaList->currentRow();
    qDebug() << ListSize[0];
    for(int i=0; i<ListSize[0]; i++){
        if(complete.front() == currentROW){
            complete.pop_front();
            break;
        }
        completeBU.push_front(complete.front());
        complete.pop_front();
    }
    ListSize[1] = completeBU.size();
    for(int i=0; i<ListSize[1]; i++){
        complete.push_front(completeBU.front());
        completeBU.pop_front();
    }

    qDeleteAll(ui->metaaList->selectedItems());

    if(MA.size() != 1){MA.removeAt(ui->metaaList->currentRow());} else {MA.pop_front();}
    qDebug() << MA.size();
}

void MainWindow::on_saveBTM_clicked()
{
    QString test = "fon";
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Metas"), "",
           tr("Meta/Algorithm (*.ma);;All Files (*)"));
    if (fileName.isEmpty())
            return;
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }
            QDataStream out(&file);
                    out.setVersion(QDataStream::Qt_4_5);
                        out << MA;
    }
}

void MainWindow::on_loadBTM_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Save Metas"), "",
           tr("Meta/Algorithm (*.ma);;All Files (*)"));
    if (fileName.isEmpty())
            return;
        else {
    QString test;
            QFile file(fileName);

            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }

            QDataStream in(&file);
            in.setVersion(QDataStream::Qt_4_5);

            int OriginalListSize = MA.size();
                            for(int i=0; i<OriginalListSize; i++){
                                MA.pop_front();
                            }
            in >> MA;

            if (MA.isEmpty()) {
                        QMessageBox::information(this, tr("No test exists"),
                            tr("error in test."));
                    } else {
                ui->metaaList->clear();

                    ui->metaaList->insertItems(0,MA);

        }
    }
}

void MainWindow::on_completeBTM_clicked()
{
 QBrush test = Qt::green;
 int currentROW = ui->metaaList->currentRow();
 if(currentROW >= 0){
    ui->metaaList->currentItem()->setBackground(test);
    complete.push_back(currentROW);
 }
}

void MainWindow::on_uncompleteBTM_clicked()
{
    int ListSize[2] ={ complete.size()};
    int currentROW = ui->metaaList->currentRow();
    qDebug() << ListSize[0];
    for(int i=0; i<ListSize[0]; i++){
        if(complete.front() == currentROW){
            complete.pop_front();
            break;
        }
        completeBU.push_front(complete.front());
        complete.pop_front();
    }
    ListSize[1] = completeBU.size();
    for(int i=0; i<ListSize[1]; i++){
        complete.push_front(completeBU.front());
        completeBU.pop_front();
    }
    ui->metaaList->currentItem()->setBackground(red);
}


