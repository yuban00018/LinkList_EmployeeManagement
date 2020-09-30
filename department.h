// Department.h
#ifndef DEPARTMENT_HPP
#define DEPARTMENT_HPP
#include <iostream>
#include <string>
#include <string.h>
#include "employee.h"
#include "LinkList.h"
using namespace std;

class Department
{
public:
    Department(string name = "NO_DEPARTMENT_NAME", int budget = 0) : department_name_(name), budget_(budget) { cout << "Department build success" << endl; }
    void add_employee(const Employee &new_employee);
    void set_department_info(string name = "NO_DEPARTMENT_NAME", int budget = 0);
    operator char *()
    {
        char *name = new char[department_name_.length()];
        strcpy(name, department_name_.c_str());
        return name;
    }
    bool operator!=(const Department &department)
    {
        return department_name_ != department.department_name_;
    }
    Department &operator=(Department department)
    {
        employees_link_ = department.employees_link_;
        department_name_ = department.department_name_;
        budget_ = department.budget_;
        number_of_employees_ = department.number_of_employees_;
    }
    friend ostream &operator<<(ostream &out, Department department)
    {
        out << "DEPARTMENT: " << department.department_name_ << "\nEMPLOYEES: ";
        department.employees_link_.PutList(out);
        return out;
    }
    string showname(){return department_name_;}
private:
    static int number_of_departments_;
    string department_name_;
    LinkList<Employee> employees_link_;
    int budget_;
    int number_of_employees_;
};

#endif