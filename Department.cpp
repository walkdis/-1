// Copyright 2015 <Anna Simakova>
#include "Department.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

Department::Department() {
    title = "";
    amount = 0;
    budget = 0.0;
    BadChief = true;
}
Department::~Department() {
    delAllDepartment();
}
Department::Department(const string& name,
int amout, double budg) {
    title = name;
    amount = amout;
    budget = budg;
}
void Department::AddEmployee(const Employee& empl,
bool bad) {
    if (has(empl)) {
        throw EmployeeAlrExist(empl.GetSur());
    } else {
        amount += 1;
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
    amount -= 1;
}
Employee& Department::findS(const string& surn) {
    int i = 0;
    for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
        if (it->GetSur() == surn)
           return (*it);
        if (i == amount)
            throw EmployeeDoNotExist(surn);
        i++;
    }
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

ostream& operator<<(ostream& stream, const Employee& empl) {
    stream << "Surname: " << empl.sur <<
    "Job title: " << empl.job << "Salary: " << empl.salary << endl;
    return stream;
}
string Department::GetTitle() const {
    return title;
}
void Department::SetTitle(const string& tit) {
    title = tit;
}
int Department::GetAmount() const {
    return amount;
}
void Department::SetAmount(int am) {
    amount = am;
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
    delete &empl;
}
bool Department::has(const Employee& empl) {
  for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it)
      if ((*it) == empl)
        return true;
    return false;
}
const bool operator ==(Department& depart1, const Department& depart2) {
    return (depart1 == depart2);
}
Department::Department(const Department& depart1) {
    title = depart1.title;
    amount = depart1.amount;
    budget = depart1.budget;
    BadChief = depart1.BadChief;
    pList = depart1.pList;
}
const Department& Department::operator =(const Department& depart1) {
    title = depart1.title;
    amount = depart1.amount;
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
}
