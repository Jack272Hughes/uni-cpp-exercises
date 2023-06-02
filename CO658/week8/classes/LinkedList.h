#pragma once
#include <iostream>

using namespace std;

template <class T>
class LinkedList {
private:
	T * Get(int i) {
		int count = 0;
		T *current = first;
		while (current != 0) {
			if (count == i) return current;
			count++;
			current = current->next;
		}
		return 0;
	}
	int items;
public:
	T *first;
	LinkedList() {
		first = 0;
		items = 0;
	}
	~LinkedList() {
		while (first != 0) {
			delete Delete();
			cout << "Deleted" << endl;
		}
	}
	inline bool IsEmpty() {
		return (first == 0);
	}
	inline void Insert(T *newLink) {
		newLink->next = first;
		first = newLink;
		items++;
	}
	void Display()const {
		T *current = first;
		while (current != 0) {
			current->Display();
			current = current->next;
		}
	}
	T *Find(T * key)const {
		T *current = first;
		while (*current != *key) {
			if (current->next == 0)
				return 0;
			else
				current = current->next;
		}
		return current;
	}
	T *Delete() {
		T *temp = first;
		first = first->next;
		items--;
		return temp;
	}
	T *Delete(const int key);
	int Count() {
		return items;
	}
	T * operator[](const int &i) {
		return Get(i);
	}
};
