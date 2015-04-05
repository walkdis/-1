// Copyright 2015 <Anna Simakova>
#include "stdafx.h"
#include "Sotr.h"
#include "SP.h"
#include <cstdlib>
#include <exception>


int main()
{
	setlocale(LC_ALL, "rus");
	string cmd, snm, jt;
	bool ch, bad = false; 
	int cmnd, k=0;
	double red, paym;
	cout << "Необходимо создать отдел. Введите параметры\n";
	cout << "Назовите отдел\n";
	cin >> cmd;
	cout << "Сколько там сотрудников?\n";
	cin >> cmnd;
	cout << "Сколько денег выделяют на отдел?\n";
	cin >> red;
	Department *q1 = new Department(cmd, cmnd, red);
	for (int i = 0; i < cmnd; i++)
	{
		cout << "Введите фамилию, должность(руководящую введите как Nachalnik) и оклад сотрудника\n";
		getline(cin, snm);
		getline(cin, jt);
		if (jt == "Nachalnik")
		{
			ch = true;
			cout << "Начальник плохой?(Y or N)\n";
			char c;
			cin >> c;
			if (c == 'Y')
				bad = true;
			else bad = false;
		}
		else ch = false;
		cin >> paym;
		q1->CreateEmployee(snm, jt, ch, bad, paym);

	}
	do
	{
		cout << "Что бы вы хотели сделать еще?\n(раздать всем премию - введите 2, понизить зарплату - введите 3\n повысить зарплату - введите 4, сменить должность сотруднику - введите 5\nдобавить сотрудника в данный отдел - введите 7\n убрать сотрудника из базы - введите 8, просмотреть отдел - введите 9\n если хотите выйти из программы нажмите 0";
		cin >> k;
		if (k == 2)
			q1->GivePR();
		if ((k > 2) & (k < 7))
		{
			cout << "Введите фамилию сотрудника\n";
			cin >> cmd;
			q1->findS(cmd);
			if (q1 == NULL)
			{
				cout << "Ошибка. Сотрудник не найден!\n";
				break;
			}
			if (k == 3)
			{
				double k;
				cout << "На какую сумму понижаем?\n";
				cin >> k;
				q1->operator-(k);
			}
			if (k == 4)
			{
				double k;
				cout << "На какую сумму повышаем?\n";
				cin >> k;
				q1->operator+(k);
			}
			if (k == 5)
				getline(cin, jt);
				q1->ChD(jt);
		}
		if (k == 7)
		{
			cout << "Введите фамилию, должность(руководящую введите как Nachalnik) и оклад сотрудника\n";
			getline(cin, snm);
			getline(cin, jt);
			if (jt == "Nachalnik")
			{
				ch = true;
				cout << "Начальник плохой?(Y or N)\n";
				char c;
				cin >> c;
				if (c == 'Y')
					bad = true;
				else bad = false;
			}
			else ch = false;
			cin >> paym;
			Employee empl(snm, jt, ch, paym);
			try {
				q1->AddEmployee(empl, bad);
			}catch (exception& e){
				cout << e.what()<< endl;
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
