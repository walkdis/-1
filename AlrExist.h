// Copyright 2015 <Anna Simakova>
#pragma once
#include <exception>
#include <string>

using ::std::string;
using ::std::exception;

class EmployeeAlrExist :public exception {
  string qq;

 public:
  explicit EmployeeAlrExist(const string&);
  const char* what() const noexcept(true);
};
