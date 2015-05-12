// Copyright 2015 <Anna Simakova>
#include "stdafx.h"
#include "Department.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>

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
    if (has(empl))
        throw EmployeeAlrExist(empl.GetSur());

    pList.push_back(empl);
    BadChief = bad;
}
void Department::KickOutEmployee(int iter) {
    list<Employee>::iterator it = pList.begin();
    advance(it, iter);
    pList.erase(it);
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
    throw EmployeeDoNotExist(surn);
}
void Department::printDepartment() {
    cout << title << " ";
    for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it)
        cout << (*it);
}
void Department::delAllDepartment() {
    pList.clear();
}

const string& Department::GetTitle() {
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
    if (it == pList.end())
    throw EmployeeDoNotExist("");
}
bool Department::has(const Employee& empl) {
    auto it = find(pList.begin(), pList.end(), empl);
    return it != pList.end();
}
Department::Department(const Department& depart1) {
    title = depart1.title;
    budget = depart1.budget;
    BadChief = depart1.BadChief;
    pList = depart1.pList;
}
const Department& Department::operator =(const Department& depart) {
    if (this != &depart) {
        title = depart.title;
        budget = depart.budget;
        BadChief = depart.BadChief;
        pList = depart.pList;
    }
    return (*this);
}
Employee& Department::Get(int iter) {
    if ((pList.begin() == pList.end()) || (iter > pList.size()) || (iter < 0))
        throw EmployeeDoNotExist("");
    list<Employee>::iterator it = pList.begin();
    advance(it, iter);
    return (*it);
}
const bool Department::operator ==(const Department& department) {
    return (((*this).title == department.title) &&
        ((*this).budget == department.budget) &&
        ((*this).BadChief == department.BadChief)
        && ((*this).pList == department.pList));
}
