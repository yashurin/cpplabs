#ifndef _STRINGDEMO_H_
#define _STRINGDEMO_H_

#include <string>

using namespace std;

class MyStr {
    public:
    MyStr();
    MyStr(string);
    MyStr(const MyStr &c);
    ~MyStr();
    void contStrings(string);   // + operation
    void eqvStrings(string);    // = operation
    void contpStrings();        // += operation
    void accessString(int);
    void isEqual(string);       // check for equality ==
    void isNotEqual(string);    // check for non-equality !=
    void powerString(int);      // ^ string to the power of...
    void printString();
    void searchSym(char);
    void searchStr(string);     // searching for a substring within a default strin

    void printMenu();

    private:
    string str;

};

#endif
