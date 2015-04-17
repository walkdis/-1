// Copyright 2015 <Anna Simakova>
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
using ::std::string;
using ::std::cin;
using ::std::cout;
using ::std::ostream;

class Employee {
  string sur;
  string job;
  double salary;
  double prem;
  bool rab;
  bool chief;

 public:
  Employee();
  Employee(const string&, const string&, const bool, const double);
  void ChD(const string&);
  explicit Employee(double k);
  double operator -(const double);
  double operator +(const double);
  friend ostream& operator<<(ostream&, const Employee&);
  ~Employee();
  string GetSur() const;
  void SetSur(const string&);
  string GetJob() const;
  void SetJob(const string&);
  double GetSalary() const;
  void SetSalary(const double);
  double GetPrem() const;
  void SetPrem(const double);
  bool IsChief() const;
  void SetChief(const bool);
  bool GetRab() const;
  void SetRab(const bool);
  Employee(const Employee&);
  friend bool operator ==(Employee, const Employee);
  void operator =(const Employee&);
};
