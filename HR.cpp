//HP.cpp
#include <iostream>                 
#include <string>
#include "Linklist.h"
using namespace std;
/*
class:department, employee
department:link employees by department, have access to their basic information, add or delete employees
employee:store basic information including ID,NAME,DEPARTMENT,SALARY
*/
class employee;

class department
{
public:
    department(string name = "INVALIDNAME", int s = 0) : DepartmentName(name), size(s) {}
    void AddEmployee(const employee &newemployee);
    department &operator=(const department dp)
    {
        DepartmentName = dp.DepartmentName;
        link = dp.link; //has been overload
        size = dp.size;
    }
    friend ostream &operator<<(ostream &out, department dp)
    {
        dp.link.PutList(out);
        return out;
    }

private:
    string DepartmentName;
    LinkList<employee> link;
    int size;
};
class employee
{
public:
    employee() : ID(0), salary(0), name("INVALIDNAME"), department("INVALIDDEPARTMENT"), regular(false) {}
    employee(int id, int s, string n, string d, bool r = false) : ID(id), salary(s), name(n), department(d), regular(r) {}
    employee(const employee &person) { *this = person; }
    void set(int id, int s, string n, string d, bool r = false)
    {
        ID = id;
        salary = s;
        name = n;
        department = d;
        regular = r;
    }
    friend ostream &operator<<(ostream &out, employee person)
    {
        out << "ID:" << person.ID << endl
            << "NAME:" << person.name << endl
            << "DEPARTMENT:" << person.department << endl
            << "SALARY:" << person.salary << endl;
        return out;
    }
    employee &operator=(const employee &person)
    {
        ID = person.ID;
        salary = person.salary;
        name = person.name;
        department = person.department;
        regular = person.regular;
    }
    friend class department;

private:
    int ID;
    int salary; //per month
    string name;
    string department;
    bool regular; //regular employee or not
};

void department::AddEmployee(const employee &newemployee)
{
    employee person(newemployee);
    size++;
    link.Append(person);
}

int main()
{
    employee newemployee(2333, 15000, "Eddie Cao", "Technic Support", true);
    department newdepartment("Technic Support");
    LinkList<department> departments;
    departments.Append(newdepartment);
    departments.CurData().AddEmployee(newemployee);
    newemployee.set(6666, 15000, "Jacky", "Technic Support", true);
    departments.CurData().AddEmployee(newemployee);
    cout << departments.CurData();
    return 0;
}
