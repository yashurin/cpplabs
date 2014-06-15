#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QtCore>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private:
    enum {N=5};
    struct Stud
    {
        QString id;
        QString card1;
        QString name;
        QString year;
        QString spec;
        QString avgrade;
    };

    QList <QImage> img_list;
    QList <Stud> data;
    QImage img_cur;
    int index;

    QPushButton *next;
    QPushButton *prev;
    QLabel * label;
    QTextEdit * text;
    Ui::Dialog *ui;
    QVBoxLayout * vlay;
    QHBoxLayout * hlay;

    void readMyXML(void);

private slots:
    void slotNext();
    void slotPrev();
};


#endif // DIALOG_H
