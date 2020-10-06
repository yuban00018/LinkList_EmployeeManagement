#include <iostream>
#include <string>
#include "LinkList.h"
#include "employee.h"
#include "department.h"
#include "department_runner.h"
using namespace std;

void help1();
void help2();
void EmployeeManage(Department &department);
void DepartmentManage(LinkList<Department> &departments);

int main()
{
    LinkList<Department> departments;
    char choice;

    //test data
    Department new_department; //Create new department
    departments.Append(new_department);
    Department new_department0; //Create new department
    departments.Append(new_department0);
    Employee new_employee;
    departments.CurData().add_employee(new_employee);
    Employee new_employee0;
    departments.CurData().add_employee(new_employee0);
    //end

    while (true)
    {
        cout << "Load from the data base (Y/N)";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            //Load();
            break;
        }
        else if (choice == 'n' || choice == 'N')
            break;
    }

    DepartmentManage(departments);//main part

    while (true)
    {
        cout << "Save to the data base (Y/N)";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            Save(departments);
            break;
        }
        else if (choice == 'n' || choice == 'N')
            break;
    }
}

void help1(){ //ABCDEFGHIGKLMNOPQRSTUVWXYZ
    system("cls");
    cout << "A - Add a new department" << endl;
    cout << "C (name) (newname) (budget) - Change department infomation" << endl;
    cout << "D (name) - Delete department" << endl;
    cout << "M (id) (from) (to) - Move employee" << endl;//没有完成函数定义
    cout << "O - Check which department over budget" << endl;//没有函数声明与定义
    cout << "Q - Quit" << endl;
    cout << "S (method) - Sort department by certain rule" << endl;//没有声明与定义
    cout << "V (name) - View further details of department" << endl;
    cout << endl;
}

void help2()
{
    system("cls");
    cout << "A - Add new employee" << endl;
    cout << "D (identity) - Delete a specific employee" << endl;
    cout << "S (method) - Sort employee by certain rule" << endl;
    cout << "Q - Quit" << endl;
    cout << "type A see further detail or press ENTER to quit help" << endl;
    char further_command;
    further_command = getchar();
    if (further_command == 'A')
        cout << "A (id) (name) (salary) (work_hour) (position) (rate)" << endl;
    cout << endl;
}

void EmployeeManage(Department &department)
{
    while (true)
    {
        system("cls");
        department.ShowEmployees();
        cout << "Command(H for help): ";
        char command;
        cin >> command;
        if (command == 'H' || command == 'h')
            help2();
        if (command == 'Q' || command == 'q')
            return;
        system("pause");
        system("cls");
    }
}

void DepartmentManage(LinkList<Department> &departments)
{
    while (true)
    {
        cout << "\n=========================================================" << endl;
        ShowDepartments(departments);
        cout << "\n=========================================================" << endl;
        cout << "Command(H or HH for help): ";
        char command;
        cin >> command;
        if (command == 'H' || command == 'h')
            help1();
        else if (command == 'V' || command == 'v')
        {
            string name;
            cin >> name;
            Node<Department> *p = departments.Locate(name, true);
            if (p == NULL)
            {
                cout << "Not found!" << endl
                     << endl;
            }
            else
            {
                departments.CurData().ShowEmployees();
                EmployeeManage(departments.CurData());
            }
        }
        else if (command == 'D' || command == 'd') {
            string name;
            char choice;
            cout << "Please input the name of the department to be delete: " << endl;
            cin >> name;
            Node<Department>* p = departments.Locate(name, true);
            if (p == NULL)
            {
                cout << "Not found!" << endl;
                continue;
            }
            else
            {
                cout << "Delete the department (Y/N):" ;
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    dedelete_department(departments);
                    continue;
                }
                else if (choice == 'n' || choice == 'N')
                    continue;
            }
        }
        else if (command == 'Q' || command == 'q')
            return;
        system("pause");
        system("cls");
    }
}