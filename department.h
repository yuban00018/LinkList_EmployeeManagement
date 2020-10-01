// Department.h
// every class should overload operator **==** and operator **!=**
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
    // not finished
    void delete_employee_by_name(string employee_name);//please refer to delete_employee_by_id
    double ShowTotalBudget();
    void SortByBudget();
    void move_employee(string from_department_name, int employee_id, string to_department_name);

    Department(string name = "NO_DEPARTMENT_NAME", double budget = 0) : department_name_(name),
                                                                        budget_(budget) {}
    void add_employee(const Employee &new_employee);
    void set_department_info(string name = "NO_DEPARTMENT_NAME", int budget = 0);
    bool delete_employee_by_id(int employee_id);

    //Type Cast
    operator string() { return department_name_; }
    operator double() { return budget_; }
    operator int() { return number_of_employees_; }
    //Overload
    Department &operator=(Department department);
    friend ostream &operator<<(ostream &out, const Department &department)
    {
        out << "DEPARTMENT: " << department.department_name_ << "\nEMPLOYEES: ";
        department.employees_link_.PutList(out); //shows employees information, operator << got overloaded in employee.h
        return out;
    }

private:
    static int number_of_departments_;
    string department_name_;
    LinkList<Employee> employees_link_;
    double budget_;
    int number_of_employees_;
};

#endif