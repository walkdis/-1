// Copyright 2015 <Anna Simakova>
#include "stdafx.h"
#include "DoNotEx.h"

EmployeeDoNotExist::EmployeeDoNotExist(const string& name) :exception(){
	qq = "Sotr: " + name + " do not exist";
}
const char * EmployeeDoNotExist::what() const noexcept(true){
	return qq.c_str();
}
