// Copyright 2015 <Anna Simakova>
#include "Employee.h"
#include "Department.h"
#include <cstdlib>
#include <exception>
#include <string>


int main() {
  string cmd, snm, jt;
  bool ch, bad = false;
  int cmnd, k = 0;
  double red, paym;
  cout << "You must create a department. enter the parameters:\n";
  cout << "Name department\n";
  cin >> cmd;
  cout << "How many employees?\n";
  cin >> cmnd;
  cout << "How much money is allocated to the department?\n";
  cin >> red;
  Department *q1 = new Department(cmd, cmnd, red);
  for (int i = 0; i < cmnd; i++) {
  cout << "Enter the name, title (enter leadership as Chief) ";
  cout << "and the salary of the employee\n";
  getline(cin, snm);
  getline(cin, jt);
  if (jt == "Chief)") {
  ch = true;
  cout << "Chief bad? (Y or N)\n";
  char c;
  cin >> c;
  if (c == 'Y')
  bad = true;
  else
  bad = false;
  } else {
  ch = false;
  }
  cin >> paym;
  q1->CreateEmployee(snm, jt, ch, bad, paym);
}
  do {
  cout << "What would you like to do more?\n";
  cout << "give all the prize - enter 2, lower wages - enter 3\n";
  cout << "raise the salary - enter 4, change the position of the employee - ";
  cout << "enter the 5 \nAdd employee in this department - enter 7\n";
  cout << "remove the employee from base - enter 8, see Front - enter 9\n";
  cout << "if you want to exit the program, press 0";
  cin >> k;
  if (k == 2)
  q1->GivePR();
  if ((k > 2) & (k < 7)) {
  cout << "Enter the name of the employee\n";
  cin >> cmd;
  q1->findS(cmd);
  if (q1 == NULL) {
  cout << "Error. An employee can not be found!\n";
  break;
  }
  if (k == 3) {
  double k;
  cout << "How much downgrade?\n";
  cin >> k;
  q1->operator-(k);
  }
  if (k == 4) {
  double k;
  cout << "How much are raising?\n";
  cin >> k;
  q1->operator+(k);
  }
  if (k == 5)
  getline(cin, jt);
  q1->ChD(jt);
  }
  if (k == 7) {
  cout << "Enter the name, title (enter leadership as Chief)";
  cout << " and the salary of the employee\n";
  getline(cin, snm);
  getline(cin, jt);
  if (jt == "Chief)") {
  ch = true;
  cout << "Chief bad? (Y or N)\n";
  char c;
  cin >> c;
  if (c == 'Y')
  bad = true;
  else
  bad = false;
  } else { ch = false; }
  cin >> paym;
  Employee empl(snm, jt, ch, paym);
  try {
  q1->AddEmployee(empl, bad);
}
  catch (exception& e) {
  cout << e.what() << endl;
}
}
  if (k == 8)
  q1->KickOutEmployee(q1->findI(cmd));
  if (k == 9)
  q1->printDepartment();
} while (k != 0);
  system("pause");
  return 0;
}
