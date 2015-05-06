// Copyright 2015 <Anna Simakova>
#include "Department.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>

Department::Department() {
    title = "";
    budget = 0.0;
    BadChief = true;
}
Department::~Department() {
    delAllDepartment();
}
Department::Department(const string& name, double budg) {
    title = name;
    budget = budg;
}
void Department::AddEmployee(const Employee& empl,
    bool bad) {
    if (has(empl)) {
        throw EmployeeAlrExist(empl.GetSur());
    } else {
        pList.push_back(empl);
        BadChief = bad;
    }
}
void Department::KickOutEmployee(int iter) {
    int g = 0;
    for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
        if (iter == g) {
            pList.erase(it);
        }
        g++;
    }
}
Employee& Department::findS(const string& surn) {
    for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
        if (it->GetSur() == surn)
            return (*it);
    }
     throw EmployeeDoNotExist(surn);
}
int Department::findI(const string& surn) {
    int i = 0;
    for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
        if (it->GetSur() == surn)
            return i;
        i++;
    }
}
void Department::printDepartment() {
    cout << title << " ";
    for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
        cout << it->GetSur() << " " <<
            it->GetJob() << " " << it->GetSalary();
    }
}
void Department::delAllDepartment() {
    pList.clear();
}

string Department::GetTitle() const {
    return title;
}
void Department::SetTitle(const string& tit) {
    title = tit;
}
int Department::GetAmount() const {
    return pList.size();
}
double Department::GetBudg() const {
    return budget;
}
void Department::SetBudg(double budg) {
    budget = budg;
}
bool Department::IsChiefBad() const {
    return BadChief;
}
void Department::SetBadChief(bool BCH) {
    BadChief = BCH;
}
void Department::remove(const Employee& empl) {
    auto it = find(pList.begin(), pList.end(), empl);
    pList.erase(it);
}
bool Department::has(const Employee& empl) {
    auto it = find (pList.begin(), pList.end(), empl);
    return it != pList.end();
}
Department::Department(const Department& depart1) {
    title = depart1.title;
    budget = depart1.budget;
    BadChief = depart1.BadChief;
    pList = depart1.pList;
}
void Department::operator =(const Department& depart1) {
    title = depart1.title;
    budget = depart1.budget;
    BadChief = depart1.BadChief;
    pList = depart1.pList;
}
Employee& Department::Get(int iter) {
    int g = 0;
    for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
        if (iter == g) {
            return (*it);
        }
        g++;
    }
    throw EmployeeDoNotExist("");
}
