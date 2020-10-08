// Department.h
// every class should overload operator **==** and operator **!=**
#ifndef DEPARTMENT_HPP
#define DEPARTMENT_HPP
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include "employee.h"
#include "LinkList.h"
using namespace std;

#define newsearch true

class Department
{
public:
    void CheckOverBudget();
    double GetTotalSalaries();

    Department(string name = "NO_DEPARTMENT_NAME", double budget = 0) : department_name_(name), number_of_employees_(0),
                                                                        budget_(budget) {}
    void add_employee(const Employee &new_employee);
    void set_department_info(string name = "NO_DEPARTMENT_NAME", int budget = 0);
    template <typename T>
    void SortEmployee(T method)
    {
        employees_link_.Sort(method);
    }
    template <typename T>
    void delete_employee(T employee_identity)// now just delete employee and decrease the number_of_employees_
    {
        //if (employees_link_.Locate(employee_identity, newsearch) != NULL ) // now the CurNode is what we want
        //{
            employees_link_.DeleteCurNode();
            number_of_employees_ --;
            //return true;
        //}
        //else
            //return false;
    }

    void ShowEmployees()
    {
        cout << setw(10) << "Name" << setw(10) << "ID" << setw(25) << "Position" << setw(10) << "Work Hour" << setw(10) << "Salary" << endl;
        cout << employees_link_;
    }

    LinkList<Employee> &GetEmployees() { return employees_link_; }
    string GetDepartmentName() const { return department_name_; }
    int GetEmployeesNum() const { return number_of_employees_; }

    //Type Cast
    operator string() { return department_name_; }
    operator double() { return budget_; }
    operator int() { return number_of_employees_; }

    //Overload
    Department &operator=(Department department);
    friend ostream &operator<<(ostream &out, const Department &department)
    {
        out << setw(25) << department.department_name_ << setw(20) << department.number_of_employees_ 
            << setw(10) << department.budget_;
        return out;
    }
    //Doing
    friend istream &operator>>(istream& in, Department& department)
    {
        in >> department.department_name_ >> department.number_of_employees_ >> department.budget_ ;
        return in;
    }

private:
    static int number_of_departments_; //use LinkList::NumNodes() instead?
    string department_name_;
    LinkList<Employee> employees_link_;
    double budget_;
    int number_of_employees_;
};

#endif
