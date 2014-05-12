#include "stringdemo.h"
#include <string>
#include <iostream>

using namespace std;


MyStr::MyStr()
{
    str = "This is a default string";
}

MyStr::MyStr(string s)
{
    str = s;
}

MyStr::~MyStr(void)
{
    cout << "Object is being deleted" << endl;
}

void MyStr::contStrings(string a)
{
    str = str + a;
}
void MyStr::eqvStrings(string a)
{
    str = a;
}

void MyStr::powerString(int n)
{
    if(n == 1)
        str = str;
    else {
    string sum = str;
    for(int i=1; i<n; ++i)
        sum = sum+str;
    str = sum;
    }
    printString();
}

void MyStr::contpStrings()
{
    str = str + str;
}

void MyStr::accessString(int i)
{
    cout << "The element at " << i << " position is " << str.at(i) << endl;
}

void MyStr::isEqual(string a)
{
    if(str == a)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are not equal" << endl;
}

void MyStr::isNotEqual(string a)
{
    if(str != a)
        cout << "Strings are not equal" << endl;
    else
        cout << "Strings are equal" << endl;
}

void MyStr::printString()
{
    cout << str << endl;
}

void MyStr::searchSym(char x)
{
    int i;
    int flag = 0;
    for(i=0;i<str.length();i++)
        if(str.at(i)==x) {
        cout << "An element " << x << " was found at position " << i << endl;
        flag = 1;
        }
    if(flag == 0)
        cout << "An element was not found in a string" << endl;
}

void MyStr::searchStr(string a)
{
    int i,j,l;
    for(l=0;a[l]!='\0';l++);    // finding the length of a substring

	for(i=0,j=0;str[i]!='\0'&& a[j]!='\0';i++)
		if(str[i]==a[j])
			j++;
		else
			j=0;

	if(j==l)
		cout << "Substring was found at position " << i-j+1 << endl;
	else
		cout << "Substring was not found" << endl;

}
void MyStr::printMenu(void)
{
    cout << "........................" << endl;
    cout << "What would you like to do?" << endl;
    cout << "Please enter 1 to put together two strings" << endl;
    cout << "Please enter 2 to make default string equal to some other string" << endl;
    cout << "Please enter 3 to add default string to a default string" << endl;
    cout << "Please enter 4 to access a symbol of a string" << endl;
    cout << "Please enter 5 to check whether sting 'a' is equal to a default string" << endl;
    cout << "Please enter 6 to repeat a sting 'n' times" << endl;
    cout << "Please enter 7 to print a sting" << endl;
    cout << "Please enter 8 to search for a symbol in a sting" << endl;
    cout << "Please enter 9 to search for a substring in a sting" << endl;
    cout << "Please enter 0 to quit" << endl;
}

