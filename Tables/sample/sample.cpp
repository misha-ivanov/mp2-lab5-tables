#include <iostream>
#include <vector>
#include "orderedTable.h"
#include "unorderedTable.h"
#include "hashTable.h"
#include "tables.h"
#include "list.h"
#include "cell.h"

using namespace std;

int main() {
	Tables<int, Polinom> T(10); // main table

	Cell<int, Polinom> cell;

	vector<Polinom> v {}; // storage of polinoms
	vector<Cell<int, Polinom>> v_cell{}; // storage of cells
	vector<int> v_key {};

	Polinom P;
	Monom M;

	int status = 2; // 0 - finish the program, 1 - add monom into this polinom

	double k; // coefficient
	double tmp;
	int i;
	int tmp_key;
	int deg; // degree of monom
	int term1, term2; // numbers of polioms for actions


	cout << "WELCOME to the POLINOM CREATOR !!!" << endl << "Here you can add as much monoms and polinoms of 'xyz' view as you want and make some arithmetic operations with them (+, -, *)." << endl;
	while (status != 0) {
		switch (status) {
		case 0:
			cout << "Have a nice day :)";
			return 0;
		case 1: // CREATE NEW MONOM
			cout << "Creating new monom. Please, enter:" << endl << "coefficient: ";
			cin >> k;
			cout << endl << "Degree of x: ";
			cin >> tmp;
			deg = tmp * 100;
			cout << endl << "Degree of y: ";
			cin >> tmp;
			deg = deg + tmp * 10;
			cout << endl << "Degree of z: ";
			cin >> tmp;
			deg = deg + tmp;
			M = Monom(k, deg);
			P.Push(M);
			status = 0;
			break;
		case 2: // CREATE NEW POLINOM
			P = Polinom();
			status = 1;
			break;
		case 3: // SAVE POLINOM
			cout << "Previous polinom was saved" << endl;

			v.push_back(P);
			status = 0;
			break;
		case 4: // SHOW EXISTING POLINOMS
			for (int i = 0; i < v.size(); i++) {
				cout << "#" << i + 1 << "   ";
				v[i].Show();
				cout << endl;
			}
			status = 0;
			break;
		case 5: // OPEARTIONS WITH POLINOMS
			P = Polinom();
			cout << "Choose an operation beneath:" << endl
				<< "1 - CONJUNCTION (+)" << endl
				<< "2 - SUBTRACTION (-)" << endl
				<< "3 - MULTIPLICATION (*)" << endl
				<< "4 - SAVE TO TABLES" << endl
				<< "5 - FIND IN TABLES" << endl
				<< "6 - DELETE FROM TABLES" << endl;
			cin >> status;
			try {
				switch (status) {
				case 1:  // +
					cout << "List of existing polinoms:" << endl;
					for (int i = 0; i < v.size(); i++) {
						cout << "#" << i + 1 << "   ";
						v[i].Show();
						cout << endl;
					}
					while (status == 1) {
						cout << "Choose number of first term: ";
						cin >> term1;
						cout << "Choose number of second term: ";
						cin >> term2;
						if (term1 < 1 || term2 < 1 || term1 > v.size() || term2 > v.size()) {
							cout << "You have entered non existing polinom. Try again.";
							status = 1;
						}
						else
							status = 0;
					}
					P = v[term1 - 1] + v[term2 - 1];
					break;
				case 2: // -
					cout << "List of existing polinoms:" << endl;
					for (int i = 0; i < v.size(); i++) {
						cout << "#" << i + 1 << "   ";
						v[i].Show();
						cout << endl;
					}
					while (status == 2) {
						cout << "Choose number of first term: ";
						cin >> term1;
						cout << "Choose number of second term: ";
						cin >> term2;
						if (term1 < 1 || term2 < 1 || term1 > v.size() || term2 > v.size()) {
							cout << "You have entered non existing polinom. Try again.";
							status = 2;
						}
						else
							status = 0;
					}
					P = v[term1 - 1] - v[term2 - 1];
					break;
				case 3: // *
					cout << "Would you like to multiply a polinom by a number or another polinom? Choose an option beneath:" << endl
						<< "0 - NUMBER" << endl
						<< "1 - POLINOM" << endl;
					cin >> status;
					if (status == 0) {
						cout << "List of existing polinoms:" << endl;
						for (int i = 0; i < v.size(); i++) {
							cout << "#" << i + 1 << "   ";
							v[i].Show();
							cout << endl;
						}
						status = 1;
						while (status == 1) {
							cout << "Choose number of polinom: ";
							cin >> term1;
							if (term1 < 1 || term1 > v.size()) {
								cout << "You have entered non existing polinom. Try again.";
								status = 1;
							}
							else
								status = 0;
						}
						cout << "Choose number to multiply: ";
						cin >> term2;
						P = v[term1 - 1] * double(term2);
					}
					if (status == 1) {
						cout << "List of existing polinoms:" << endl;
						for (int i = 0; i < v.size(); i++) {
							cout << "#" << i + 1 << "   ";
							v[i].Show();
							cout << endl;
						}
						while (status == 1) {
							cout << "Choose number of first term: ";
							cin >> term1;
							cout << "Choose number of second term: ";
							cin >> term2;
							if (term1 < 1 || term2 < 1 || term1 > v.size() || term2 > v.size()) {
								cout << "You have entered non existing polinom. Try again.";
								status = 1;
							}
							else
								status = 0;
						}
						P = v[term1 - 1] * v[term2 - 1];
					}
					break;
				case 4:
					cout << "List of existing polinoms:" << endl;
					for (int i = 0; i < v.size(); i++) {
						cout << "#" << i + 1 << "   ";
						v[i].Show();
						cout << endl;
					}
					while (status == 4) {
						cout << "Choose number of polinom: ";
						cin >> term1;
						if (term1 < 1 || term1 > v.size()) {
							cout << "You have entered non existing polinom. Try again.";
							status = 4;
						}
						else
							status = 0;
					}
					status = 4;
					cout << "Enter key of this cell: ";
					cin >> tmp_key;
					i = 0;
					while ((i < v_key.size()) && (v_key[i] != tmp_key))
						i++;
					if ((v_key.size() != i) && (v_key[i] == tmp_key))
						throw "This key already exist";
					else {
						cell = *new Cell<int, Polinom>(tmp_key, v[term1 - 1]);
						T.Push(cell);
						v_key.push_back(tmp_key);
						}
					break;
				case 5:
					cout << "Enter key of the cell which you want to find: ";
					cin >> tmp_key;
					T.Find(tmp_key);
					break;
				case 6:
					cout << "Enter key of the cell which you want to delete: ";
					cin >> tmp_key;
					T.Delete(tmp_key);
					break;
				default:
					break;
				}
			}
			catch (const char* str) 
			{
				cout << endl << endl << str << endl;
			}
			if (status < 4) {
				cout << "Your active polinom is:  ";
				P.Show();
				cout << "Would you like to save it? Choose an option beneath:" << endl
					<< "0 - NO" << endl
					<< "1 - YES" << endl;
				cin >> status;
				if (status == 1) {
					v.push_back(P);
					cout << "Previous polinom was saved" << endl;
				}
			}
			status = 0;
			break;
		default:
			break;
		}
		if (status != 1) {
			cout << endl << "Choose an option beneath:" << endl
				<< "0 - FINISH THE PROGRAM" << endl
				<< "1 - CREATE NEW MONOM" << endl
				<< "2 - CREATE NEW POLINOM" << endl
				<< "3 - SAVE ACTIVE POLINOM" << endl
				<< "4 - SHOW EXISTING POLINOMS" << endl
				<< "5 - OPERATIONS WITH POLINOMS" << endl;
			cin >> status;
		}
	}

	return 0;
}