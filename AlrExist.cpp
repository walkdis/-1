// Copyright 2015 <Anna Simakova>
#include "AlrExist.h"
#include <string>


EmployeeAlrExist::EmployeeAlrExist(const string& name) :exception() {
  qq = "Employee: " + name + " already exist";
}
const char * EmployeeAlrExist::what() const noexcept(true) {
  return qq.c_str();
}
