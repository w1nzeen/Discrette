#pragma once
#include <iostream>
typedef int datatype; // задання типу даних

struct Item {
    datatype data; // інформаційне поле
    Item* next; // поле-вказівник на наступний компонент
    Item* prev; // поле-вказівник на попередній компонент
    Item* search(Item* first, datatype key);
};
//void pop(Item*& head);
void show(Item* head);
void enqueue(Item*& end, Item*& front, datatype data);
void dequeue(Item*& front);
void add_begin(Item*& first, Item*& last, datatype data);
void add_end(Item*& first, Item*& last, datatype data);
void del_begin(Item*& first, Item*& last);
void del_end(Item*& first, Item*& last);
void add_mid(Item*& first, Item*& last, datatype key, datatype data);
void del_mid(Item*& first, Item*& last, datatype key);

