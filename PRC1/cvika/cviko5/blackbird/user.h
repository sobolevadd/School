#ifndef USER_H
#define USER_H

#include <string>

using std::string; //imports single symbol

class User
{
protected:
    string name;
    string surname;
    int uid;
    //TODO - must return unique value
    int generateUid(){
        return 42;
    }
    void printCommon() const;
public:
    User(string name, string surname);
    virtual ~User();
    string getName() const{return name;}
    string getSurname() const{return surname;}
    int getUid() const{return uid;}
    void setSurname(string newSurname){
        surname = newSurname;
    } 
    virtual void print() const;
}; 

class Student : public User {
protected:
    int credits;
public:
    Student(string n, string s, int c);
    virtual ~Student();
    int getCredits() const {return credits;}
    virtual void print() const;
};

class Employee : public User{
protected:
    int officeNumber;
public: 
    Employee(string n, string p, int num);
    virtual ~Employee();
    int getOfficeNumber() const{return officeNumber;}
    void setOfficeNumber(int newOfficeNumber){officeNumber = newOfficeNumber;}
    virtual void print() const;
};

#endif //USER_H