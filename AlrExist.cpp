// Copyright 2015 <Anna Simakova>
#include "AlrExist.h"
#include <string>


EmployeeAlrExist::EmployeeAlrExist(const string& name) :exception() {
    msg = "Employee: " + name + " already exist";
}
const char * EmployeeAlrExist::what() const throw() {
    return msg.c_str();
}
