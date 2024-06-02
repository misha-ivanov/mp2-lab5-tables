#pragma once
#include <iostream>
#include <vector>
#include "cell.h"
#include "polinom.h"

template <class Tkey, class Tdata>

class unorderedTable {
	vector<Cell<Tkey, Tdata>> table;
public:
	unorderedTable() {
		table = vector<Cell<Tkey, Tdata>>();
	}

	vector<Cell<Tkey, Tdata>> tableOut() {
		return table;
	}

	void Push(Cell<Tkey, Tdata> cell) {
		int COUNTER = 0;

		table.push_back(cell);
		COUNTER++;

		cout << COUNTER;
	}

	int Find(Tkey _key) {
		int COUNTER = 0;

		int i = 0;
		COUNTER ++;
		while ((i < table.size()) && (table[i].keyOut() != _key)) {
			COUNTER += 3;
			i++;
		}
		COUNTER += 2;
		if (i == table.size()) {
			throw "Cell isn't found";
		}
		else {
			COUNTER++;
			cout << COUNTER;
			return i;
		}
	}

	void Delete(Tkey _key) {
		int COUNTER = 0;

		int index = Find(_key);
		COUNTER++;
		table[index] = table[table.size() - 1];
		table.pop_back();
		COUNTER += 3;
		cout << COUNTER;
	}
};