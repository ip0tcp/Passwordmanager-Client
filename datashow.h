#ifndef DATASHOW_H
#define DATASHOW_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#define PASSWD_LEN 255
#define USERNAME_LEN 64
#define DESCRIPT_LEN 255
#define USE_ON_LEN 128

typedef  struct {
    unsigned int no;
    char passwd[PASSWD_LEN];
    char username[USERNAME_LEN];
    char descript[DESCRIPT_LEN];
    char useon[USE_ON_LEN];
    }dataStruct;

namespace Ui {
class dataShow;
}

class dataShow : public QWidget
{
    Q_OBJECT

public:
    explicit dataShow(QWidget *parent = 0);
    ~dataShow();
     void Init();
     bool getData(void *);
     void encrypt(void *);
     void refresh();
     dataShow * decrypt(void *);

protected:
    dataStruct  * g_data;
    unsigned int g_dataSize = sizeof (dataStruct);

private:
    Ui::dataShow *ui;
};

#endif // DATASHOW_H

