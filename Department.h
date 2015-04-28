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

class Department {
 private:
  string title;
  int amount;
  double budget;
  bool BadChief;
  list<Employee> pList;

 public:
  Department();
  ~Department();
  Department(const string& surname, int amount, double budget);
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
  void SetAmount(const int amount);
  double GetBudg() const;
  void SetBudg(const double budget);
  bool IsChiefBad() const;
  void SetBadChief(const bool bad);
  friend const bool operator ==(Department departm1, const Department departm2);
  Department(const Department& departm);
  const Department& operator =(const Department& departm);
  Employee& Get(int iter);
};
