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
Department::Department(const string& poi,
const int rest, const double tr) {
  title = poi;
  amount = rest;
  budget = tr;
}
void Department::CreateEmployee(const string& snm,
const string& jt, const bool ch, const bool bad,
const double paym) {
  SetSur(snm);
  SetJob(jt);
  SetChief(ch);
  if (ch == true)
  BadChief = bad;
  SetSalary(paym);
  SetRab(true);
}
void Department::AddEmployee(const Employee& qw,
const bool bad) {
  if (has(qw)) {
  throw EmployeeAlrExist(qw.GetSur());
  } else {
  amount += 1;
  pList.push_back(qw);
  }
}
void Department::KickOutEmployee(int l) {
  int g = 0;
  for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
  if (l == g) {
  pList.erase(it);
  }
  g++;
  }
  amount -= 1;
}
Employee& Department::findS(const string& surn) {
  int i = 0;
  for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
  if ((*it).GetSur() == surn)
  return (*it);
  if (i == amount)
  throw EmployeeDoNotExist(surn);
  i++;
}
}
int Department::findI(const string& surn) {
  int i = 0;
  for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
  if ((*it).GetSur() == surn)
  return i;
  i++;
}
}
void Department::printDepartment() {
  cout << title << " ";
  for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
  cout << (*it).GetSur() << " " <<
  (*it).GetJob() << " " << (*it).GetSalary();
}
}
void Department::delAllDepartment() {
  pList.clear();
}
void Department::GivePR() {
    if (BadChief = true) {
  for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
            if ((*it).IsChief() == true)
            (*it).SetPrem(budget / 2);
            else
            (*it).SetPrem(budget / 2 / (amount - 1));
        }
    } else {
  for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it)
  (*it).SetPrem(budget / amount);
  }
}
ostream& operator<<(ostream& stream, const Employee& qw) {
  stream << "Surname: " << qw.sur <<
  "Job title: " << qw.job << "Salary: " << qw.salary << endl;
  return stream;
}
string Department::GetTitle() const {
  return title;
}
void Department::SetTitle(const string& as) {
  title = as;
}
int Department::GetAmount() const {
  return amount;
}
void Department::SetAmount(const int as) {
  amount = as;
}
double Department::GetBudg() const {
  return budget;
}
void Department::SetBudg(const double as) {
  budget = as;
}
bool Department::IsChiefBad() const {
  return BadChief;
}
void Department::SetBadChief(const bool as) {
  BadChief = as;
}
void Department::remove(const Employee& qw) {
  delete &qw;
}
bool Department::has(const Employee& qw) {
  for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it)
  if ((*it) == qw)
  return true;
  return false;
}
bool operator ==(Department df, const Department qw) {
  if (df == qw)
  return true;
  else
  return false;
}
Department::Department(const Department& b) {
  title = b.title;
  amount = b.amount;
  budget = b.budget;
  BadChief = b.BadChief;
  pList = b.pList;
}
const Department& Department::operator =(const Department& b) {
  title = b.title;
  amount = b.amount;
  budget = b.budget;
  BadChief = b.BadChief;
  pList = b.pList;
}
Employee& Department::Get(int i) {
    int g = 0;
    for (list<Employee>::iterator it = pList.begin(); it != pList.end(); ++it) {
        if (i == g) {
            return (*it);
        }
        g++;
    }
}
