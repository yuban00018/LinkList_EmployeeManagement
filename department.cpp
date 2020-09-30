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