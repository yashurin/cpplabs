#include "automata.h"
#include <iostream>
#include <cstring>
#include <unistd.h>

using namespace std;

void Automata::printMenu()
{
cout << "What would you like to order?" << endl;

for(int i=0;i<NUMDRINKS;i++)
    cout << "Enter " << i+1 <<" to order " << drinks[i] << endl;

cout << "Enter 0 to exit" << endl;

}

void Automata::Cooking()
{
cout << "Your order is accepted!" << endl;
cout << "Cooking... Please wait" << endl;
sleep(10);
cout << "Now you can take your order" << endl;
sleep(5);
cout << "..................." << endl;
}

void Automata::Payment(int n)
{
int i, sum;
cout << "Please insert " << n << " roubles. You can use coins of 1, 2, 5, or 10 roubles. Enter 0 to cancel the operation" << endl;
cin >> i;
sum=i;
if(i!=0) {
        while(sum<n && i!=0) {
            cout << "Please add more money, or enter 0 to cancel your order" << endl;
            cin >> i;
            sum+=i;
            }
        if(i==0) {
        cout << "Your order have been cancelled" << endl;
        cout << "Please take back " << sum << " roubles" << endl;
        cout << "..................." << endl;
        }
        if(sum==n) {
            Cooking();
        }
        if (sum>n) {
            cout << "Your change is " << sum-n << " roubles" << endl;
            Cooking();
        }


}
else {
cout << "Your order has been canceled" << endl;
cout << "..................." << endl;
}
}



void Automata::makeChoice(int n)
{

    if(n!=0) {
        cout << "You've ordered " << drinks[n-1]<< endl;
        int cprice = prices[n-1];
        Payment(cprice);
        printMenu();
        cin >> n;
        makeChoice(n); }

}

// More drinks can be easily added

int Automata::prices[NUMDRINKS] = {11, 13, 15};

const char *Automata::drinks[] = { "tea", "espresso", "capuccino" };
