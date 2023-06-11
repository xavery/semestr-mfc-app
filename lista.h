#pragma once

#include <fstream>
#include <vector>
#include <string>
#include "towar.h"

class lista
{
private:
	towar elem;
	lista* nastepny;
	static lista* poczatek;
	static unsigned int wielkosc;
public:
	bool dodaj(towar);
	towar& zwroc(unsigned int);
	bool implode();
	bool usun(unsigned int);
	unsigned int getwielkosc();
	bool swaptow(towar);
	std::vector<unsigned int> szukaj(CString,double,double,unsigned int,unsigned int);
	std::vector<unsigned int> szukaj(CString,double,unsigned int,unsigned int);
	std::vector<unsigned int> szukaj(CString,double,double,unsigned int);
	std::vector<unsigned int> szukaj(CString,double,unsigned int);
	std::vector<unsigned int> szukaj(CString,unsigned int);
	std::vector<unsigned int> szukaj(CString,unsigned int,unsigned int);
	std::vector<unsigned int> szukaj(CString,double);
	std::vector<unsigned int> szukaj(CString,double,double);
	std::vector<unsigned int> szukaj(CString);
	std::vector<unsigned int> szukaj(double,double,unsigned int,unsigned int);
	std::vector<unsigned int> szukaj(double,unsigned int,unsigned int);
	std::vector<unsigned int> szukaj(double,double,unsigned int);
	std::vector<unsigned int> szukaj(double,unsigned int);
	std::vector<unsigned int> szukaj(unsigned int);
	std::vector<unsigned int> szukaj(unsigned int,unsigned int);
	std::vector<unsigned int> szukaj(double);
	std::vector<unsigned int> szukaj(double,double);
	friend std::ostream& operator<<(std::ostream&,lista&);
	friend std::istream& operator>>(std::istream&,lista&);
};