#include "dialog.h"
#include "ui_dialog.h"
#include <stdlib.h>
#include <time.h>
#include <QVector>

#define ROWS 20 // rows and columns in "ocean" matrix
#define COLS 20


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    setOcean();
    setStones();
    setPrey();
    setPredator();
    ui->setupUi(this);

    stone = QImage(":/new/prefix1/stone.jpg").scaled(30, 30);
    prey = QImage(":/new/prefix1/prey.jpg").scaled(30, 30);
    predator = QImage(":/new/prefix1/predator.jpg").scaled(30, 30);
    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(50);

    resize(30*COLS, 30*ROWS);

}

int flag[ROWS][COLS];	// each cell of an ocean has an assigned flag


void Dialog::setOcean()
{
    for (int i=0; i<20; i++)
        for (int j=0; j<20; j++)
            flag[i][j] = 0;
}


void Dialog::setStones()
{
    int stones = 10;
    while(stones>0) {
    int v, w;
    v = rand()%20;
    w = rand()%20;
    if(flag[v][w] == 0) {
    flag[v][w] = 1;
    stones--; }
    }
}

void Dialog::setPrey()
{
    int prey = 20;
    QVector <Prey> vPrey;
    while(prey>0) {
    int u, z;
    u = rand()%20;
    z = rand()%20;
    if(flag[u][z] == 0) {
        vPrey.push_back(Prey(u, z, 2));
        flag[u][z] = 2;
        prey--; }
    }
}


void Dialog::setPredator()
{
    int predn = 20;
    QVector <Predator> vPred;
    while(predn>0) {
    int v, w;
    v = rand()%20;
    w = rand()%20;
    if(flag[v][w] == 0) {
        vPred.push_back(Predator(v, w, 3));
        flag[v][w] = 3;
        predn--; }
    }
}

void Dialog::moveIt()
{

srand (time(NULL));
int randomDir = rand() % 4; // selecting a random direction from all available directions

int span = 0;

for(int i=0; i<20; i++)
   for(int j=0; j<20; j++)
     if(span<20) {


        if(flag[i][j] == 2)  // prey moves in random direction and procreates (when lifespan is 5)
        {
            if(randomDir == 0 && flag[i-1][j] == 0)  { // moving up
            flag[i][j] = 0;
            i--;
            flag[i][j] = 2;
            span++;
            if(span==5 && flag[i+1][j] == 0) {
                flag[i+1][j] = 2;
                vPrey.push_back(Prey(i+1, j, 2)); }
            return; }

            if(randomDir == 1 && flag[i+1][j] == 0) { // moving to the right
            flag[i][j] = 0;
            i++;
            flag[i][j] = 2;
            span++;
            if(span==5 && flag[i-1][j] == 0) {
                flag[i-1][j] = 2;
                vPrey.push_back(Prey(i-1, j, 2)); }
            return; }

            if(randomDir == 2 && flag[i][j+1] == 0) { // moving down
            flag[i][j] = 0;
            j++;
            flag[i][j] = 2;
            span++;
            if(span==5 && flag[i][j-1] == 0) {
                flag[i][j-1] = 2;
                vPrey.push_back(Prey(i, j-1, 2)); }
            return; }

            if(randomDir == 3 && flag[i][j-1] == 0) { // moving to the left
            flag[i][j] = 0;
            j--;
            flag[i][j] = 2;
            span++;
            if(span==5 && flag[i][j+1] == 0) {
                flag[i][j+1] = 2;
                vPrey.push_back(Prey(i, j+1, 2)); }
            return; }

        }

      if(flag[i][j] == 3) // predators eat prey, move in random direction and procreate
        {
            if(flag[i-1][j] == 2) {
                flag[i][j] = 0;
                i--;
                flag[i][j] = 3;
                span++;
                    if(span==5 && flag[i+1][j] == 0) {
                    flag[i+1][j] = 3;
                    vPred.push_back(Predator(i+1, j, 3)); }
                return; }
            if(flag[i+1][j] == 2) {
                flag[i][j] = 0;
                i++;
                flag[i][j] = 3;
                span++;
                    if(span==5 && flag[i-1][j] == 0) {
                    flag[i-1][j] = 3;
                    vPred.push_back(Predator(i-1, j, 3)); }
                return; }
            if(flag[i][j-1] == 2) {
                flag[i][j] = 0;
                j--;
                flag[i][j] = 3;
                span++;
                    if(span==5 && flag[i][j+1] == 0) {
                    flag[i][j+1] = 3;
                    vPred.push_back(Predator(i, j+1, 3)); }
                return; }
            if(flag[i][j+1] == 2) {
                flag[i][j] = 0;
                j++;
                flag[i][j] = 3;
                span++;
                    if(span==5 && flag[i][j-1] == 0) {
                    flag[i][j-1] = 3;
                    vPred.push_back(Predator(i, j-1, 3)); }
                return; }

            if(randomDir == 0 && flag[i-1][j] == 0)  { // moving up
            flag[i][j] = 0;
            i--;
            flag[i][j] = 3;
            span++;
            if(span==5 && flag[i+1][j] == 0) {
                flag[i+1][j] = 3;
                vPred.push_back(Predator(i+1, j, 3)); }
            return; }

            if(randomDir == 1 && flag[i+1][j] == 0) { // moving to the right
            flag[i][j] = 0;
            i++;
            flag[i][j] = 2;
            span++;
            if(span==5 && flag[i-1][j] == 0) {
                flag[i-1][j] = 3;
                vPred.push_back(Predator(i-1, j, 3)); }
            return; }

            if(randomDir == 2 && flag[i][j+1] == 0) { // moving down
            flag[i][j] = 0;
            j++;
            flag[i][j] = 2;
            span++;
            if(span==5 && flag[i][j-1] == 0) {
                flag[i][j-1] = 3;
                vPred.push_back(Predator(i, j-1, 3)); }
            return; }

            if(randomDir == 3 && flag[i][j-1] == 0) { // moving to the left
            flag[i][j] = 0;
            j--;
            flag[i][j] = 2;
            span++;
            if(span==5 && flag[i][j+1] == 0) {
                flag[i][j+1] = 3;
                vPred.push_back(Predator(i, j+1, 3)); }
            return; }
     }
}

else {          // natural death of prey and predators when the life cycle is over
    flag[i][j] = 0;
    return;

}

}



void Dialog::paintEvent(QPaintEvent *event)
{

    moveIt();

    QPainter painter (this);
    for (int i=0; i<20; i++)
        for (int j=0; j<20; j++)
            if (flag[i][j] == 1)
                painter.drawImage(j*30, i*30, stone);
            else if (flag[i][j] == 2)
                painter.drawImage(j*30, i*30, prey);
            else if (flag[i][j] == 3)
                painter.drawImage(j*30, i*30, predator);
}

Dialog::~Dialog()
{
    delete ui;
}


Stone::Stone(int a, int b, int c, int d)
{
    num = d;
    x = a;
    y = b;
    fls = c;
}

void Dialog::setFlag(int a, int b, int c)
{
int i, j;
    for(i=0; i<ROWS; i++)
        for(j=0; j<COLS; j++)
                {
            if(i==a && j==b)
                flag[i][j] = c;
            }
}


Prey::Prey(int a, int b, int c)
{
    xp = a;
    yp = b;
    flp = c;
}

void Prey::setFlag(int a, int b, int c)
{
int i, j;
    for(i=0; i<ROWS; i++)
        for(j=0; j<COLS; j++)
                {
            if(i==a && j==b)
                flag[i][j] = c;
            }
}



Predator::Predator(int a, int b, int c)
{
    xpr = a;
    ypr = b;
    flpr = c;
}

void Predator::setFlag(int a, int b, int c)
{
int i, j;
    for(i=0; i<ROWS; i++)
        for(j=0; j<COLS; j++)
                {
            if(i==a && j==b)
                flag[i][j] = c;
            }
}
