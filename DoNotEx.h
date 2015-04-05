// Copyright 2015 <Anna Simakova>
#pragma once
#include <exception>
#include <string>

using namespace std;

class EmployeeDoNotExist :public exception{
	string qq;
public:
	EmployeeDoNotExist(const string&);
	const char* what() const noexcept(true);
};
