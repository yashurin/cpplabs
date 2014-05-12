#include "stringdemo.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void clean(void)
{
	while (cin.get() != '\n')
		;
}

int main()
{

    MyStr one;

one.printMenu();
int n;
cin >> n;
while (n!=0)

{
    if(n==1) {
        string temp;
        cout << "Please enter a string: " << endl;
        clean();
        getline(cin, temp);
        one.contStrings(temp);
        cout << "Two strings together: " << endl;
        one.printString();
        one.printMenu();
        cin >> n; }
    if(n==2) {
        string temp;
        cout << "Please enter a string: " << endl;
        clean();
        getline(cin, temp);
        one.eqvStrings(temp);
        cout << "Here is now the new default string: " << endl;
        one.printString();
        one.printMenu();
        cin >> n; }
    if(n==3) {
        one.contpStrings();
        cout << "Here is how a default string plus a default string looks like: " << endl;
        one.printString();
        one.printMenu();
        cin >> n; }
    if(n==4) {
        int num;
        cout << "Please enter a position in a string you want to access: " << endl;
        cin >> num;
        one.accessString(num);
        one.printMenu();
        cin >> n; }
    if(n==5) {
        string temp;
        cout << "Please enter a string: " << endl;
        clean();
        getline(cin, temp);
        one.isEqual(temp);
        one.printMenu();
        cin >> n; }
    if(n==6) {
        int num;
        cout << "Enter the number of times you want string to be repeated: " << endl;
        cin >> num;
        cout << num << endl;
        one.powerString(num);
        one.printMenu();
        cin >> n; }
    if(n==7) {
        one.printString();
        one.printMenu();
        cin >> n; }
    if(n==8) {
        char ch;
        cout << "Please enter a character to look for in a string: " << endl;
        cin >> ch;
        one.searchSym(ch);
        one.printMenu();
        cin >> n; }
    if(n==9) {
        string temp;
        cout << "Please enter a substring: " << endl;
        clean();
        getline(cin, temp);
        one.searchStr(temp);
        one.printMenu();
        cin >> n; }
    if(n==0)
        break;

}

    cout << "Goodbye!" << endl;

    return 0;
}
