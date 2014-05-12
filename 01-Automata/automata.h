#ifndef _AUTOMATA_H_
#define _AUTOMATA_H_

#define NUMDRINKS 3 // The number of drinks on the menu. Can be easily changed if necessary.

using namespace std;

class Automata
{
    public:
    void printMenu();
    void Cooking();
    void Payment(int);
    void makeChoice(int);

    private:
    static int prices[];
    static const char *drinks[];
};

#endif
