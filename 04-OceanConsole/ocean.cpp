#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20 // rows and columns in "ocean" matrix
#define COLS 20

using namespace std;

int flag[ROWS][COLS];	// each cell of an ocean has an assigned flag

void printOcean()
{
	
for(int i=0; i<ROWS; i++)
    {
    for(int j=0; j<COLS; j++)
        {  
			if(flag[i][j] == 0)   // flag 0 is for empty spaces
                cout << " " << " " << " ";
           if(flag[i][j] == 1)   // flag 1 is for stones
                cout << " " << "H" << " ";
            if(flag[i][j] == 2)   // flag 2 is for prey
                cout << " " << "O" << " ";
            if(flag[i][j] == 3)   // flag 3 is for predators
                cout << " " << "X" << " "; 
                
                }

        cout << endl;
    }	
}
class Stone
{
public:
    Stone(int, int, int, int);
    ~Stone() {}
	void setFlag(int, int, int); // set coordinates of a stone
private:
	int num;
	int fls;
	int x;	// coordinates
    int y;
};

class Prey
{
public:
    Prey(int, int, int, int);
    ~Prey() {}
	void setFlag(int, int, int); // set flag of a prey
	void setCoord(int, int);	// set coordinates of a prey
	void moveIt();	// random movement of a prey to a free space
	int whatsLeft(); // how long prey is going to live
	int getX();
	int getY();
private:
	int nump;
	int lspn; // life span of a prey
	int flp;
	int xp;	// coordinates
    int yp;
};

class Predator
{
public:
    Predator(int, int, int, int);
    ~Predator() {}
    void setFlag(int, int, int); // set flag of a predator
    void setCoord(int, int); // set coordinates of a predator	
    void moveTo(); // predator can move to a free space or to eat prey
    int whatsLeft(); // how long predator is going to live
    int getX();
    int getY();
private:
	int numpr;
    int lspnp;   // life span of a predator
    int flpr;
    int xpr;	// coordinates
    int ypr;
};

Stone::Stone(int a, int b, int c, int d)
{
    num = d;
	x = a;
	y = b;
	fls = c;
}

void Stone::setFlag(int a, int b, int c)
{
int i, j;
    for(i=0; i<ROWS; i++)
        for(j=0; j<COLS; j++)
                {
            if(i==a && j==b)
                flag[i][j] = c;
            }
}

Prey::Prey(int a, int b, int c, int d)
{
	xp = a;	
	yp = b;
	lspn = 10;
	flp = c;
    nump = d;
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

void Prey::moveIt()
{
srand (time(NULL));
int randomDir = rand() % 4; // selecting a random direction from all available directions

if(lspn>0) {	
	if(randomDir == 0 && yp!=0 && flag[xp][yp-1] == 0) { // moving up
		setFlag(xp, yp, 0);
		yp = yp - 1;
		setFlag(xp, yp, 2); }	
	if(randomDir == 1 && xp!=ROWS-1 && flag[xp+1][yp] == 0) { // moving to the right
		setFlag(xp, yp, 0);
		xp = xp + 1;
		setFlag(xp, yp, 2); }	 
	if(randomDir == 2 && yp!=COLS-1 && flag[xp][yp+1] == 0) { // moving down
		setFlag(xp, yp, 0);
        yp = yp + 1;
        setFlag(xp, yp, 2); }	 
	if(randomDir == 3 && xp!=0 && flag[xp-1][yp] == 0) { // moving to the left
		setFlag(xp, yp, 0);
		xp = xp - 1;
		setFlag(xp, yp, 2); }	
	lspn--;
	} 	
if(lspn == 0) {
	setFlag(xp, yp, 0); }	
}


void Prey::setCoord(int a, int b)
{
	xp = a;	
	yp = b;
}

int Prey::whatsLeft()
{
	return lspn;
}

int Prey::getX()
{
	return xp;
}
int Prey::getY()
{
	return yp;
}

Predator::Predator(int a, int b, int c, int d)
{
	xpr = a;	
	ypr = b;
	lspnp = 10;
	flpr = c;
    numpr = d;
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

void Predator::setCoord(int a, int b)
{
	xpr = a;	
	ypr = b;
}

void Predator::moveTo()
{
if(lspnp>0) {	

// If prey is available, predator eats prey

if(flag[xpr][ypr-1] == 2) {
	setFlag(xpr, ypr, 0);
	ypr = ypr - 1;
	setFlag(xpr, ypr, 3); 
	}	
if(flag[xpr][ypr+1] == 2) {
	setFlag(xpr, ypr, 0);
		xpr = xpr + 1;
		setFlag(xpr, ypr, 3); }	
if(flag[xpr+1][ypr] == 2) {
		setFlag(xpr, ypr, 0);
        ypr = ypr + 1;
        setFlag(xpr, ypr, 3);
	}
if(flag[xpr-1][ypr] == 2) {
	setFlag(xpr, ypr, 0);
		xpr = xpr - 1;
		setFlag(xpr, ypr, 3); }	
		
// If prey is not available, predator moves randomly

srand (time(NULL));
int randomDir = rand() % 4; // selecting a random direction from all available directions

	if(randomDir == 0 && ypr!=0 && flag[xpr][ypr-1] == 0) { // moving up
		setFlag(xpr, ypr, 0);
		ypr = ypr - 1;
		setFlag(xpr, ypr, 3); }	
	if(randomDir == 1 && xpr!=ROWS-1 && flag[xpr+1][ypr] == 0) { // moving to the right
		setFlag(xpr, ypr, 0);
		xpr = xpr + 1;
		setFlag(xpr, ypr, 3); }	 
	if(randomDir == 2 && ypr!=COLS-1 && flag[xpr][ypr+1] == 0) { // moving down
		setFlag(xpr, ypr, 0);
        ypr = ypr + 1;
        setFlag(xpr, ypr, 3); }	 
	if(randomDir == 3 && xpr!=0 && flag[xpr-1][ypr] == 0) { // moving to the left
		setFlag(xpr, ypr, 0);
		xpr = xpr - 1;
		setFlag(xpr, ypr, 3); }	
	lspnp--;
	} 	
if(lspnp == 0) {
	setFlag(xpr, ypr, 0); }
		
}

int Predator::whatsLeft()
{
	return lspnp;
}

int Predator::getX()
{
	return xpr;
}
int Predator::getY()
{
	return ypr;
}


int countFlags(int a)
{
	int flags = 0;
	int i, j;
    for(i=0; i<ROWS; i++)
        for(j=0; j<COLS; j++)
                {
				if(flag[i][j] == a)
                flags++;
				}
		return flags;
}



int main()
{

int stone, prey, predator;
cout << "Enter the number of stones in the ocean (10-20 is recommended): " << endl;
cin >> stone;
cout << "Enter the number of prey in the ocean (10-20 is recommended): " << endl;
cin >> prey;
cout << "Enter the number of predators in the ocean (5-10 is recommended): " << endl;
cin >> predator;

for(int i=0; i<ROWS; i++)
	for(int j=0; j<COLS; j++)
		flag[i][j] = 0;
	
printOcean();



//int stone = 10;

vector<Stone> vStone;

while(stone>0)
{
    int v, w;
    v = rand()%ROWS;
    w = rand()%COLS;
	if(flag[v][w] == 0) {
        vStone.push_back(Stone(v, w, 1, stone));
        vStone[stone].setFlag(v, w, 1);
        stone--;
       }
 }
 
//int prey = 10;

vector<Prey> vPrey;

while(prey>0)
{
	int x, y;
    x = rand()%ROWS;
    y = rand()%COLS;
	if(flag[x][y]==0) {
		vPrey.push_back(Prey(x, y, 2, prey));   
		vPrey[prey].setFlag(x, y, 2);   
        prey--;
       }
}

//int predator = 5;

vector<Predator> vPred;

while(predator>0)
{
    int k, l;
    k = rand()%ROWS;
    l = rand()%COLS;
	if(flag[k][l]==0) {
        vPred.push_back(Predator(k, l, 3, predator));
        vPred[predator].setFlag(k, l, 3);
        predator--;
       }
 }

cout << "Initial setup of the ocean is complete" << endl;

cout << "-----------------------------------------------------------------" << endl;

printOcean();

// Life of an ocean

int term = 50; // Life cycles available

do {
unsigned int i, j;

// Prey move

for (i=0; i<vPrey.size(); i++)  {
	vPrey[i].moveIt();	

// Prey procreate

if(vPrey[i].whatsLeft() == 3) {
int a, b;
a = vPrey[i].getX();
b = vPrey[i].getY();

if(flag[a+1][b] == 0)
	vPrey.push_back(Prey(a+1, b, 2, vPrey.size()));
else if(flag[a-1][b] == 0)
	vPrey.push_back(Prey(a-1, b, 2, vPrey.size()));
else if(flag[a][b+1] == 0)
	vPrey.push_back(Prey(a, b+1, 2, vPrey.size()));
else if(flag[a][b-1] == 0)
	vPrey.push_back(Prey(a, b-1, 2, vPrey.size()));
else
	continue;
} 
}

sleep(1);

// Predators move

for (j=0; j<vPred.size(); j++)  {
	vPred[j].moveTo();	

// Predators procreate

if(vPred[j].whatsLeft() == 3) {

int c, d;
c = vPred[j].getX();
d = vPred[j].getY();

if(flag[c+1][d] == 0)
	vPred.push_back(Predator(c+1, d, 3, vPred.size()));
else if(flag[c-1][d] == 0)
	vPred.push_back(Predator(c-1, d, 3, vPred.size()));
else if(flag[c][d+1] == 0)
	vPred.push_back(Predator(c, d+1, 3, vPred.size()));
else if(flag[c][d-1] == 0)
	vPred.push_back(Predator(c, d-1, 3, vPred.size()));
else
	continue;  

		}

}

sleep(1);

cout << "-----------------------------------------------------------------" << endl;	
	printOcean();
cout << "-----------------------------------------------------------------" << endl;	

	
	term--;
	cout << "Life cycles available: " << term << endl;
	cout << "The number of prey: " << countFlags(2) << endl;
	cout << "The number of predators: " << countFlags(3) << endl;


	
} while(term>0);


	return 0;
	
}

