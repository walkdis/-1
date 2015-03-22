#include <iostream>
#include <string>

using namespace std;

class SP:public Sotr
{
private:
	string NP; // название подразделения
	int NS; // количество сотрудников
	double budzh; // бюджет отдела(зарплаты, премии)
	bool NachBad; // начальник бяка((((
	Sotr *pList; // список сотрудников подразделения
	SP *top;
public:
	SP();
	~SP();
	SP(string, int, double);
	void CreateSotr();
	void GivePR();
	Sotr findS(string);
	void printSP();
	void delAllSP();
	void KickOutSotr(int);
	int findI(string);
};
