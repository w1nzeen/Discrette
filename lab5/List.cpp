#include "list.h"
#include <iostream>
using namespace std;

void push(Item*& head, const datatype data) {
	Item* temp = new Item; // динамічна пам'ять для нового елементу
	temp->data = data; // заповнення поля нового елемента
	temp->next = head; // зв'язання нового елемента з вершиною стеку
	head = temp; // нова вершина стеку
}

void pop(Item*& head) {
if (head == NULL) { // перевірка чи не є стек порожнім
		cout << "Stack is empty\n";
		return;
	}
	else {
		Item* temp = head; // копія вказвіника на вершину стеку
		head = temp->next; // перемістити вказівник вершини на некст елемент
		delete temp; // звільнити пам'ять
	}
}

void show(Item* head) {
	Item* temp = head; // копія вказвіника на вершину стеку
	while (temp != NULL) { // переведення тимчасового вказівника на некст елемент стеку
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void enqueue(Item*& end, Item*& front, datatype data) {
	Item* temp = new Item; // динамічна пам'ять для нового елементу
	Item* head = NULL; // копія вказвіника на вершину стеку
	temp->data = data; // заповнення поля нового елемента
	temp->next = NULL; // новий елемент останнім у чергу
	if (front == NULL) { // якщо черга порожня, то новий елемент на вершину
		front = temp;
	}
	else {
		end->next = temp; // кінець- новостворений елемент
	}
	end = temp;
}

void dequeue(Item*& front) { // аналогічне до pop тільки head = front
	if (front == NULL) { // поле нового елемента
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
	Item* temp = new Item; // динамічна пам'ять для нового елементу
	temp->data = data; // поле нового елемента
	temp->next = first; // новий елемент з початком нового списку і наступним
	temp->prev = NULL; // вказівник нового елемента на попередній як NULL
	if (first != NULL) { // якшо список не порожній, то 1 зв'язати елемент з новим і попереднім
		first->prev = temp;
	}
	else {
		last = temp; // порожній, тоді вказівник кінця на новий елемент
	}
	first = temp; // новий вказівник початку списку
}

void add_end(Item*& first, Item*& last, datatype data) {
	Item* temp = new Item; // Виділити  динамічну  пам’ять  для  нового  елемента
	temp->data = data; // Заповнити  інформаційне  поле  нового  елемента
	temp->next = NULL; // Встановити  новий  елемент  останнім  у  списку
	temp->prev = last; // Зв’язати  новостворений  елемент  з  попереднім
	if (last != NULL) { // Якщо список не порожній, то зв’язати його кінець з новоствореним елементом як з наступним
		last->next = temp;
	}
	else { // Якщо список порожній, то встановити вказівник початку списку на новостворений елемент
		first = temp;
	}
	last = temp; // Встановити вказівник кінця списку на новостворений елемент
}

void del_begin(Item*& first, Item*& last) {
	if (first == NULL) { // Перевірити, чи список не є порожній
		cout << "List is empty\n";
		return;
	}
	Item* temp = first; // Створити  копію  вказівника  на  початок  списку
	first = temp->next; // Перемістити вказівник початку списку на наступний елемент

	if (first != NULL) { //Якщо  список  не  порожній, то встановити  вказівник  початку  на  попередній  як  NULL
		first->prev = NULL;
	}
	else {
		last = NULL; // встановити вказівник кінця списку як NULL
	}
	delete temp;

}

void del_end(Item*& first, Item*& last) {
	if (last == NULL) { // Перевірити, чи список не є порожній
		cout << "List is empty";
		return;
	}
	Item* temp = last; // Створити копію вказівника на кінець списку
	last = temp->prev; // Перемістити вказівник кінця списку на попередній елемент

	if (last != NULL) {
		last->next = NULL; // Якщо  список  не  порожній,  то встановити  вказівник  кінця  списку  на  наступний  як  NULL
	}
	else {
		first = NULL; // встановити вказівник початку списку як NULL
	}
	delete temp;
}

Item* search(Item* first, datatype key) {
	Item* temp = first; // Створити тимчасовий вказівник і присвоїти йому значення початку списку
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
		Item* pkey = search(first, key); // пошук елементу у списку за заданим ключем
		if (pkey->next == NULL) { // Якщо знайдений елемент знаходиться в кінці списку, то додавання в кінець списку
			add_end(first, last, data);
		}
		else {
			Item* temp = new Item; // Виділити  динамічну  пам’ять  для  нового  елементу
			temp->data = data; // Заповнити інформаційне поле новоствореного елементу
			temp->next = pkey->next; // Зв’язати новостворений елемент з наступним після знайденого
			temp->prev = pkey; // Зв’язати новостворений елемент зі знайденим як з попереднім
			pkey->next = temp; // Зв’язати знайдений з новоствореним як з наступним
			(temp->next)->prev = temp; // Зв’язати  наступний  після  знайденого  з  новоствореним  як  з попереднім
		}
	}
}

void del_mid(Item*& first, Item*& last, datatype key) {
	if (search(first, key) == NULL) { // Виконати пошук елементу у списку за заданим ключем
		cout << "Item not found\n";
		return;
	}
	else {
		Item* pkey = search(first, key);
		if (pkey->prev == NULL) { // Якщо знайдений елемент знаходиться на початку списку, то видалити з початку списку
			del_begin(first, last);
		}
		else if (pkey->next == NULL) {
			del_end(first, last); // Якщо  знайдений  елемент  знаходиться  в  кінці  списку, то видалити з кінця списку
		}
		else {
			(pkey->prev)->next = pkey->next; // Зв’язати попередній від знайденого з наступним від знайденого
			(pkey->next)->prev = pkey->prev; // Зв’язати наступний від знайденого з попереднім від знайденого
			delete pkey;
		}
	}
}
