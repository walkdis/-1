// Copyright 2015 <Anna Simakova>
#pragma once
#include "Employee.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "AlrExist.h"
#include "DoNotEx.h"
#include <list>


using std::string;
using std::cin;
using std::cout;
using std::ostream;
using std::endl;
using std::exception;
using std::list;
using std::find;

class Department {
 private:
    string title;
    double budget;
    bool BadChief;
    list<Employee> pList;

 public:
    Department();
    ~Department();
    Department(const string& surname, double budget);
    void AddEmployee(const Employee& employee, bool bad);
    Employee& findS(const string& surname);
    void printDepartment();
    void delAllDepartment();
    void KickOutEmployee(int iter);
    int findI(const string& surname);
    void remove(const Employee& employee);
    bool has(const Employee& employee);
    string GetTitle() const;
    void SetTitle(const string& title);
    int GetAmount() const;
    double GetBudg() const;
    void SetBudg(double budget);
    bool IsChiefBad() const;
    void SetBadChief(bool bad);
    Department(const Department& departm);
    void operator =(const Department& departm);
    Employee& Get(int iter);
};
