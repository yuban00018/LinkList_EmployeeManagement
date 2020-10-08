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
    operator double()
    {
        return work_hour_ - 8 > 0 ? (work_hour_ - 8) * salary_ * rate_ + salary_ * 8 : work_hour_ * salary_;
    }
    inline friend ostream &operator<<(ostream &out, Employee person)
    {
        //out << setw(10) << person.name_ << setw(10) << person.id_ << setw(25) << person.position_ 
        //    << setw(10) << person.work_hour_ << setw(10) << person.salary_;
        out << '\t' << person.name_ << '\t' << person.id_ << '\t' << person.position_
                << '\t' << person.work_hour_ << '\t' << person.salary_ ;
        return out;
    }
    // Doing
    inline friend istream &operator>>(istream& in, Employee person)
    {
        char str[100];
        //cin >> setw(10) >> person.name_ >> setw(10) >> person.id_ >> setw(25) >> person.position_ 
        //    >> setw(10) >> person.work_hour_ >> setw(10) >> person.salary_;
        in.getline(str, 100, '\t');
        person.name_ = str;

        in.getline(str, 100, '\t');
        person.id_ = atoi(str);

        in.getline(str, 100, '\t');
        person.position_ = str;

        in.getline(str, 100, '\t');
        person.work_hour_ = atoi(str);

        in.getline(str, 100, '\n');
        person.salary_ = atoi(str);

        //person.set_employee_info(); // no function
        return in;
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
