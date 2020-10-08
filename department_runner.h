//any function try to interact with department should be placed here
#ifndef DEPARTMENT_RUNNER_H
#define DEPARTMENT_RUNNER_H
#include <iostream>
#include <string>
#include <fstream>
#include "LinkList.h"
#include "department.h"
void MoveEmployee(int employee_id, string from_department_name, string to_department_name) {

}


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

void Save(LinkList<Department> departments,const string& filename)
{
    ofstream out(filename);
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
void Load(LinkList<Department> departments, const string &filename) //read information
{
    ifstream infile (filename);
    if (infile.is_open())
    {
        int number_of_departments = departments.NumNodes();
        infile >> number_of_departments;
        departments.GoTop();
        infile >> departments;
        Node<Department>* flag = departments.CurNode();
        for (int i = 1; i <= number_of_departments; i++)
        {
            departments.Go(i);
            departments.CurData().GetEmployees().GetList(infile);
        }

        infile.close();
    }
}
#endif