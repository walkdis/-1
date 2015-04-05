// Copyright 2015 <Anna Simakova>
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "SP.h"


Department::Department() {
  title = "";
  pList = NULL;
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
  pList = (Employee*)malloc(sizeof(Employee)*amount);
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
  if (has(qw))
  throw EmployeeAlrExist(qw.GetSur());
  else {
  amount += 1;
  pList = (Employee *)realloc(pList, sizeof(Employee)*amount);
  SetSur(qw.GetSur());
  SetJob(qw.GetJob());
  SetChief(qw.IsChief());
  if (qw.IsChief() == true)
  BadChief = bad;
  SetSalary(qw.GetSalary());
  SetRab(true);
  }
}
void Department::KickOutEmployee(int l) {
  for (int i = l; i <= amount; i++) {
  pList[i] = pList[i + 1];
  }
  amount -= 1;
  pList = (Employee *)realloc(pList, sizeof(Employee)*amount);
}
Employee Department::findS(const string& l) {
  int i = 0;
  for (i = 0; i < amount; i++)
  if (pList[i].GetSur() == l)
  return pList[i];
  if (i == amount)
  throw EmployeeDoNotExist(l);
}
int Department::findI(const string& l) {
  for (int i = 0; i < amount; i++)
  if (pList[i].GetSur() == l)
  return i;
}
void Department::printDepartment() {
  cout << title << " ";
  for (int i = 0; i < amount; i++)
  cout << pList[i].GetSur() << " " <<
  pList[i].GetJob() << " " << pList[i].GetSalary();
}
void Department::delAllDepartment() {
  free(pList);
}
void Department::GivePR() {
  if (BadChief = true) {
  for (int i = 0; i < amount; i++)
  if (pList[i].IsChief() == true)
  pList[i].SetPrem(budget / 2);
  else
  pList[i].SetPrem(budget / 2 / (amount - 1));
  } else {
  for (int i = 0; i < amount; i++)
  pList[i].SetPrem(budget / amount);
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
  for (int i = 0; i < amount; i++)
  if (pList[i] == qw)
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
Employee Department::Get(int i) {
	return pList[i];
}
