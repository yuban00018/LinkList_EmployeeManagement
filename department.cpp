#include "employee.h"
#include "department.h"
void Department::add_employee(const Employee &new_employee)
{
    number_of_employees_++;
    employees_link_.Append(new_employee); //add information into employees link
}

void Department::set_department_info(string name, int budget)
{
    department_name_ = name;
    budget_ = budget;
}
Department &Department::operator=(Department department)
{
    employees_link_ = department.employees_link_; //operator = got overloaded in LinkList.h
    department_name_ = department.department_name_;
    budget_ = department.budget_;
    number_of_employees_ = department.number_of_employees_;
    return *this;
}
void Department::CheckOverBudget()
{
	Node<Employee> *p = employees_link_.GoTop();
	double summary_of_salary=0;
	for(; p != NULL; p = employees_link_.Skip())
		summary_of_salary += double(employees_link_.CurData());
	if(summary_of_salary - budget_ > 0)
		cout << "Department : " << department_name_ << " is over budget!" << endl;
	else
		cout << "Department : " << department_name_ << " is under budget!" << endl;
}
