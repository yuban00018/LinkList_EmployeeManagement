// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee(int id = 0, string name = "NO_NAME", int salary = 0, int work_hour = 0, string position = "UNASSIGNED", double rate = 1.0) : id_(id), name_(name), salary_(salary), work_hour_(work_hour), position_(position), rate_(rate)
    {
        cout << "Employee build success" << endl;
    }
    inline friend ostream &operator<<(ostream &out, Employee person)
    {
        out << "ID: " << person.id_ << endl
            << "NAME: " << person.name_ << endl
            << "SALARY: " << person.salary_ << endl
            << "WORK_HOUR: " << person.work_hour_ << endl;
        return out;
    }

private:
    int id_;
    int salary_;
    int work_hour_;
    string position_;
    string name_;
    double rate_; //should be between 0.5 and 1.5
};

#endif