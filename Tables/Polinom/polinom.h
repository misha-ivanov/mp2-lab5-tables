#pragma once

#include "list.h"
#include <iostream>

using namespace std;

struct Monom {
	double k;
	int deg;
public:
	Monom() {
		k = 0;
		deg = 0;
	}

	Monom(double _k, int _deg) {
		if (_deg > 999 || _deg < 0)
			throw "deg_is_out_of_range";
		k = _k;
		deg = _deg;
	}

	void operator =(const Monom& m) {
		k = m.k;
		deg = m.deg;
	}

	bool operator >(const Monom& m) {
		if ((deg > m.deg)||(deg == m.deg && k > m.k))
			return true;
		return false;
	}

	bool operator <(const Monom& m) {
		if ((deg < m.deg) || (deg == m.deg && k < m.k))
			return true;
		return false;
	}

	bool operator ==(const Monom& m) {
		if ((deg == m.deg) && (k == m.k))
			return true;
		return false;
	}
	
	bool operator !=(const Monom& m) {
		return !(*this == m); 
	}
};

class Polinom {
	List<Monom> poli;
public:
	Polinom() {
		poli = List<Monom>();
	}

	Polinom(const Polinom& p);
	
	List<Monom> PoliOut() { return poli; }

	void SearchSimilar();

	void Push(Monom monom);

	void Show();

	void DeleteZeroMonoms();

	//void Sort();

	void operator +=(Polinom& p);

	Polinom& operator =(const Polinom& _p);

	Polinom& operator =(double _k);

	Polinom& operator =(int _k);

	Polinom& operator +(Polinom& _p);

	Polinom& operator -(Polinom& _p);

	Polinom& operator *(double p);

	Polinom& operator *(Polinom& _p);

	bool operator ==(Polinom& _p);

	bool operator >(Polinom& _p);

	bool operator <(Polinom& _p);

	friend ostream& operator <<(ostream& out, Polinom p) {
		Node<Monom>* tmp = p.PoliOut().HeadOut();
		while (tmp->next != nullptr) {
			if (tmp == p.PoliOut().HeadOut()) {
				if (tmp->next->data.k != 1 && tmp->next->data.k != -1 || tmp->next->data.deg == 0)
					out << tmp->next->data.k;
				else {
					if (tmp->next->data.k == -1)
						out << "-";
				}
				if (tmp->next->data.deg / 100 != 0)
					out << " x^" << tmp->next->data.deg / 100;
				if (tmp->next->data.deg / 10 % 10 != 0)
					out << " y^" << tmp->next->data.deg / 10 % 10;
				if (tmp->next->data.deg % 100 != 0)
					out << " z^" << tmp->next->data.deg % 10;
			}
			else {
				if (tmp->next->data.k >= 0)
					out << " + ";
				else
					out << " - ";
				if (tmp->next->data.k != 1 && tmp->next->data.k != -1)
					out << abs(tmp->next->data.k);
				if (tmp->next->data.deg / 100 != 0)
					out << " x^" << tmp->next->data.deg / 100;
				if (tmp->next->data.deg / 10 % 10 != 0)
					out << " y^" << tmp->next->data.deg / 10 % 10;
				if (tmp->next->data.deg % 100 != 0)
					out << " z^" << tmp->next->data.deg % 10;
			}
			tmp = tmp->next;
		}
		return out;
	};
};
