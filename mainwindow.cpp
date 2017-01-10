#include "mainwindow.h"
#include "ui_mainwindow.h"
/***************************************************************************
 *
 **************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Init();
}
/***************************************************************************
 *
 **************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}
/***************************************************************************
 *
 **************************************************************************/
void MainWindow::Init()
{
    QFont font;
    font.setBold(true);
    font.setPointSize(14);

    /* Set cloud area style  */
    ui->CloudWidget->setStyleSheet("background:#51B7F3");
    ui->cloudLabel->setFont(font);
    ui->cloudLabel->setStyleSheet("color: #E2F92A");

    ui->passWdLabel->setStyleSheet("color:white");
    ui->passWdIn->setStyleSheet("background:white");
    ui->passWdIn->setEchoMode(QLineEdit::Password);     /*  set password input invisible    */

    ui->uNameIn->setStyleSheet("background:white");
    ui->uNameLabel->setStyleSheet("color:white");

    QString cloudStyle = QString("QPushButton{color:white;}\
                                  QPushButton:hover{color:yellow; } \
                                  QPushButton:pressed{color:yellow;background-color:#38DA9E}");
    ui->regBtn->setStyleSheet(cloudStyle);
    ui->logInBtn->setStyleSheet(cloudStyle);
    ui->otherOpBtn->setStyleSheet(cloudStyle);

    /*  Set local area style  */
    ui->LocalWidget->setStyleSheet("background:#A440BF");
    ui->localLabel->setFont(font);
    ui->localLabel->setStyleSheet("color: #E2F92A");

    QString localStyle = QString("QPushButton{color:white;}\
                                  QPushButton:hover{color:yellow; } \
                                  QPushButton:pressed{color:yellow;background-color:#38DA9E}");
    ui->createBtn->setStyleSheet(localStyle);
    ui->openBtn->setStyleSheet(localStyle);

    font.setBold(false);
    font.setPointSize(12);
    font.setStyle(QFont::StyleItalic);
    ui->fileNameIn->setStyleSheet("background:white");
    ui->fileNameIn->setFont(font);
    ui->fileNameIn->setText(tr("You can type the file name and path in here to open..."));

    /*  connects    */
    connect(this->ui->openBtn,SIGNAL(clicked(bool)),this,SLOT(slotOpenfile()));
    connect(this->ui->createBtn,SIGNAL(clicked(bool)),this,SLOT(slotCreatefile()));

}
/***************************************************************************
 *
 **************************************************************************/
void MainWindow::cryptoData()
{



}
/***************************************************************************
 *
 **************************************************************************/
void MainWindow::decryptoData()
{



}
/***************************************************************************
 *
 **************************************************************************/
void MainWindow::slotOpenfile()
{
    QString getFilename = QFileDialog::getOpenFileName(this,\
                                                       tr("Please select the data file"),\
                                                       tr("/home/"),\
                                                       tr("ALL (*.c)"));
    if (getFilename == NULL) return;    /*  if user choice nothing ,do nothing  */

    /*  Open file and read file all data to memory  */
    g_file.setFileName(getFilename);
    if ( g_file.open( QIODevice::ReadWrite) == false ){
        QMessageBox err(this);
        err.setText(tr("Open data file: %1 was failed,Please check you have the "
                       "permition").arg(getFilename));

        err.setWindowTitle("Open ERROR");
        err.setIcon(QMessageBox::Critical);
        err.exec();
        g_file.close();
        return;
    }

    /*  Read file   */
    g_data  = g_file.readAll();
    if ( g_data.isEmpty() ){
        QMessageBox err(this);
        err.setText(tr("Load data file:%1 was failed /n It may empty!").arg(getFilename));
        err.setWindowTitle("Read ERROR");
        err.setIcon(QMessageBox::Critical);
        err.exec();
        g_file.close();
        return;
    }
    g_file.close();

    /*  Close the open file ui,Create the oparet data and show  */
    ui->CloudWidget->close();
    ui->LocalWidget->close();

    g_mainArea = new dataShow();
    this->ui->mainAreaLayout->addWidget(g_mainArea);
    if(g_mainArea->getData((void *)&g_data) == false){
        return;
    }
   //else g_mainArea->

}
/***************************************************************************
 *
 **************************************************************************/
void MainWindow::slotSavefile()
{

}
/***************************************************************************
 *
 **************************************************************************/
void MainWindow::slotCreatefile()
{
     QString getFilename = QFileDialog::getSaveFileName(this, \
                                                        tr("Please select the data file"), \
                                                        tr("/home/"), \
                                                        tr("ALL (*.c)"));

     if (getFilename == NULL) return;
     /*----Open file----*/
     g_file.setFileName(getFilename);
     if ( g_file.open( QIODevice::ReadWrite) == false ){
         QMessageBox err(this);
         err.setText(tr("Open data file: %1 was failed,Please check you have the "
                        "permition").arg(getFilename));

         err.setWindowTitle("Open ERROR");
         err.setIcon(QMessageBox::Critical);
         err.exec();
         g_file.close();
         return;
     }
     /*  Close the open file ui,Create the oparet data and show  */
     ui->CloudWidget->close();
     ui->LocalWidget->close();

     g_mainArea = new dataShow(this);
     this->ui->mainAreaLayout->addWidget(g_mainArea);
}
