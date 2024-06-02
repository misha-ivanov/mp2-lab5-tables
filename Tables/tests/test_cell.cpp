#include <gtest.h>
#include "polinom.h"
#include "list.h"
#include "cell.h"

TEST(cell, can_initialize_key) {
	Cell<int, int> A(2, 4);
	EXPECT_EQ(A.key, 2);
}

TEST(cell, can_initialize_data) {
	Cell<int, int> A(2, 4);
	EXPECT_EQ(A.data, 4);
}

TEST(cell, can_initialize_data_polinom_true_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Cell<int, Polinom> C(2, P);
	EXPECT_EQ(C.data == P, true);
}

TEST(cell, can_initialize_data_polinom_false_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Polinom _P;
	_P.Push(A);
	Cell<int, Polinom> C(2, P);
	EXPECT_EQ(C.data == _P, false);
}

TEST(cell, can_copy_data_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Cell<int, Polinom> C(2, P);
	Cell<int, Polinom> _C(C);
	EXPECT_EQ(_C.data == C.data, true);
}

TEST(cell, can_copy_key_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Cell<int, Polinom> C(2, P);
	Cell<int, Polinom> _C(C);
	EXPECT_EQ(_C.key == C.key, true);
}

TEST(cell, can_equate_data_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Cell<int, Polinom> C(2, P);
	Cell<int, Polinom> _C = C;
	EXPECT_EQ(_C.data == C.data, true);
}

TEST(cell, can_equate_key_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Cell<int, Polinom> C(2, P);
	Cell<int, Polinom> _C = C;
	EXPECT_EQ(_C.key == C.key, true);
}

TEST(cell, can_compare_true_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Cell<int, Polinom> C(2, P);
	Cell<int, Polinom> _C(2, P);
	EXPECT_EQ(_C == C, true);
}

TEST(cell, can_compare_false_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	Cell<int, Polinom> C(2, P);
	P.Push(B);
	Cell<int, Polinom> _C(2, P);
	EXPECT_EQ(_C == C, false);
}

TEST(cell, can_compare_with_not_true_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	Cell<int, Polinom> C(2, P);
	P.Push(B);
	Cell<int, Polinom> _C(2, P);
	EXPECT_EQ(_C != C, true);
}

TEST(cell, can_compare_with_not_false_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	P.Push(B);
	Cell<int, Polinom> C(2, P);
	Cell<int, Polinom> _C(2, P);
	EXPECT_EQ(_C != C, false);
}

TEST(cell, can_compare_bigger_true_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	Cell<int, Polinom> C(2, P);
	P.Push(B);
	Cell<int, Polinom> _C(2, P);
	EXPECT_EQ(_C > C, true);
}

TEST(cell, can_compare_bigger_false_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	Cell<int, Polinom> C(2, P);
	P.Push(B);
	Cell<int, Polinom> _C(2, P);
	EXPECT_EQ(C > _C, false);
}

TEST(cell, can_compare_less_true_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	Cell<int, Polinom> C(2, P);
	P.Push(B);
	Cell<int, Polinom> _C(2, P);
	EXPECT_EQ(C < _C, true);
}

TEST(cell, can_compare_less_false_check) {
	Monom A(1, 101);
	Monom B(3, 234);
	Polinom P;
	P.Push(A);
	Cell<int, Polinom> C(2, P);
	P.Push(B);
	Cell<int, Polinom> _C(2, P);
	EXPECT_EQ(_C < C, false);
}
