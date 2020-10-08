//any function try to interact with department should be placed here
#ifndef DEPARTMENT_RUNNER_H
#define DEPARTMENT_RUNNER_H
#include <iostream>
#include <string>
#include <fstream>
#include "LinkList.h"
#include "department.h"
void MoveEmployee(LinkList<Department>& departments)
{
    departments.CurData().ShowEmployees();
    cout << "Pleace enter the name of the employee you want to move" << endl;
    string name_employee;
    cin >> name_employee;
    Node<Employee>* p_employee = departments.CurData().GetEmployees().Locate(name_employee, true);
    Employee target_employee = departments.CurData().GetEmployees().CurData();
    departments.CurData().delete_employee(name_employee);
    cout << "Pleace enter the name of the target department" << endl;
    string name_target;
    cin >> name_target;
    Node<Department>* p_target = departments.Locate(name_target, true);
    departments.CurData().add_employee(target_employee);
    cout << "Done!" << endl;
}

// void set_employee_info();

template <typename T>
void delete_department(T &departments){
    cout << departments.DeleteCurNode() << endl;
    cout << "Deleted" << endl;
    return;
}

template <typename T>
void SortDepartment(T method, LinkList<Department>& departments) {
    departments.Sort(method);
}

void ShowDepartments(LinkList<Department> &departments)
{
    cout << "Number of departments: " << departments.NumNodes() << endl;
    cout << left << setw(25) << "Department Name" << setw(20) << "Number of employees" << setw(10) << "Budget" << endl;
    cout << departments;
}

void Save(LinkList<Department> &departments,const string& filename)
{
    ofstream out(filename,ios::out);
    if (out.is_open())
    {
        out << departments.NumNodes() << endl;
        out << departments;
        departments.GoTop();
        Node<Department> *flag = departments.CurNode();
        int number_of_departments = departments.NumNodes();
        for (int i = 1; i <= number_of_departments; i++)
        {
            out << departments.CurData().GetEmployees();
            departments.Go(i);
        }
        out << EOF;
        out.close();
    }
}

// Doing
void Load(LinkList<Department> &departments, const string &filename) //read information
{
    ifstream infile (filename);
    if (infile.is_open())
    {
        //infile >> number_of_departments;
        //int number_of_departments = departments.NumNodes();
        int number_of_departments;
        infile >> number_of_departments;
        departments.GoTop();  
        Node<Department>* flag = departments.CurNode();
  
        for (int i = 0; i < number_of_departments; i++) {
        //infile >> departments.CurData();
        infile >> departments;
        departments.GoBottom();
        }

        departments.GoTop();
        flag = departments.CurNode();
        Node<Employee>* flag0; // Flag to see what happended
        for (int i = 0; i < number_of_departments; i++)
        {
            flag = departments.CurNode();
            int number_of_employees = departments.CurData().GetEmployeesNum();
            flag0 = departments.CurData().GetEmployees().GoTop();
                for (int j = 0; j < number_of_employees; j++)
                {
                    infile >> departments.CurData().GetEmployees();
                    flag0 = departments.CurData().GetEmployees().CurNode();
                    departments.CurData().GetEmployees().GoBottom();
                    flag0 = departments.CurData().GetEmployees().CurNode();
                }
            departments.Go(i+1);
            flag = departments.CurNode();
            //infile >> departments.CurData().GetEmployees();
            //departments.Append(departments.CurData());
        }

        infile.close();
    }
}
#endif