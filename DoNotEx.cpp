// Copyright 2015 <Anna Simakova>
#include "DoNotEx.h"
#include <string>

EmployeeDoNotExist::EmployeeDoNotExist(const string& name) :exception() {
    msg = "Sotr: " + name + " do not exist";
}
const char * EmployeeDoNotExist::what() const throw() {
    return msg.c_str();
}
