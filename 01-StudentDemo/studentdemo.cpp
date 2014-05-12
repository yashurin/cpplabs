#include "studentdemo.h"
#include <iostream>
#include <string>

using namespace std;

void clean(void)
{
	while (cin.get() != '\n')
		;
}

void Student::setName()
{
	cout << "Please enter the name of the student: " << endl;
	clean();
	getline(cin, studentName);
	cout << "The name of the student is: " << studentName << endl;
}

void Student::setGrades()
{
	cout << "Enter the number of exams: " << endl;
	cin >> numex;
	grades = new int [numex];
	cout << "Enter " << numex << " grades" << endl;
	for (int i = 0; i < numex; ++i)
        cin >> grades[i];
    clean();
}

double Student::calcAvgrade()
{
    int sum = 0;
    double avg;
    for (int i = 0; i < numex; ++i)
        sum = sum + grades[i];

    avg = (double)sum / (double)numex;
    return avg;
}

void Student::printStudent()
{
	cout << "The name of the student: " << studentName << endl;
}

void Student::printGrades()
{
    cout << "The grades of the student: ";
    for (int i = 0; i < numex; ++i)
        cout << grades[i] << " ";
    cout << endl;
}

Group::Group()
{
    cout << "A new group has been created" << endl;
}

int Group::setNumber(int number)
{
    return number;
}

void Group::addStudent(int number)
{
	st[number].setName();
	st[number].setGrades();
	cout << "The student was successfully added" << endl;
}

void Group::removeStudent(int count)
{
    cout << "Enter the student's name: " << endl;
    clean();
    string temp;
	int fl = -1;
	getline(cin, temp);
	for(int i=1; i<count; i++)
        if (st[i].getStudentName() == temp) {
            cout << "A matching name was found" << endl;
			fl = i;
			break;
            }
    if (fl == -1) {
	cerr << "The student cannot be removed" << endl;
        return;
    }
	st[fl] = st[count-1];
    cout << "The student was successfully removed" << endl;
}

void Group::printGroup(int count)
{
    cout << "Students in the group: " << endl;
    cout << "...................." << endl;
	for(int i=1;i<count; i++) {
        st[i].printStudent();
        st[i].printGrades();
        cout << "The average grade of a student is " << st[i].calcAvgrade() << endl;
        cout << "...................." << endl;
        }
}

void Group::avGroupGrade(int count)
{
    int j;
    double avgg;
    double sum = 0;
    for(j=1;j<count; j++) {
        sum = sum + st[j].calcAvgrade();
    }
    avgg = sum / (double)(j-1);
    cout << "The average grade of a group is " << avgg << endl;

}




void Group::printMenu()
{
    cout << "What would you like to do?" << endl;
    cout << "To add a student to a group, enter 1" << endl;
    cout << "To remove a student from a group, enter 2" << endl;
    cout << "To calculate the average grade of a group. enter 3" << endl;
    cout << "To print all students. enter 4" << endl;
    cout << "Please enter 0 to quit" << endl;
}



