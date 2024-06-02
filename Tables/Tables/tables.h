#pragma once

#include <iostream>
#include "list.h"
#include "polinom.h"
#include "unorderedTable.h"
#include "orderedTable.h"
#include "hashTable.h"

using namespace std;

template<class Tkey, class Tdata>

class Tables {
	unorderedTable<Tkey, Tdata> UnT;
	orderedTable<Tkey, Tdata> OrT;
	hashTable<Tkey, Tdata> HT;

public:

	Tables() {
		UnT = unorderedTable<Tkey, Tdata>();
		OrT = orderedTable<Tkey, Tdata>();
		HT = hashTable<Tkey, Tdata>();
	};

	Tables(int _N) {
		UnT = unorderedTable<Tkey, Tdata>();
		OrT = orderedTable<Tkey, Tdata>();
		HT = hashTable<Tkey, Tdata>(_N);
	};

	void Push(Cell<Tkey, Tdata> cell) {
		cout << "SAVE" << endl;
		cout << endl << "Unordered table:";
		UnT.Push(cell);
		cout << endl << "Ordered table:";
		OrT.Push(cell);
		cout << endl << "Hash table:";
		HT.Push(cell);
	}

	void Delete(Tkey _key) {
		cout << endl << endl << "DELETE" << endl;
		cout << endl << "Unordered table:";
		UnT.Delete(_key);
		cout << endl << "Ordered table:";
		OrT.Delete(_key);
		cout << endl << "Hash table:";
		HT.Delete(_key);
	}

	void Find(Tkey _key) {
		cout << endl << endl << "FIND" << endl;
		cout << endl << "Unordered table:";
		UnT.Find(_key);
		cout << endl << "Ordered table:";
		OrT.Find(_key);
		cout << endl << "Hash table:";
		HT.Find(_key);
	}
};