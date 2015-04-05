// Copyright 2015 <Anna Simakova>
#pragma once
#include <exception>
#include <string>

using namespace std;

class EmployeeAlrExist :public exception{
	string qq;
public:
	EmployeeAlrExist(const string&);
	const char* what() const noexcept(true);
};
