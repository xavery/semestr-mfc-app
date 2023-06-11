#include "stdafx.h"
#include "towar.h"

towar::towar():indeks(0),nazwa(' '),cena(-1),ilosc(0),koment(' ') { }

towar::towar(unsigned int ind):indeks(ind),nazwa(' '),cena(-1),ilosc(0),koment(' ') { }

towar::towar(unsigned int ind,CString naz,double cen,unsigned int ilo,CString kom):indeks(ind),nazwa(naz),cena(cen),ilosc(ilo),koment(kom) { }

unsigned int towar::getindeks() { return indeks; }

CString towar::getnazwa() { return nazwa; }

double towar::getcena() { return cena; }

unsigned int towar::getilosc() { return ilosc; }

CString towar::getkoment() { return koment; }

unsigned int& towar::modindeks() { return indeks; }

void towar::operator++() { ++ilosc; }

std::ostream& operator<<(std::ostream &output,towar &tow)
{
	output << tow.indeks << ' ' << tow.cena << ' ' << tow.ilosc << ' ';
	int dlug_naz = tow.nazwa.GetLength();
	output << dlug_naz << ' ';
	for(int i=0;i<dlug_naz;++i) output << (int)tow.nazwa[i] << ' ';
	int dlug_kom = tow.koment.GetLength();
	if(dlug_kom == 0) { output << "E\n"; return output; }
	output << dlug_kom << ' ';
	for(int i=0;i<dlug_kom;++i) output << (int)tow.koment[i] << ' ';
	output << "E\n";
	return output;
}

std::istream& operator>>(std::istream &input,towar &tow)
{
	unsigned int indeks;
	double cena;
	unsigned int ilosc;
	input >> indeks;
	input >> cena;
	input >> ilosc;
	int rozm_nazw;
	input >> rozm_nazw;
	int* nazw_int = new int[rozm_nazw];
	for(int i=0;i<rozm_nazw;++i) input >> nazw_int[i];
	char* nazw_char = new char[rozm_nazw+1];
	for(int i=0;i<rozm_nazw;++i) nazw_char[i] = nazw_int[i];
	delete[] nazw_int;
	nazw_char[rozm_nazw] = '\0';
	int rozm_komm(0);
	input >> rozm_komm;
	if((input.fail()) || (rozm_komm == 0))
	{
		tow = towar(indeks,CString(nazw_char),cena,ilosc,CString(""));
		input.clear();
		input.seekg(2,std::ios::cur);
		return input;
	}
	int* komm_int = new int[rozm_komm];
	for(int i=0;i<rozm_komm;++i) input >> komm_int[i];
	char* komm_char = new char[rozm_komm+1];
	for(int i=0;i<rozm_komm;++i) komm_char[i] = komm_int[i];
	komm_char[rozm_komm] = '\0';
	delete[] komm_int;
	tow = towar(indeks,CString(nazw_char),cena,ilosc,CString(komm_char));
	input.seekg(2,std::ios::cur);
	return input;
}