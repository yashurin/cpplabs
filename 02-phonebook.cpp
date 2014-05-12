// This is just a console application

#include <iostream>
#include <string>
#include <map>

using namespace std;

void printMenu()
{
    cout << "What you would like to do?" << endl;
    cout << "To add a new phone number, enter 1" << endl;
    cout << "To find a person's phone, enter 2" << endl;
    cout << "To delete a person from the phonebook, enter 3" << endl;
    cout << "To view all people in your phonebook, enter 4" << endl;
    cout << "To quit, enter 0" << endl;
}

int main()
{
int n;
string phone, name;
map< string, string > phonebook;

printMenu();
cin >> n;
while (n!=0)
{
    if(n==1) {
        cout << "Please enter a person's name: " << endl;
        cin >> name;
        cout << "Please enter a person's phone number: " << endl;
        cin >> phone;
        phonebook[ name ] = phone;
        cout << "The phone number was added" << endl;
        printMenu();
        cin >> n; }
    if(n==2) {
        cout << "Please enter a person's name: " << endl;
        cin >> name;
        map< string, string >::const_iterator ifind = phonebook.find( name );

        if ( ifind != phonebook.end() )
            cout << ifind->first << "'s phone number is " << ifind->second << endl;
        else
            cout << name << " was not found in a phonebook" << endl;

        printMenu();
        cin >> n; }
    if(n==3) {
        cout << "Please enter a person's name: " << endl;
        cin >> name;
        phonebook.erase( name );
        cout << "This person was deleted from your phone book" << endl;
        printMenu();
        cin >> n; }
    if(n==4) {
        map< string, string >::const_iterator i;

        for( i = phonebook.begin(); i != phonebook.end() ; ++i )
            cout << i->second << "\t " << i->first << endl;
        printMenu();
        cin >> n; }

    if(n==0)
        break;

}

    cout << "Goodbye" << endl;

    return 0;
}

