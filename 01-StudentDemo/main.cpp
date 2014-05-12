#include "studentdemo.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

int j;

Group gr;

j=gr.setNumber(1);

gr.printMenu();
int n;
cin >> n;
while (n!=0)
{
    if(n==1) {
        gr.addStudent(j);
        j++;
        gr.printMenu();
        cin >> n; }
    if(n==2) {
        gr.removeStudent(j);
        j--;
        gr.printMenu();
        cin >> n; }
    if(n==3) {
        gr.avGroupGrade(j);
        gr.printMenu();
        cin >> n; }
    if(n==4) {
        gr.printGroup(j);
        gr.printMenu();
        cin >> n; }
    if(n==0)
        break;
}
    cout << "Goodbye!" << endl;

    return 0;
}
