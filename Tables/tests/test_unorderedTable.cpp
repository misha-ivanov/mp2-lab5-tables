#include <gtest.h>
#include "polinom.h"
#include "list.h"
#include "cell.h"
#include "unorderedTable.h"


TEST(unorderedTable, can_create) {
	unorderedTable<int, Polinom> U;
	EXPECT_EQ(U.tableOut().size(), 0);
}

TEST(unorderedTable, can_push) {
	unorderedTable<int, Polinom> U;

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	U.Push(C1);
	U.Push(C2);

	EXPECT_EQ(U.tableOut()[1].dataOut() == P2, true);
}

TEST(unorderedTable, can_find_true_check) {
	unorderedTable<int, Polinom> U;

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	U.Push(C1);
	U.Push(C2);

	EXPECT_EQ(U.Find(5), 1);
}

TEST(unorderedTable, can_find_false_check) {
	unorderedTable<int, Polinom> U;

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	U.Push(C1);
	U.Push(C2);

	ASSERT_ANY_THROW(U.Find(3));
}

TEST(unorderedTable, can_delete_true_check) {
	unorderedTable<int, Polinom> U;

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	U.Push(C1);
	U.Push(C2);
	U.Delete(5);

	EXPECT_EQ(U.tableOut().back() == C1, true);
}

TEST(unorderedTable, can_delete_false_check) {
	unorderedTable<int, Polinom> U;

	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P1, P2;
	P1.Push(A);
	P1.Push(B);
	P2.Push(B);
	Cell<int, Polinom> C1(2, P1);
	Cell<int, Polinom> C2(5, P2);
	U.Push(C1);

	ASSERT_ANY_THROW(U.Delete(5));
}