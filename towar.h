#pragma once

#include <fstream>

class towar
{
private:
	unsigned int indeks;
	CString nazwa;
	double cena;
	unsigned int ilosc;
	CString koment;
public:
	towar();
	towar(unsigned int);
	towar(unsigned int,CString,double,unsigned int,CString);
	unsigned int getindeks();
	CString getnazwa();
	double getcena();
	unsigned int getilosc();
	CString getkoment();
	unsigned int& modindeks();
	void operator++();
	friend std::istream& operator>>(std::istream&,towar&);
	friend std::ostream& operator<<(std::ostream&,towar&);
};