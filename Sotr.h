#include <iostream>
#include <string>

using namespace std;

class Sotr
{
public:
	string sur;
	string dolzh;
	double oklad;
	double prem;
	bool rab;
	bool nach;
	Sotr * link;

	Sotr();
	Sotr(string, string, double);
	void ChD(const Sotr&);
	Sotr Sotr::Del(Sotr&) const;
	Sotr(double l) : oklad(l) {}
	Sotr operator -(const Sotr&) const;
	Sotr operator +(const Sotr&) const;
	friend ostream& operator<<(ostream&, const Sotr&);
	~Sotr();
};
