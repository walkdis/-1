// Copyright 2015 <Anna Simakova>
#include "Employee.h"
#include <string>


Employee::Employee() {
    sur = "";
    job = "";
    rab = true;
}
Employee::Employee(const string& surname, const string& role,
    bool shef, double slr) {
    sur = surname;
    job = role;
    chief = shef;
    salary = slr;
    rab = true;
}
Employee::Employee(double l) : salary(l) {}
void Employee::ChD(const string& job) {
    this->job = job;
}
double Employee::operator-(double amnt) {
    return (salary - amnt);
}
double Employee::operator+(double amnt) {
    return (salary + amnt);
}
Employee::~Employee() {}

string Employee::GetSur() const {
    return sur;
}
void Employee::SetSur(const string& surname) {
    sur = surname;
}
string Employee::GetJob() const {
    return job;
}
void Employee::SetJob(const string& role) {
    job = role;
}
double Employee::GetSalary() const {
    return salary;
}
void Employee::SetSalary(double salar) {
    salary = salar;
}
bool Employee::IsChief() const {
    return chief;
}
void Employee::SetChief(bool shef) {
    chief = shef;
}
bool Employee::GetRab() const {
    return rab;
}
void Employee::SetRab(bool rb) {
    rab = rb;
}
Employee::Employee(const Employee& empl) {
    sur = empl.sur;
    job = empl.job;
    salary = empl.salary;
    rab = empl.rab;
    chief = empl.chief;
}

void Employee::operator =(const Employee& empl) {
    sur = empl.sur;
    job = empl.job;
    salary = empl.salary;
    rab = empl.rab;
    chief = empl.chief;
}
ostream& operator<<(ostream& stream, const Employee& empl) {
    stream << "Surname: " << empl.sur <<
        "Job title: " << empl.job << "Salary: " << empl.salary << endl;
    return stream;
}
bool operator ==(const Employee& empl1, const Employee& empl2) {
    return ((empl1.sur == empl2.sur)&(empl1.job == empl2.job)&
        (empl1.salary == empl2.salary)&(empl1.chief == empl2.chief));
}
