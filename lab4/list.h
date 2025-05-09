#pragma once
#include <iostream>
typedef int datatype;

struct Item {
    datatype data;
    Item* next;
    Item* prev;
    Item* search(Item* first, datatype key);
};
void push(Item*& head, const datatype data); void pop(Item*& head);void show(Item* head);
void enqueue(Item*& end, Item*& front, datatype data);
void dequeue(Item*& front);
void add_begin(Item*& first, Item*& last, datatype data);
void add_end(Item*& first, Item*& last, datatype data);
void del_begin(Item*& first, Item*& last);
void del_end(Item*& first, Item*& last);
void add_mid(Item*& first, Item*& last, datatype key, datatype data);
void del_mid(Item*& first, Item*& last, datatype key);

