#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdexcept>
#include <Windows.h>
#pragma execution_character_set("utf-8")

using namespace std;

// Структура для елементів зв’язного списку (використовується для стека та черги)
struct Item {
    int data;          // Значення вершини
    Item* next;        // Вказівник на наступний елемент
    Item* previous;    // Не використовується
};

// Базовий клас для зв’язного списку
class List {
public:
    Item* first, *last; // Вказівники на початок і кінець
    bool empty();       // Перевіряє, чи список порожній
};

// Клас стека
class stacks : public List {
public:
    stacks();           // Конструктор
    ~stacks();          // Деструктор для очищення пам’яті
    void push(int data); // Додає елемент на вершину
    int pop();          // Видаляє та повертає верхній елемент
};

// Клас черги
class queuee : public List {
public:
    queuee();           // Конструктор
    ~queuee();          // Деструктор для очищення пам’яті
    void enqueue(int data); // Додає елемент у кінець
    int dequeue();      // Видаляє та повертає перший елемент
};

// Клас для роботи з графом
class Graph {
    vector<vector<int>> graph; // Матриця суміжності
    int dfsnum;               // Лічильник для номерів DFS
    int _BFS;                 // Лічильник для номерів BFS
    int counter;              // Лічильник ребер
    int numOfVertex;          // Кількість вершин
    bool* visited;            // Масив відвіданих вершин
    int* pos;                 // Масив номерів обходу
    int* from;                // Початкові вершини ребер
    int* to;                  // Кінцеві вершини ребер
public:
    Graph();                  // Конструктор
    ~Graph();                 // Деструктор
    void AddEdge(vector<vector<int>> AdjMatrix, int vertex); // Ініціалізує граф
    void DFS(int start);      // Ітеративний пошук у глибину
    void rDFS(int start);     // Рекурсивний пошук у глибину
    void BFS(int start);      // Пошук у ширину
private:
    void rDFSHelper(int start); // Допоміжна функція для rDFS
};