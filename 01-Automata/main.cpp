#include "automata.h"
#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;


int main()
{

    Automata current;

    int m, n;

    cout << "The Machine is OFF. Enter 1 to turn on the Machine" << endl;

    cin >> m;

    if(m==1)
    {
    cout << "Hello! The Machine is ON." << endl;

    current.printMenu();

    cin >> n;

    if(n!=0)
        current.makeChoice(n);

    cout << "Goodbye! The Machine is OFF" << endl;
    }

    return 0;
}
