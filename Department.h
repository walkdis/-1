// Copyright 2015 <Anna Simakova>
#pragma once
#include "Sotr.h"
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

class Department :public Employee {
 private:
  string title;
  int amount;
  double budget;
  bool BadChief;
  list<Employee> pList;

 public:
  Department();
  ~Department();
  Department(const string&, const int, const double);
  void CreateEmployee(const string&,
  const string&, const bool, const bool, const double);
  void AddEmployee(const Employee&, const bool);
  void GivePR();
  Employee& findS(const string&);
  void printDepartment();
  void delAllDepartment();
  void KickOutEmployee(int i);
  int findI(const string&);
  void remove(const Employee&);
  bool has(const Employee&);
  string GetTitle() const;
  void SetTitle(const string&);
  int GetAmount() const;
  void SetAmount(const int);
  double GetBudg() const;
  void SetBudg(const double);
  bool IsChiefBad() const;
  void SetBadChief(const bool);
  friend bool operator ==(Department, const Department);
  Department(const Department&);
  const Department& operator =(const Department&);
  Employee& Get(int i);
};
