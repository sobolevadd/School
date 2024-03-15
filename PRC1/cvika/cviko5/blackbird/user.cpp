#include "user.h"
#include <iostream>

using std::cout;
using std::endl;

User::User(string n, string s)
    : name(n), surname(s), uid(generateUid())
{
    cout << "User constructor\n";
}

Student::Student(string n, string s, int c)
    : User(n, s), credits(c)
{
    cout << "Student constructor\n";
}

Employee::Employee(string n, string s, int num)
    : User(n, s), officeNumber(num)
{
    cout << "Employee constructor\n";
}

User::~User(){
    cout << "User destructor\n";
}

Student::~Student(){
    cout << "Student destructor\n";
}

Employee::~Employee(){
    cout << "Employee destructor\n";
}

void User::print() const{
    cout << "Role: user\n";
    User::printCommon();
}

void User::printCommon() const{
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Uid: " << uid << endl;
}

void Student::print() const{
    cout << "Role: student\n";
    User::printCommon();
    cout << "Credits: " << credits << endl;
}

void Employee::print() const{
    cout << "Role: employee\n";
    printCommon();
    cout << "Office number: " << officeNumber << endl;
}