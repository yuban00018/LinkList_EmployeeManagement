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
    for (int i = 0; i < 2; i++)
    {
        Department new_department; //Create new department
        departments.Append(new_department);
        Employee new_employee;                            //Create new employee
        departments.CurData().add_employee(new_employee); //add employee
    }
    departments.CurData().set_department_info("technic support", 25000);
    char *search1 = "technic support";
    cout << departments.Locate(search1, true) << endl;
    //  departments.ShowList();
    //cout << departments.CurData();                    //Show department detail
    //delete employee
    //delete de
    return 0;
}
