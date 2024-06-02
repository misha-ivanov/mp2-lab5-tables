#include <gtest.h>
#include "polinom.h"
#include "list.h"
#include "cell.h"
#include "orderedTable.h"

TEST(orderedTable, can_create) {
	orderedTable<int, Polinom> Or;
	EXPECT_EQ(Or.tableOut().size(), 0);
}

TEST(orderedTable, can_push) {
	orderedTable<int, int> Or;
	
	Cell<int, int> C1(1, 10), C2(5, 10), C3(2, 10), C4(8, 10), C5(10, 10), C6(3, 10);
	
	Or.Push(C1);
	Or.Push(C2);
	Or.Push(C3);
	Or.Push(C4);
	Or.Push(C5);
	Or.Push(C6);
	
	EXPECT_EQ(Or.tableOut()[5].keyOut(), 10);
}

TEST(orderedTable, can_find_true_check) {
	orderedTable<int, int> Or;

	Cell<int, int> C1(1, 10), C2(5, 10), C3(2, 10), C4(8, 10), C5(10, 10), C6(3, 10);

	Or.Push(C1);
	Or.Push(C2);
	Or.Push(C3);
	Or.Push(C4);
	Or.Push(C5);
	Or.Push(C6);

	EXPECT_EQ(Or.Find(8), 4);
}

TEST(orderedTable, can_find_false_check) {
	orderedTable<int, int> Or;

	Cell<int, int> C1(1, 10), C2(5, 10), C3(2, 10), C4(8, 10), C5(10, 10), C6(3, 10);

	Or.Push(C1);
	Or.Push(C2);
	Or.Push(C3);
	Or.Push(C4);
	Or.Push(C5);
	Or.Push(C6);

	ASSERT_ANY_THROW(Or.Find(9));
}

TEST(orderedTable, can_delete_true_check) {
	orderedTable<int, int> Or;

	Cell<int, int> C1(1, 10), C2(5, 10), C3(2, 10), C4(8, 10), C5(10, 10), C6(3, 10);

	Or.Push(C1);
	Or.Push(C2);
	Or.Push(C3);
	Or.Push(C4);
	Or.Push(C5);
	Or.Push(C6);

	Or.Delete(8);

	EXPECT_EQ(Or.tableOut()[4].keyOut(), 10);
}

TEST(orderedTable, can_delete_false_check) {
	orderedTable<int, int> Or;

	Cell<int, int> C1(1, 10), C2(5, 10), C3(2, 10), C4(8, 10), C5(10, 10), C6(3, 10);

	Or.Push(C1);
	Or.Push(C2);
	Or.Push(C3);
	Or.Push(C4);
	Or.Push(C5);
	Or.Push(C6);

	ASSERT_ANY_THROW(Or.Delete(9));
}