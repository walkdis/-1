// Copyright 2015 <Anna Simakova>
#pragma once
#include <exception>
#include <string>

using ::std::string;
using ::std::exception;

class EmployeeDoNotExist :public exception {
  string qq;

 public:
  explicit EmployeeDoNotExist(const string&);
  const char* what() const noexcept(true);
};
