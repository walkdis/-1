#include "stdafx.h"
#include "Sotr.h"
#include "SP.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Sotr::Sotr()
{
	sur = "";
	dolzh = "";
	rab = true;
}
Sotr::Sotr(string ty, string dol, double lop)
{
	sur = ty;
	dolzh = dol;
	oklad = lop;
	rab = true;
}
void Sotr::ChD(const Sotr& lol)
{
	cout << "Введите новую должность для " << lol.sur;
	getline(cin, dolzh);
}
Sotr Sotr::Del(Sotr& ok) const
{
	ok.rab = false;
	return ok.rab;
}
Sotr Sotr::operator-(const Sotr& ok) const
{
	double k;
	cout << "На какую сумму понижаем?\n";
	cin >> k;
	return (ok.oklad - k);
}
Sotr Sotr::operator+(const Sotr& ok) const
{
	double k;
	cout << "На какую сумму повышаем?\n";
	cin >> k;
	return (ok.oklad + k);
}
Sotr::~Sotr()
{
	delete(link);
}
SP::SP()
{
	NP = "";
	pList == NULL;
	NS = 0;
	budzh = 0.0;
	NachBad = true;
}
SP::~SP()
{
	delAllSP();
}
SP::SP(string poi, int rest, double tr)
{
	NP = poi;
	NS = rest;
	budzh = tr;
	pList = (Sotr *)malloc(sizeof(Sotr)*NS);
	for (int i = 0; i < NS; i++)
	{
		cout << "Введите фамилию, должность(руководящую введите как Nachalnik) и оклад сотрудника\n";
		getline(cin, pList[i].sur);
		getline(cin, pList[i].dolzh);
		if (pList[NS].dolzh == "Nachalnik")
		{
			pList[NS].nach = true;
			cout << "Начальник плохой?(Y or N)\n";
			char c;
			cin >> c;
			if (c == 'Y')
				NachBad = true;
			else NachBad = false;
		}
		else pList[i].nach = false;
		cin >> pList[i].oklad;
		pList[i].rab = true;
	}
}
void SP::CreateSotr()
{
	NS += 1;
	pList = (Sotr *)realloc(pList, sizeof(Sotr)*NS);
	cout << "Введите фамилию, должность(руководящую введите как Nachalnik) и оклад сотрудника\n";
	getline(cin, pList[NS].sur);
	getline(cin, pList[NS].dolzh);
	if (pList[NS].dolzh == "Nachalnik")
	{
		pList[NS].nach = true;
		cout << "Начальник плохой?(Y or N)\n";
		char c;
		cin >> c;
		if (c == 'Y')
			NachBad = true;
		else NachBad = false;
	}
	else pList[NS].nach = false;
	cin >> pList[NS].oklad;
	pList[NS].rab = true;
}
void SP::KickOutSotr(int l)
{
	for (int i = l; i <= NS; i++)
	{
		pList[i] = pList[i + 1];
	}
	NS -= 1;
	pList = (Sotr *)realloc(pList, sizeof(Sotr)*NS);
}
Sotr SP::findS(string l)
{
	for (int i = 0; i < NS; i++)
	{
		if (pList[i].sur == l)
			return pList[i];
	}
}
int SP::findI(string l)
{
	for (int i = 0; i < NS; i++)
	{
		if (pList[i].sur == l)
			return i;
	}
}
void SP::printSP()
{
	cout << NP<<" ";
	for (int i = 0; i < NS; i++)
	{
		cout << pList[i].sur << " " << pList[i].dolzh << " " << pList[i].oklad;
	}
}
void SP::delAllSP()
{
	free(pList);
}
void SP::GivePR()
{
	if (NachBad = true)
	{
		for (int i = 0; i < NS; i++)
		{
			if (pList[i].nach = true)
				pList[i].prem = budzh / 2;
			else pList[i].prem = budzh / 2 / (NS-1);
		}
	}
	else for (int i = 0; i < NS; i++)
		pList[i].prem = budzh / NS;
}
ostream& operator<<(ostream& stream, const Sotr& qw)
{
stream << "Фамилия " << qw.sur << "Должность " << qw.dolzh << "Оклад " << qw.oklad<< endl;
return stream;
}

int main()
{
	setlocale(LC_ALL, "rus");
	string cmd;
	int cmnd, k=0;
	double red;
	cout << "Необходимо создать отдел. Введите параметры\n";
	cout << "Назовите отдел\n";
	cin >> cmd;
	cout << "Сколько там сотрудников?\n";
	cin >> cmnd;
	cout << "Сколько денег выделяют на отдел?\n";
	cin >> red;
	SP *q1 = new SP(cmd, cmnd, red);
	do
	{
		cout << "Что бы вы хотели сделать еще?\n(раздать всем премию - введите 2, понизить зарплату - введите 3\n повысить зарплату - введите 4, сменить должность сотруднику - введите 5\nуволить сотрудника - введите 6, добавить сотрудника в данный отдел - введите 7\n убрать сотрудника из базы - введите 8, просмотреть отдел - введите 9\n если хотите выйти из программы нажмите 0";
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
				q1->operator-(q1->findS(cmd));
			if (k == 4)
				q1->operator+(q1->findS(cmd));
			if (k == 5)
				q1->ChD(q1->findS(cmd));
			if (k == 6)
				q1->Del(q1->findS(cmd));
		}
		if (k == 7)
			q1->CreateSotr();
		if (k == 8)
			q1->KickOutSotr(q1->findI(cmd));
		if (k == 9)
			q1->printSP();
	} while (k != 0);
	system("pause");
	return 0;
}

