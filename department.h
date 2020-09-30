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
    bool operator!=(const char *right);
    Department &operator=(Department department);
    friend ostream &operator<<(ostream &out, const Department &department)
    {
        out << "DEPARTMENT: " << department.department_name_ << "\nEMPLOYEES: ";
        department.employees_link_.PutList(out);
        return out;
    }
private:
    static int number_of_departments_;
    string department_name_;
    LinkList<Employee> employees_link_;
    int budget_;
    int number_of_employees_;
};

#endif