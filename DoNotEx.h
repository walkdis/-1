// Copyright 2015 <Anna Simakova>
#pragma once
#include <exception>
#include <string>

using ::std::string;
using ::std::exception;

class EmployeeDoNotExist:public exception {
    string msg;

 public:
    explicit EmployeeDoNotExist(const string& name);
    const char* what() const throw();
};
