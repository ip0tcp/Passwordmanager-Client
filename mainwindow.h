#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <datashow.h>
#include <QByteArray>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Init();
    dataShow * g_mainArea;

private:
    Ui::MainWindow *ui;
   QFile  g_file;
   QByteArray g_data;


private slots:
    void slotOpenfile();
    void slotSavefile();
    void slotCreatefile();
    void cryptoData();
    void decryptoData();
};

#endif // MAINWINDOW_H
