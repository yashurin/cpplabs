#ifndef _STUDENTDEMO_H_
#define _STUDENTDEMO_H_

#include <string>

using namespace std;

class Student
{
    public:
    Student() {}
 //   ~Student();
    void setName();         // input name of a student
    void setGrades();       // input grades of a student
    double calcAvgrade(); // calculate the average grade of a student
    const string & getStudentName() { return studentName; } // access student name

    void printStudent();
    void printGrades();

    private:
    string studentName; // the name of a student
    int numex;          // the number of exams
    int * grades;       // grades for all the exams
    double avGrade;     // the average grade

};

class Group
{
    public:
    Group();
    void addStudent(int);
    void removeStudent(int);
    int setNumber(int);     // method for setting the initial number
    void printGroup(int);   // print all the students in a group
    void avGroupGrade(int); // calculate and print the avegage grade of a group
    void printMenu();

    private:
    int number;         // the initial number
    int count;          // counter for the actual number of students in a group
    enum {NUM = 25};    // the maximum number of students in a group
    Student st[NUM];

};

#endif

