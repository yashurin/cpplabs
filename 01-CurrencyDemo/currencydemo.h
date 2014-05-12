#ifndef _CURRENCYDEMO_H_
#define _CURRENCYDEMO_H_

using namespace std;

class Currency
{
    public:
    Currency(int a, int b);
    Currency();
    Currency(const Currency &);
    double getBalance(int rub, int kop);
    void printMenu(void);
    void printBalance(double rubl);
    double addRoubles(double rubl);
    double removeRoubles(double rubl);
    void convertToDollars(double rubl);
    void convertToEuros(double rubl);
    void makeChoice(int n, double rubl);

    private:
    int rub;
    int kop;
    double rubl;
};


#endif

