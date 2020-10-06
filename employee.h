// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
public:
    Employee(int id = 0,
             string name = "NO_NAME",
             double salary = 0,
             int work_hour = 0,
             string position = "UNASSIGNED",
             double rate = 1.0) : id_(id),
                                  name_(name),
                                  salary_(salary),
                                  work_hour_(work_hour),
                                  position_(position),
                                  rate_(rate) {}
    operator string() { return name_; }
    operator int() { return id_; }
    operator double() { return salary_; }
    inline friend ostream &operator<<(ostream &out, Employee person)
    {
        out << setw(10) << person.name_ << setw(10) << person.id_ << setw(25) << person.position_ << setw(10) << person.work_hour_ << setw(10) << person.salary_;
        return out;
    }
    void set_rate(double rate)
    {
        rate_ = rate;
    }
    friend class Department;

private:
    int id_;
    double salary_;
    int work_hour_;
    string position_;
    string name_;
    double rate_; //should be between 0.5 and 1.5
};

#endif
