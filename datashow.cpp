#include "datashow.h"
#include "ui_datashow.h"

dataShow::dataShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataShow)
{
    ui->setupUi(this);
}

dataShow::~dataShow()
{
    delete ui;
}
void dataShow::Init()
{
    //getData();

}

bool dataShow::getData(void *pdata)
{
    g_data = (dataStruct *)decrypt(pdata);
    if( NULL == g_data ){
        return false;
    }
}
dataShow * dataShow::decrypt(void *pdata)
{
    bool ok;
   QString password = QInputDialog::getText(this,
                                            tr("Input passwd"),
                                            tr("Please input the file's password to decrypt this file"),
                                            QLineEdit::Password,
                                            NULL,
                                            &ok);
   if(!ok || password.isEmpty()){
        return NULL;
   }
   char * cdata;
   //password.toWCharArray(cdata);

}
void dataShow::encrypt(void *)
{

}
