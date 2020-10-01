#include <iostream>
#include <string>
#include <typeinfo>
#include "department.h"
#include "employee.h"
#include "LinkList.h"
using namespace std;

int main()
{
    LinkList<Department> departments;
    for (int i = 0; i < 5; i++)
    {
        Department new_department; //Create new department
        departments.Append(new_department);
        if(i==2)departments.CurData().set_department_info("technic supports", 25000);
        Employee new_employee;                            //Create new employee
        departments.CurData().add_employee(new_employee); //add employee
    }
    departments.CurData().set_department_info("technic support", 25000);
    string search1 = "technic supports";
    departments.Locate(search1, true);//never use Locate(char*,true);
    departments.CurData().delete_employee_by_id(0);
    cout<<departments.CurData();
    return 0;
}
