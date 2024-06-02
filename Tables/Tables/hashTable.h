#pragma once
#include <iostream>
#include <vector>
#include "cell.h"
#include "polinom.h"

using namespace std;

template <class Tkey, class Tdata>
class hashTable {
	int N;
	vector <List<Cell<Tkey, Tdata>>> table;
public:
	hashTable() {
		N = 1;
		table = vector<List<Cell<Tkey, Tdata>>>(N);
	}

	hashTable(int _N) {
		N = _N;
		table = vector<List<Cell<Tkey, Tdata>>>(N);
	}

	int Hash(Tkey key) {
		return ((int)key % N);
	}

	int NOut() {
		return N;
	}

	vector<List<Cell<Tkey, Tdata>>> tableOut() {
		return table;
	}

	void Push(Cell<Tkey, Tdata> cell) {
		int COUNTER = 0;
		int index = Hash(cell.key);
		table[index].Push(cell);
		COUNTER += 4;
		cout << COUNTER;
	}

	Cell<Tkey, Tdata> Find(Tkey _key) {
		int COUNTER = 0;
		int index = Hash(_key);
		COUNTER += 2;
		Node<Cell<Tkey, Tdata>>* tmp_head = table[index].HeadOut();
		COUNTER += 3;
		while ((tmp_head->next != nullptr) && (tmp_head->next->data.keyOut() != _key)) {
			tmp_head = tmp_head->next;
			COUNTER += 6;
		}
		if (tmp_head->next == nullptr) {
			COUNTER++;
			cout << COUNTER;
			throw "Cell isn't found";
		}
		else {
			COUNTER++;
			cout << COUNTER;
			return tmp_head->next->data;
		}
	}

	void Delete(Tkey _key) {
		int COUNTER = 0;
		int index = Hash(_key);
		COUNTER += 2;
		Node<Cell<Tkey, Tdata>>* tmp_head = table[index].HeadOut();
		COUNTER += 3;
		while ((tmp_head->next != nullptr) && (tmp_head->next->data.keyOut() != _key)) {
			tmp_head = tmp_head->next;
			COUNTER += 6;
		}
		if (tmp_head->next == nullptr) {
			COUNTER++;
			cout << COUNTER;
			throw "Cell isn't found";
		}
		else {
			COUNTER+=3;
			cout << COUNTER;
			tmp_head->next = tmp_head->next->next;
		}
	}
};