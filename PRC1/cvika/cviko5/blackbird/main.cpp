#include <iostream>
#include "user.h"

using namespace std;

void sendMail(User *userPtr, string message)
{
    cout << "Sending message\n\n"
         << message
         << "\n\nto the user: \n";
    userPtr->print();
}

int main()
{
    string name, surname;
    int credits, officeNumber;
    char choice;
    User *u;
    cout << "Welcome to the BLACKBIRD 3000" << endl;
    cout << "Let's create a new user!\n";
    cout << "Do you wish to create a new (s)tudent or an (e)mployee?\n";
    cin >> choice;

    cout << "Please, enter name: ";
    cin >> name;
    cout << "Please, enter surname: ";
    cin >> surname ;

    if(choice == 's')
    {
        cout << "Please enter initial count of credits: ";
        cin >> credits;
        u = new Student(name, surname, credits);
    } else {
        cout << "Please, enter office number: ";
        cin >> officeNumber;
        u = new Employee(name, surname, officeNumber);

    }

    sendMail(u, "Welcome to the University");

    delete u;
    return 0;
}