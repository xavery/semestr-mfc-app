#include "stdafx.h"
#include "lista.h"

lista* lista::poczatek = NULL;
unsigned int lista::wielkosc = 0;

bool lista::dodaj(towar tow)
{
	if(poczatek == NULL)
	{
		elem = tow;
		nastepny = NULL;
		poczatek = this;
		++wielkosc;
	}
	else
	{
		lista *tmp = poczatek;
		lista *nowy = new lista;
		if(nowy == NULL) return false;
		while(tmp->nastepny != NULL) tmp = tmp->nastepny;
		tmp->nastepny = nowy;
		nowy->elem = tow;
		nowy->nastepny = NULL;
		++wielkosc;
	}
	return true;
}

towar& lista::zwroc(unsigned int ind)
{
	if((ind <= 0) || (ind > (wielkosc+1))) return towar(0);
	lista* temp = poczatek;
	while(temp->nastepny != NULL)
	{
		if((temp->elem.getindeks()) == ind) break;
		temp = temp->nastepny;
	}
	return (temp->elem);
}

unsigned int lista::getwielkosc() { return wielkosc; }

bool lista::implode()
{
	if(wielkosc == 0) return false;
	lista *temp = poczatek->nastepny;
	lista *nastepny;
	while(temp != NULL)
	{
		nastepny = temp->nastepny;
		delete temp;
		temp = nastepny;
	}
	elem = towar(0);
	poczatek = NULL;
	nastepny = NULL;
	wielkosc = 0;
	return true;
}

bool lista::usun(unsigned int ind)
{
	if(wielkosc <= 2) return false;
	lista *poprz = poczatek;
	lista *usuw;
	while(poprz->nastepny != NULL)
	{
		usuw = poprz->nastepny;
		if(usuw->elem.getindeks() == ind) break;
		poprz = poprz->nastepny;
	}
	poprz->nastepny = usuw->nastepny;
	delete usuw;
	--wielkosc;
	return true;
}

bool lista::swaptow(towar tow)
{
	elem = tow;
	return true;
}

std::ostream& operator<<(std::ostream& output,lista &lst)
{
	output << "39b5d4cbeb25f42e5ab407e963ee20dc\n" << lst.wielkosc << '\n';
	for(unsigned int i=1;i<=lst.wielkosc;++i) output << lst.zwroc(i);
	return output;
}

std::istream& operator>>(std::istream &input,lista &lst)
{
	std::string checksum("39b5d4cbeb25f42e5ab407e963ee20dc");
	std::string read_checksum;
	input >> read_checksum;
	if(read_checksum != checksum) throw "Niepoprawny format pliku!";
	int wielkosc;
	input >> wielkosc;
	towar nowy;
	for(int i=0;i<wielkosc;++i)
	{
		input >> nowy;
		lst.dodaj(nowy);
	}
	return input;
}

// funkcje szukajace lol

std::vector<unsigned int> lista::szukaj(CString naz,double cen_low,double cen_up,unsigned int ilo_low,unsigned int ilo_up)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getnazwa().Find(naz,0) != -1) && (temp.getcena() >= cen_low) && (temp.getcena() <= cen_up)
			&& (temp.getilosc() >= ilo_low) && (temp.getilosc() <= ilo_up)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(CString naz,double cena,unsigned int ilo_low,unsigned int ilo_up)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getnazwa().Find(naz,0) != -1) && (temp.getcena() == cena) &&
			(temp.getilosc() >= ilo_low) && (temp.getilosc() <= ilo_up)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(CString naz,double cen_low,double cen_up,unsigned int ilosc)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getnazwa().Find(naz,0) != -1) && (temp.getcena() >= cen_low) && (temp.getcena() <= cen_up)
			&& (temp.getilosc() == ilosc)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(CString naz,double cena,unsigned int ilosc)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getnazwa().Find(naz,0) != -1) && (temp.getcena() == cena)
			&& (temp.getilosc() == ilosc)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(CString naz,unsigned int ilosc)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getnazwa().Find(naz,0) != -1) && (temp.getilosc() == ilosc)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(CString naz,unsigned int ilo_low,unsigned int ilo_up)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getnazwa().Find(naz,0) != -1) && (temp.getilosc() >= ilo_low)
			&& (temp.getilosc() <= ilo_up)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(CString naz,double cena)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getnazwa().Find(naz,0) != -1) && (temp.getcena() == cena)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(CString naz,double cen_low,double cen_up)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getnazwa().Find(naz,0) != -1) && (temp.getcena() >= cen_low)
			&& (temp.getcena() <= cen_up)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(CString naz)
{
	towar temp;
	std::vector<unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if(temp.getnazwa().Find(naz,0) != -1) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(double cen_low,double cen_up,unsigned int ilo_low,unsigned int ilo_up)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getcena() >= cen_low) && (temp.getcena() <= cen_up)
			&& (temp.getilosc() >= ilo_low) && (temp.getilosc() <= ilo_up)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(double cena,unsigned int ilo_low,unsigned int ilo_up)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getcena() == cena) &&
			(temp.getilosc() >= ilo_low) && (temp.getilosc() <= ilo_up)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(double cen_low,double cen_up,unsigned int ilosc)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getcena() >= cen_low) && (temp.getcena() <= cen_up)
			&& (temp.getilosc() == ilosc)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(double cena,unsigned int ilosc)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getcena() == cena)
			&& (temp.getilosc() == ilosc)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(unsigned int ilosc)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getilosc() == ilosc)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(unsigned int ilo_low,unsigned int ilo_up)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getilosc() >= ilo_low)
			&& (temp.getilosc() <= ilo_up)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(double cena)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getcena() == cena)) indeksy.push_back(i);
	}
	return indeksy;
}

std::vector<unsigned int> lista::szukaj(double cen_low,double cen_up)
{
	towar temp;
	std::vector <unsigned int> indeksy;
	for(unsigned int i=1;i<=wielkosc;++i)
	{
		temp = zwroc(i);
		if((temp.getcena() >= cen_low)
			&& (temp.getcena() <= cen_up)) indeksy.push_back(i);
	}
	return indeksy;
}