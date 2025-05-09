#include "list.h"
#include <iostream>
using namespace std;

void push(Item*& head, const datatype data) {
	Item* temp = new Item;
	temp-> data = data;
	temp->next = head;
	head = temp;
}

void pop(Item*& head) {
	if (head == NULL) {
		cout << "Stack is empty\n";
			return;
	}
	else {
		Item* temp = head;
		head = temp->next;
		delete temp;
	}
}

void show(Item* head) {
	Item* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void enqueue(Item*& end, Item*& front, datatype data) {
	Item* temp = new Item;
	Item* head = NULL;
	temp->data = data;
	temp->next = NULL;
	if (front == NULL) {
		front = temp;
	}
	else {
		end->next = temp;
	}
	end = temp;
}

void dequeue(Item*& front) {
	if (front == NULL) {
		cout << "Queue is empty\n";
		return;
	}
	else {
		Item* temp = front;
		front = front->next;
		delete temp;
	}
}

void add_begin(Item*& first, Item*& last, datatype data) {
	Item* temp = new Item;
	temp->data = data;
	temp->next = first;
	temp->prev = NULL;
	if (first != NULL) {
		first->prev = temp;
	}
	else {
		last = temp;
	}
	first = temp;
}

void add_end(Item*& first, Item*& last, datatype data) {
	Item* temp = new Item;
	temp->data = data;
	temp->next = NULL;
	temp->prev = last;
	if (last != NULL) {
		last->next = temp;
	}
	else { //
		first = temp;
	}
	last = temp;
}

void del_begin(Item*& first, Item*& last) {
	if (first == NULL) {
		cout << "List is empty\n";
		return;
	}
	Item* temp = first;
	first = temp->next;

	if (first != NULL) {
		first->prev = NULL;
	}
	else {
		last = NULL;
	}
	delete temp;

}

void del_end(Item*& first, Item*& last) {
	if (last == NULL) {
		cout << "List is empty";
		return;
	}
	Item* temp = last;
	last = temp->prev;

	if (last != NULL) {
		last->next = NULL;
	}
	else {
		first = NULL;
	}
	delete temp;
}

Item* search(Item* first, datatype key) {
	Item* temp = first;
	while (temp != NULL) {
		if (temp->data == key) {
			return temp;
		}
		else {
			temp = temp->next;
		}
	}
	return temp;
}

void add_mid(Item*& first, Item*& last, datatype key, datatype data) {
	if (search(first, key) == NULL) {
		cout << "Item not found\n";
			return;
	}
	else {
		Item* pkey = search(first, key);
		if (pkey->next == NULL) {
			add_end(first, last, data);
		}
		else {
			Item* temp = new Item;
			temp->data = data;
			temp->next = pkey->next;
			temp->prev = pkey;
			pkey->next = temp;
			(temp->next)->prev = temp;
		}
	}
}

void del_mid(Item*& first, Item*& last, datatype key) {
	if (search(first, key) == NULL) {
		cout << "Item not found\n";
		return;
	}
	else {
		Item* pkey = search(first, key);
		if (pkey->prev == NULL) {
			del_begin(first, last);
		}
		else if (pkey->next == NULL) {
			del_end(first, last);
		}
		else {
			(pkey->prev)->next = pkey->next;
			(pkey->next)->prev = pkey->prev;
			delete pkey;
		}
	}
}