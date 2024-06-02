#pragma once
#include <iostream>
#include "list.h"
#include "polinom.h"


template <class Tkey, class Tdata>
struct Cell {
	Tkey key;
	Tdata data;
public:
	Cell() {
		key = 0;
		data = 0;
	}

	Cell(Tkey _key) {
		key = _key;
	}

	Cell(Tkey _key, Tdata _data) {
		key = _key;
		data = _data;
	}

	Cell(const Cell<Tkey, Tdata>& p) {
		key = p.key;
		data = p.data;
	}

	void Show() {
			cout << "Key: " << key << endl << "Data: " << data;
	}

	Tkey keyOut() {
		return key;
	}

	Tdata dataOut() {
		return data;
	}

	Cell<Tkey, Tdata>& operator =(Cell<Tkey, Tdata>& p) {
		key = p.key;
		data = p.data;
		return *this;
	}

	bool operator ==(Cell<Tkey, Tdata>& p) {
		if ((key == p.key)&&(data == p.data))
			return true;
		else
			return false;
	}

	bool operator !=(Cell<Tkey, Tdata>& p) {
		return !(*this == p);
	}

	bool operator >(Cell<Tkey, Tdata>& p) {
		return (data > p.data);
	}

	bool operator <(Cell<Tkey, Tdata>& p) {
		return (data < p.data);
	}
};