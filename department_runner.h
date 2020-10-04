//any function try to interact with department should be placed here
#ifndef DEPARTMENT_RUNNER_H
#define DEPARTMENT_RUNNER_H
#include <iostream>
#include <string>
#include "LinkList.h"
#include "department.h"
void MoveEmployee(string from_department_name, int employee_id, string to_department_name);
template<typename T>void delete_department(T method){}
template<typename T>void SortDepartment(T method){}
void Save();//save department and employee information into data.txt
void Load();//read information from data.txt

#endif