#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Node {
	T data;
	Node<T>* next;
public:
	Node() {
		next = nullptr;
	}

	Node(T _data) {
		data = _data;
		next = nullptr;
	}

	Node(T _data, Node<T>* _next) {
		data = _data;
		next = _next;
	}

	bool operator ==(const Node& n) {
		if (data == n.data)
			return true;
		return false;
	}

	bool operator !=(const Node& n) {
		return !(this == n);
	}
};

template <class T>
class List {
	Node<T>* head;
public:
	List() {
		head = new Node<T>;
		head->next = nullptr;
	}

	List(const List<T>& _l) {
		Node<T>* tmp_head = new Node<T>;
		head = tmp_head;
		Node<T>* tmp_p_head = _l.head;
		while (tmp_p_head->next != nullptr) {
			tmp_head->next = new Node<T>(tmp_p_head->next->data);
			tmp_head = tmp_head->next;
			tmp_p_head = tmp_p_head->next;
		}
	}

	Node<T>* HeadOut() const { return head; };

	bool IsEmpty() {
		return (head -> next == nullptr);
	}

	void Push(T elem) {
		if (IsEmpty())
			head->next = new Node<T>(elem, nullptr);
		else
		{
			Node<T>* tmp = head -> next;
			while (tmp->next != nullptr)
				tmp = tmp->next;
			tmp->next = new Node<T>(elem, nullptr);
		}
		Sort();
	}



	void Delete(Node<T>* ptr) {
		Node<T>* tmp = head;
		while ((tmp->next != ptr) && (tmp->next != nullptr)){
			tmp = tmp->next;
		}
		if ((tmp->next != nullptr) && (tmp->next == ptr))
			tmp->next = tmp->next->next;
		else
			throw "there_are_no_elements_to_delete";
	}

	void Sort() {
		Node<T>* tmp_head = head;
		Node<T>* tmp_swap = head; // empty node for swapping
		Node<T>* tmp_prev = head; // storage for pointer to tmp_head
		Node<T>* tmp = head; // next node after tmp_head
		int len = 0, f = 1, j, i = 0;

		while (tmp_head->next != nullptr) {
			len++;
			tmp_head = tmp_head->next;
		}
		while (i < len && f == 1) {
			tmp_prev = head;
			tmp_head = head->next;
			tmp = tmp_head->next;
			j = len - i - 1;
			while (j > 0) {
				if (tmp_head->data < tmp->data) { // swapping
					tmp_swap = tmp->next;
					tmp->next = tmp_head;
					tmp_prev->next = tmp;
					tmp_head->next = tmp_swap;
					f = 1;
					tmp_swap = tmp;
					tmp = tmp_head;
					tmp_head = tmp_swap;

				}
				tmp = tmp->next;
				tmp_head = tmp_head->next;
				tmp_prev = tmp_prev->next;
				j--;
			}
			i++;
		}
	}

	bool operator ==(List<T> l) {
		Node<T>* tmp = head;
		Node<T>* tmp_l = l.head;
		while (tmp->next != nullptr) {
			if ((tmp_l->next == nullptr)||(tmp->data != tmp_l->data))
				return false;
			tmp = tmp->next;
			tmp_l = tmp_l->next;
		}
		if ((tmp_l->next != nullptr) || (tmp->data != tmp_l->data))
			return false;
		return true;
	}

	bool operator >(List<T>& l) {
		Node<T>* tmp = head;
		Node<T>* tmp_l = l.head;
		while (tmp->next != nullptr) {
			if ((tmp_l->next == nullptr) || (tmp->data > tmp_l->data))
				return true;
			tmp = tmp->next;
			tmp_l = tmp_l->next;
		}
		if ((tmp_l->next != nullptr) || !(tmp->data > tmp_l->data))
			return false;
		return true;
	}

	bool operator <(List<T>& l) {
		Node<T>* tmp = head;
		Node<T>* tmp_l = l.head;
		while (tmp->next != nullptr) {
			if ((tmp_l->next == nullptr) || (tmp->data > tmp_l->data))
				return false;
			tmp = tmp->next;
			tmp_l = tmp_l->next;
		}
		if ((tmp_l->next != nullptr) || (tmp->data < tmp_l->data))
			return true;
		return false;
	}
};