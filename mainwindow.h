#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMap"
#include "QListWidgetItem"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QStringList MA;
    QBrush green = Qt::darkGreen;
    QBrush red = Qt::darkRed;
    QList<int> complete;
    QList<int> completeBU;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_InsertBTM_clicked();

    void on_removeBTM_clicked();

    void on_saveBTM_clicked();

    void on_loadBTM_clicked();

    void on_completeBTM_clicked();

    void on_uncompleteBTM_clicked();

    void on_metaaInsertion_returnPressed();

    void on_metaaList_itemDoubleClicked(QListWidgetItem *item);

    void on_insertInTheMiddle_clicked();

    void on_reloadList_clicked();

private:


    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
