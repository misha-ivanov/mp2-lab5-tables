#include <gtest.h>
#include "polinom.h"
#include "list.h"
#include "cell.h"
#include "hashTable.h"


TEST(hashTable, can_initialize_N) {
	hashTable<int, Polinom> H(3);
	EXPECT_EQ(H.NOut(), 3);
}

TEST(hashTable, can_initialize_data) {
	hashTable<int, Polinom> H(3);

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Cell<int, Polinom> C(2, P);
	H.Push(C);

	EXPECT_EQ(H.tableOut()[2].HeadOut()->next->data.dataOut() == P, true);
}

TEST(hashTable, can_count_hash) {
	hashTable<int, Polinom> H(3);

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Cell<int, Polinom> C(5, P);

	EXPECT_EQ(H.Hash(C.keyOut()), 2);
}

TEST(hashTable, can_push_true_check) {
	hashTable<int, Polinom> H(3);

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	H.Push(C1);
	H.Push(C2);

	EXPECT_EQ(H.tableOut()[2].HeadOut()->next->next->data.dataOut() == P2, true);
}

TEST(hashTable, can_push_false_check) {
	hashTable<int, Polinom> H(3);

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	H.Push(C1);
	H.Push(C2);

	EXPECT_EQ(H.tableOut()[2].HeadOut()->next->next->data.dataOut() == P1, false);
}

TEST(hashTable, can_find_true_check) {
	hashTable<int, Polinom> H(3);

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	H.Push(C1);
	H.Push(C2);

	EXPECT_EQ(H.Find(5) == C2, true);
}

TEST(hashTable, can_find_false_check) {
	hashTable<int, Polinom> H(3);

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	H.Push(C1);

	EXPECT_ANY_THROW(H.Find(5));
}

TEST(hashTable, can_delete_true_check) {
	hashTable<int, Polinom> H(3);

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	H.Push(C1);
	H.Push(C2);
	H.Delete(2);

	EXPECT_ANY_THROW(H.Find(2));
}

TEST(hashTable, can_delete_false_check) {
	hashTable<int, Polinom> H(3);

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	H.Push(C1);

	EXPECT_ANY_THROW(H.Delete(5));
}

