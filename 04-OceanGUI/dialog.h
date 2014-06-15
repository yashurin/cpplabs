#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QtCore>
#include <QVector>

namespace Ui {
class Dialog;
}

class Stone
{
public:
    Stone(int, int, int, int);
    ~Stone() {}
private:
    int num;
    int fls;
    int x;	// coordinates
    int y;
};

class Prey
{
public:
    Prey() {}
    Prey(int, int, int);
    ~Prey() {}
    void setFlag(int, int, int); // set flag of a prey

private:
    int flp;
    int xp;	// coordinates
    int yp;
};

class Predator
{
public:
    Predator() {}
    Predator(int, int, int);
    ~Predator() {}
    void setFlag(int, int, int); // set flag of a predator

private:
    int flpr;
    int xpr;	// coordinates
    int ypr;
};

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setupLab();

    void setFlag(int, int, int);
    QVector <Prey> vPrey;
    QVector <Predator> vPred;

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;

    void setOcean();
    void setStones();
    void setPrey();
    void setPredator();
    void moveIt();


    QImage stone;
    QImage prey;
    QImage predator;

    QTimer * timer;

};



#endif // DIALOG_H
