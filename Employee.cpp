// Copyright 2015 <Anna Simakova>
#include "Employee.h"
#include <string>


Employee::Employee() {
  sur = "";
  job = "";
  rab = true;
}
Employee::Employee(const string& ty, const string& dol,
const bool qw, const double lop) {
  sur = ty;
  job = dol;
  chief = qw;
  salary = lop;
  rab = true;
}
Employee::Employee(double l) : salary(l) {}
void Employee::ChD(const string& job) {
  this->job = job;
}
double Employee::operator-(const double k) {
  return (salary - k);
}
double Employee::operator+(const double k) {
  return (salary + k);
}
Employee::~Employee() {}

string Employee::GetSur() const {
  return sur;
}
void Employee::SetSur(const string& as) {
  sur = as;
}
string Employee::GetJob() const {
  return job;
}
void Employee::SetJob(const string& as) {
  job = as;
}
double Employee::GetSalary() const {
  return salary;
}
void Employee::SetSalary(const double as) {
  salary = as;
}
double Employee::GetPrem() const {
  return prem;
}
void Employee::SetPrem(const double as) {
  prem = as;
}
bool Employee::IsChief() const {
  return chief;
}
void Employee::SetChief(const bool as) {
  chief = as;
}
bool Employee::GetRab() const {
  return rab;
}
void Employee::SetRab(const bool as) {
  rab = as;
}
Employee::Employee(const Employee& b) {
  sur = b.sur;
  job = b.job;
  salary = b.salary;
  prem = b.prem;
  rab = b.rab;
  chief = b.chief;
}
bool operator ==(Employee df, const Employee qw) {
  if (df == qw)
  return true;
  else
  return false;
}
void Employee::operator =(const Employee& b) {
  sur = b.sur;
  job = b.job;
  salary = b.salary;
  prem = b.prem;
  rab = b.rab;
  chief = b.chief;
}
