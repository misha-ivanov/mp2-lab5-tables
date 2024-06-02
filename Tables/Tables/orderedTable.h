#pragma once
#include <iostream>
#include <vector>
#include "cell.h"
#include "polinom.h"
#include <algorithm>

template <class Tkey, class Tdata>

class orderedTable {
	vector<Cell<Tkey, Tdata>> table;
public:
	orderedTable() {
		table = vector<Cell<Tkey, Tdata>>();
	}

	vector<Cell<Tkey, Tdata>> tableOut() {
		return table;
	}

	void Push(Cell<Tkey, Tdata> cell) {
		int COUNTER = 0;

		int key = cell.keyOut();
		COUNTER++;
		int l = 0, r = max((int)(table.size() - 1), 0);
		COUNTER += 2;
		while (r - l > 1) {
			int i = (l + r) / 2;
			COUNTER += 5;
			if (table[i].keyOut() < key) {
				l = i + 1;
				COUNTER += 4;
			}
			else
				if (table[i].keyOut() > key) {
					r = i - 1;
					COUNTER += 4;
				}
		}
		if (r == l) {
			COUNTER++;
			if (table.size() == 0) {
				table.push_back(cell);
				COUNTER += 2;
			}
			else{
				table.push_back(table[table.size() - 1]);
				COUNTER += 3;
				if(table[r].keyOut() < key){
					COUNTER += 2;
					for (int i = table.size() - 2; i > r; i--) {
						table[i] = table[i - 1];
						COUNTER += 5;
					}
					table[r+1] = cell;
					COUNTER++;
					}
				else{
					for (int i = table.size() - 2; i >= r; i--) {
						table[i] = table[i - 1];
						COUNTER += 5;
					}
					table[r] = cell;
					COUNTER++;
					}
				}
		}
		else {
			table.push_back(table[table.size() - 1]);
			COUNTER += 3;
			if (table[r].keyOut() < key) {
				COUNTER += 3;
				for (int i = table.size() - 2; i > r; i--) {
					table[i] = table[i - 1];
					COUNTER += 5;
				}
				table[r + 1] = cell;
				COUNTER++;
				}
			else{
				for (int i = table.size() - 2; i >= r; i--) {
					table[i] = table[i - 1];
					COUNTER += 5;

				}
				table[r] = cell;
				COUNTER++;
				}	
			}
		cout << COUNTER;
	}

	int Find(Tkey _key) {
		int COUNTER = 0;

		int l = 0, r = max((int)(table.size() - 1), 0);
		COUNTER += 4;
		while (r > l) {
			COUNTER += 2;
			int i = (l + r) / 2;
			COUNTER += 3;
			if (table[i].keyOut() < _key) {
				l = i + 1;
				COUNTER += 4;
			}
			else
				if (table[i].keyOut() > _key) {
					r = i - 1;
					COUNTER += 4;
				}
				else {
					cout << COUNTER;
					return i;
				}
		}

		if ((table.size() != 0)&&(table[l].keyOut() == _key)) {
			COUNTER += 2;
			cout << COUNTER;
			return l;
		}
		else {
			COUNTER += 2;
			cout << COUNTER;
			throw "Cell isn't found";
		}
	}

	void Delete(Tkey _key){
		int COUNTER = 0;
		int index = Find(_key);
		COUNTER++;
		COUNTER++;
		for (int i = index; i < table.size() - 1; i++) {
			table[i] = table[i+1];
			COUNTER += 5;
		}
		table.pop_back();
		COUNTER++;
		cout << COUNTER;
	}
};