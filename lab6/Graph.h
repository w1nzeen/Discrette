#ifndef LAB6DISC_GRAPH_H
#define LAB6DISC_GRAPH_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
#include <windows.h>
#pragma execution_character_set("utf-8")

using namespace std;

struct Item
{
    int data;
    Item* next;
    Item* previous;
};

class List {
public:
    Item* first, * last;
    bool empty();
};

class stacks : public List
{
public:
    stacks() { first = NULL; }
    ~stacks() {}
    void push(int data) {
        Item* temp = new Item;
        temp->data = data;
        temp->next = first;
        first = temp;
    }
    int pop() {
        if (empty())
        {
            return NULL;
        }
        else
        {
            Item* temp = first;
            first = temp->next;
            int p = temp->data;
            delete temp;
            return p;
        }
    }
};

class queuee : public List
{
public:
    queuee() { last = NULL; }
    ~queuee(){}
    void enqueue(int data);
    int dequeue();
};

class Graph
{
    vector<vector<int>> graph;

    int dfsnum = 0;
    int _BFS;
    int counter = 0;
    int numOfVertex;
    bool* visited = nullptr;
    int* pos = nullptr;
    int* from = nullptr;
    int* to = nullptr;
public:
    Graph() {}
    ~Graph() {
        delete[] visited;
        delete[] pos;
        delete[] from;
        delete[] to;
    }
    void AddEdge(vector<vector<int>> AdjMatrix, int vertex);
    void DFS(int start);
    void rDFS(int start);
    void start_rDFS(int start); // <== додано
    void BFS(int start);
};

#endif //LAB6DISC_GRAPH_H
