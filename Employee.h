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
  bool rab;
  bool chief;

 public:
  Employee();
  Employee(const string& surname, const string& job, bool chief, double salary);
  void ChD(const string& job);
  explicit Employee(double amount);
  double operator -(const double amount);
  double operator +(const double amount);
  friend ostream& operator<<(ostream& stream, const Employee& empl);
  ~Employee();
  string GetSur() const;
  void SetSur(const string& surname);
  string GetJob() const;
  void SetJob(const string& job);
  double GetSalary() const;
  void SetSalary(const double salary);
  bool IsChief() const;
  void SetChief(const bool chief);
  bool GetRab() const;
  void SetRab(const bool rab);
  Employee(const Employee& empl);
  friend bool operator ==(Employee empl1, const Employee empl2);
  void operator =(const Employee& empl);
};
