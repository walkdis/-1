// Copyright 2015 <Anna Simakova>
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "AlrExist.h"
#include "DoNotEx.h"
using ::std::string;
using ::std::cin;
using ::std::cout;
using ::std::ostream;
using std::endl;

class Employee {
    string sur;
    string job;
    double salary;
    bool rab;
    bool chief;

 public:
    Employee();
    Employee(const string& surname, const string& job, bool chief,
        double salary);
    void ChD(const string& job);
    explicit Employee(double amount);
    double operator -(double amount);
    double operator +(double amount);
    friend ostream& operator<<(ostream& stream, const Employee& empl);
    ~Employee();
    string GetSur() const;
    void SetSur(const string& surname);
    string GetJob() const;
    void SetJob(const string& job);
    double GetSalary() const;
    void SetSalary(double salary);
    bool IsChief() const;
    void SetChief(bool chief);
    bool GetRab() const;
    void SetRab(bool rab);
    Employee(const Employee& empl);
    const Employee& operator =(const Employee& empl);
    bool operator ==(const Employee& empl);
};
