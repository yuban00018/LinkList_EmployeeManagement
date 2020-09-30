#include "employee.h"
#include "department.h"
void Department::add_employee(const Employee &new_employee)
{
    number_of_employees_++;
    employees_link_.Append(new_employee);
}
void Department::set_department_info(string name, int budget)
{
    department_name_ = name;
    budget_ = budget;
}
bool Department::operator!=(const char *right)
{
    char *left = new char[department_name_.length()];
    strcpy(left, department_name_.c_str());
    return strcmp(left, right);
}
Department &Department::operator=(Department department)
{
    employees_link_ = department.employees_link_;
    department_name_ = department.department_name_;
    budget_ = department.budget_;
    number_of_employees_ = department.number_of_employees_;
}