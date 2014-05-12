// This application reads phonebook from a file and writes it to a file

#include <iostream>
#include <fstream> //add
#include <string>
#include <map>
#include <algorithm>

#define FNAME "book.txt" // file where the phonebook is stored

using namespace std;

typedef pair<string, string> PairPh;
typedef map<string,string> phonebook;

void show(const PairPh & p)
{
    cout << "Phone number: " << p.first << "\tName: " << p.second << endl;
}
void printMenu()
{
    cout << "What you would like to do?" << endl;
    cout << "To add a new phone number, enter 1" << endl;
    cout << "To find a person's phone, enter 2" << endl;
    cout << "To delete a person's number from the phonebook, enter 3" << endl;
    cout << "To view all people in your phonebook, enter 4" << endl;
    cout << "To quit, enter 0" << endl;
}

void clean(void)
{
    while (cin.get() != '\n')
        ;
}

void update(phonebook & one)
{
    phonebook::iterator it;
    ofstream out;
    out.open(FNAME);
    if (!out)
    {
        cerr << "File cannot be opened\n" << endl;
        exit (EXIT_FAILURE);
    }
    for (it = one.begin(); it != one.end(); it++)
        out << it->first << " " << it->second << endl;
    out.close();
}

int main()
{
    phonebook one;

    fstream f(FNAME);

    phonebook::iterator it;
    ifstream in;
    string phone, name;

    in.open(FNAME);
    if(!in)
    {
        cerr << "File cannot be opened\n" << endl;
        return 1;
    }
    while(in)
    {
        in >> phone >> name;  // Getting information from existing phonebook
        one.insert(PairPh(phone, name));
    }
    in.close();

    update(one);

int n;
printMenu();
cin >> n;
while (n!=0)
{
    if(n==1) {

        cout << "Please enter a person's name: " << endl;
        cin >> name;
        clean();
        cout << "Please enter a person's phone number: " << endl;
        cin >> phone;
        one.insert(PairPh(phone, name));
        update(one);
        cout << "The phone number was added" << endl;
        printMenu();
        cin >> n; }
    if(n==2) {
        cout << "Please enter a person's name: " << endl;
        string temp;
        cin >> temp;
        for (it = one.begin(); it != one.end(); ++it) {
        if (it->second == temp) {
            cout << it->first << " " << it->second << endl;
            break; }
        else {
            cout << temp << " was not found in a phonebook" << endl;
            break; }
            }
        printMenu();
        cin >> n; }
    if(n==3) {
        cout << "Please enter a person's phone number: " << endl;
        cin >> phone;
        one.erase(phone);
            cout << "The number was successfully deleted from your phonebook" << endl;
        update(one);
        printMenu();
        cin >> n; }
    if(n==4) {
        for_each(one.begin(), one.end(), show);
        printMenu();
        cin >> n; }

    if(n==0)
        break;

}

    return 0;
}
