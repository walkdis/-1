// Copyright 2015 <Anna Simakova>
#include "Employee.h"
#include "Department.h"
#include <cstdlib>
#include <exception>
#include <string>
#include <iostream>
#include <list>


int main() {
    string cmd, snm, jt;
    bool chief, bad = false;
    int cmnd, k = 0;
    double red, paym;
    Employee *employee = new Employee();
    cout << "You must create a department. enter the parameters:\n";
    cout << "Name department\n";
    cin >> cmd;
    cout << "How many employees?\n";
    cin >> cmnd;
    cout << "How much money is allocated to the department?\n";
    cin >> red;
    Department *department = new Department(cmd, cmnd, red);
    for (int i = 0; i < cmnd; i++) {
        cout << "Enter the name, title (enter leadership as Chief) ";
        cout << "and the salary of the employee\n";
        getline(cin, snm);
        getline(cin, jt);
        if (jt == "Chief)") {
            chief = true;
            cout << "Chief bad? (Y or N)\n";
            char c;
            cin >> c;
            if (c == 'Y')
            bad = true;
            else
            bad = false;
        } else {
            chief = false;
        }
        cin >> paym;
        employee->SetSur(snm);
        employee->SetJob(jt);
        employee->SetChief(chief);
        employee->SetSalary(paym);
        department->AddEmployee(*employee, bad);
    }
    do {
        cout << "What would you like to do more?\n";
        cout << "lower wages - enter 3, raise the salary - enter 4\n";
        cout << "change the position of the employee - enter 5, ";
        cout << "Add employee in this department - enter 7\n";
        cout << "remove the employee from base - enter 8, ";
        cout << "see Front - enter 9\n";
        cout << "if you want to exit the program, press 0";
        cin >> k;
        if ((k > 2) & (k < 7)) {
            cout << "Enter the name of the employee\n";
            cin >> cmd;
            Employee l = department->findS(cmd);
            if (department == NULL) {
                cout << "Error. An employee can not be found!\n";
                break;
            }
            if (k == 3) {
                double k;
                cout << "How much downgrade?\n";
                cin >> k;
                l.operator-(k);
            }
            if (k == 4) {
                double k;
                cout << "How much are raising?\n";
                cin >> k;
                l.operator+(k);
            }
            if (k == 5)
            getline(cin, jt);
            l.ChD(jt);
        }
        if (k == 7) {
            cout << "Enter the name, title (enter leadership as Chief)";
            cout << " and the salary of the employee\n";
            getline(cin, snm);
            getline(cin, jt);
            if (jt == "Chief)") {
                chief = true;
                cout << "Chief bad? (Y or N)\n";
                char c;
                cin >> c;
                if (c == 'Y')
                bad = true;
                else
                bad = false;
            } else { chief = false; }
            cin >> paym;
            Employee empl(snm, jt, chief, paym);
            try {
                department->AddEmployee(empl, bad);
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
        }
        if (k == 8)
            department->KickOutEmployee(department->findI(cmd));
        if (k == 9)
            department->printDepartment();
    } while (k != 0);
    system("pause");
    return 0;
}
