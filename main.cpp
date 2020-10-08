#include <iostream>
#include <string>
#include "LinkList.h"
#include "employee.h"
#include "department.h"
#include "department_runner.h"
#include<cstdlib>  
#include<windows.h>
using namespace std;

#define newsearch true

void help1();
void help2();
void EmployeeManage(Department &department);
void DepartmentManage(LinkList<Department> &departments);

string ByName = "";
double ByBudget = 0.0;
int ByEmployeesNumber = 0;
int ByEmployeeId = 0;
double BySalary = 0.0;

string filename = "DataBase.txt";

int main()
 {
    LinkList<Department> departments;
    char choice;

    //testing data
   
    //Department new_department; //Create a new department
    //departments.Append(new_department);

    //Department new_department0("HR",0); //Create another new department
    //departments.Append(new_department0);
    //Employee new_employee;
    //departments.CurData().add_employee(new_employee);//Create a new employee 
    //Employee new_employee0(1, "NO_BODY");
    //departments.CurData().add_employee(new_employee0);//Create another new employee
    //end
    

    while (true)
    {
        cout << "Load from the data base (Y/N)";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            // Doing 
            Load(departments, filename);
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
            Save(departments, filename);
            break;
        }
        else if (choice == 'n' || choice == 'N')
            break;
    }
}

void help1()
{ //ABCDEFGHIGKLMNOPQRSTUVWXYZ
    system("cls");
    cout << "A (name) (budget)- Add a new department" << endl;
    cout << "C (name) (newname) (budget) - Change department infomation" << endl;
    cout << "D (name) - Delete department" << endl;
    cout << "M - Move employee" << endl;     //没有完成函数定义
    cout << "O - Check which department over budget" << endl; //没有函数声明与定义
    cout << "Q - Quit" << endl;
    cout << "S (method) - Sort department by certain rule" << endl; //没有声明与定义
    cout << "V (name) - View further details of department" << endl;
    cout << endl;
}

void help2()
{
    system("cls");
    cout << "A (name) (id) (position) (work_hour) (salary) - Add new employee" << endl;
    cout << "D (identity) - Delete a specific employee" << endl;
    cout << "S (method) - Sort employee by certain rule" << endl;
    cout << "Q - Quit" << endl;
    cout << "type A see further detail or press ENTER to quit help" << endl;
    cout << endl;
}

void EmployeeManage(Department &department)
{
    while (true)
    {
        system("cls");
        cout << "\n=========================================================" << endl;
        department.ShowEmployees();
        cout << "\n=========================================================" << endl;
        cout << "Command(H for help): ";
        string command;
        cin >> command;
        if (command == "H" || command == "h")
            help2();
        else if (command == "A" || command == "a") {
            int id;
            string name;
            double salary ;
            int work_hour;
            string position;
            cin >> name;
            Node<Employee>* p = department.GetEmployees().Locate(name, newsearch);
            if (p == NULL)
            {
                cin >> id;
                cin >> position;
                cin >> work_hour;
                cin >> salary;
                Employee new_employee(id, name, salary, work_hour, position);
                department.add_employee(new_employee);
                cout << "Added!" << endl
                    << endl;
            }
            else {
                int temp1;
                string temp2;
                int temp3;
                double temp4;
                cin >> temp1 >> temp2 >> temp3 >> temp4;
                cout << endl
                    << endl;
            }

        }
        else if (command == "D" || command == "d")
        {
            int id;
            char choice;
            cin >> id;
            Node<Employee>* p = department.GetEmployees().Locate(id, newsearch);
            if (p != NULL)
            {
                cout << "Delete the employee (Y/N):";
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    department.delete_employee(id);
                    cout << "Deleted!" << endl;
                }
                else if (choice == 'n' || choice == 'N')
                    cout << "nothing happened!" << endl;
        }
            else
            {
                cout << "Not found!" << endl
                    << endl;
            }
        }
        else if (command == "S" || command == "s")
        {
            int method;
            cin >> method;
            switch (method)
            {
            case 1:
                department.SortEmployee(ByName);
                cout << "Sorted!" << endl;
                break;
            case 2:
                department.SortEmployee(ByBudget);
                cout << "Sorted!" << endl;
                break;
            case 3:
                department.SortEmployee(ByEmployeeId);
                cout << "Sorted!" << endl;
                break;
            default:
                cout << "Method not found!" << endl;
                break;
            }
        }
        else if (command == "Q" || command == "q")
            return;
        else continue;
        system("pause");
        system("cls");
    }
}

void DepartmentManage(LinkList<Department> &departments)
{
    while (true)
    {
        system("cls");
        cout << "\n=========================================================" << endl;
        ShowDepartments(departments);
        cout << "\n=========================================================" << endl;
        cout << "Command(H for help): ";
        string command;
        cin >> command;
        if (command == "H" || command == "h")
            help1();
        else if (command == "V" || command == "v")
        {
            string name;
            cin >> name;
            Node<Department> *p = departments.Locate(name, newsearch);
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
        else if (command == "D" || command == "d") {
            string name;
            char choice;
            //cout << "Please input the name of the department to be delete: " << endl;
            cin >> name;
            Node<Department>* p = departments.Locate(name, newsearch);
            if (p == NULL)
            {
                cout << "Not found!" << endl;
                //continue;  //for debug
            }
            else
            {
                cout << "Delete the department (Y/N):" ;
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    delete_department(departments);
                    //continue;  
                }
                else if (choice == 'n' || choice == 'N')
                    cout << "nothing happened!" << endl;
                    //continue;
            }
        }
        else if (command == "C" || command == "c")
        {
            string name;
            cin >> name;
            Node<Department> *p = departments.Locate(name, newsearch);
            if (p == NULL)
            {
                string temp1;
                int temp2;
                cin >> temp1 >> temp2;
                cout << "Not found!" << endl
                     << endl;
            }
            else
            {
                string new_name;
                int new_budget;
                cin >> new_name >> new_budget;
                departments.CurData().set_department_info(new_name, new_budget);
            }
        }
        else if (command == "A" || command == "a")
        {
            string name;
            cin >> name;
            Node<Department> *p = departments.Locate(name, newsearch);
            if (p == NULL)
            {
                double budget;
                cin >> budget;
                Department new_department(name, budget);
                departments.Append(new_department);
                cout << "Added!" << endl
                    << endl;
            }
            else
            {
                double temp;
                cin >> temp;
                cout << "There are already duplicated departments!" << endl
                     << endl;
            }
        }
        // Doing
        else if (command == "M" || command == "m")
        {
            cout << "Please enter the name of the department you want to operate" << endl;
            string name;
            cin >> name;
            Node<Department>* p = departments.Locate(name, true);
            if (p == NULL)
            {
                cout << "Not found!" << endl
                    << endl;
            }
            else
                MoveEmployee(departments);
        }
        else if (command == "O" || command == "o")
        {
            cout << "Please enter the name of the department you want to check" << endl;
            string name;
            cin >> name;
            Node<Department>* p = departments.Locate(name, true);
            departments.CurData().CheckOverBudget();
        }
        else if (command == "S" || command == "s")
        {
            int method;
            cin >> method;
            switch (method)
            {
            case 1:
                SortDepartment(ByName, departments);
                cout << "Sorted!" << endl;
                break;
            case 2:
                SortDepartment(ByEmployeesNumber, departments);
                cout << "Sorted!" << endl;
                break;
            case 3:
                SortDepartment(ByBudget, departments);
                cout << "Sorted!" << endl;
                break;
            default:
                cout << "Method not found!" << endl;
                break;
            }
        }
        else if (command == "Q" || command == "q")
            return;
        else continue;
        system("pause");
        system("cls");
    }
}
