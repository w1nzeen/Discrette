#include "Graph.h"

// Реалізація методу empty для класу List
bool List::empty() {
    return first == NULL; // Повертає true, якщо список порожній
}

// Реалізація класу stacks
stacks::stacks() {
    first = nullptr;
    last = nullptr;
}

stacks::~stacks() {
    // Очищаємо всі вузли
    while (!empty()) {
        Item* temp = first;
        first = temp->next;
        delete temp;
    }
}

void stacks::push(int data) {
    Item* temp = new Item;
    temp->data = data;
    temp->next = first;
    temp->previous = nullptr;
    first = temp;
}

int stacks::pop() {
    if (empty()) {
        throw runtime_error("Stack is empty"); // Виняток для порожнього стека
    }
    Item* temp = first;
    first = temp->next;
    int p = temp->data;
    delete temp;
    return p;
}

// Реалізація класу queuee
queuee::queuee() {
    first = nullptr;
    last = nullptr;
}

queuee::~queuee() {
    // Очищаємо всі вузли
    while (!empty()) {
        Item* temp = first;
        first = temp->next;
        delete temp;
    }
}

void queuee::enqueue(int data) {
    Item* temp = new Item;
    temp->data = data;
    temp->next = nullptr;
    temp->previous = nullptr;
    if (empty()) {
        first = temp;
    } else {
        last->next = temp;
    }
    last = temp;
}

int queuee::dequeue() {
    if (empty()) {
        throw runtime_error("Queue is empty"); // Виняток для порожньої черги
    }
    Item* temp = first;
    first = temp->next;
    if (!first) last = nullptr;
    int p = temp->data;
    delete temp;
    return p;
}

// Реалізація класу Graph
Graph::Graph() {
    numOfVertex = 0;
    visited = nullptr;
    pos = nullptr;
    from = nullptr;
    to = nullptr;
    dfsnum = 0;
    _BFS = 0;
    counter = 0;
}

Graph::~Graph() {
    // Звільняємо пам’ять
    delete[] visited;
    delete[] pos;
    delete[] from;
    delete[] to;
}

void Graph::AddEdge(vector<vector<int>> AdjMatrix, int vertex) {
    numOfVertex = vertex;
    graph.clear();
    // Копіюємо матрицю суміжності
    for (int i = 0; i < vertex; ++i) {
        graph.push_back(AdjMatrix[i]);
    }
    // Виділяємо та ініціалізуємо масиви
    delete[] visited;
    delete[] pos;
    delete[] from;
    delete[] to;
    visited = new bool[numOfVertex]();
    pos = new int[numOfVertex]();
    from = new int[numOfVertex]();
    to = new int[numOfVertex]();
}

void Graph::DFS(int start) {
    // Скидаємо змінні
    dfsnum = 0;
    counter = 0;
    for (int i = 0; i < numOfVertex; ++i) {
        visited[i] = false;
        pos[i] = 0;
        from[i] = 0;
        to[i] = 0;
    }
    stacks s;
    visited[start] = true;
    pos[start] = ++dfsnum;
    cout << "V" << start + 1 << "\t" << pos[start] << "\n";
    s.push(start);
    while (!s.empty()) {
        int x = s.pop();
        // Досліджуємо всіх сусідів
        for (int j = 0; j < numOfVertex; ++j) {
            if (graph[x][j] == 1 && !visited[j]) {
                visited[j] = true;
                pos[j] = ++dfsnum;
                cout << "V" << j + 1 << "\t" << pos[j] << "\n";
                from[counter] = x;
                to[counter] = j;
                counter++;
                s.push(j);
            }
        }
    }
    // Виводимо ребра
    cout << "\nPairs of vertices\n";
    for (int i = 0; i < counter; ++i) {
        cout << "V" << from[i] + 1 << " -> V" << to[i] + 1 << "\n";
    }
}

void Graph::rDFS(int start) {
    // Скидаємо змінні
    dfsnum = 0;
    counter = 0;
    for (int i = 0; i < numOfVertex; ++i) {
        visited[i] = false;
        pos[i] = 0;
        from[i] = 0;
        to[i] = 0;
    }
    rDFSHelper(start);
    // Виводимо ребра
    cout << "\nPairs of vertices\n";
    for (int i = 0; i < counter; ++i) {
        cout << "V" << from[i] + 1 << " -> V" << to[i] + 1 << "\n";
    }
}

void Graph::rDFSHelper(int start) {
    visited[start] = true;
    pos[start] = ++dfsnum;
    cout << "V" << start + 1 << "\t" << pos[start] << "\n";
    for (int j = 0; j < numOfVertex; ++j) {
        if (graph[start][j] == 1 && !visited[j]) {
            from[counter] = start;
            to[counter] = j;
            counter++;
            rDFSHelper(j);
        }
    }
}

void Graph::BFS(int start) {
    // Скидаємо змінні
    _BFS = 0;
    counter = 0;
    for (int i = 0; i < numOfVertex; ++i) {
        visited[i] = false;
        pos[i] = 0;
        from[i] = 0;
        to[i] = 0;
    }
    queue<int> q;
    visited[start] = true;
    pos[start] = ++_BFS;
    cout << "V" << start + 1 << "\t" << pos[start] << "\n";
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int j = 0; j < numOfVertex; ++j) {
            if (graph[x][j] == 1 && !visited[j]) {
                visited[j] = true;
                pos[j] = ++_BFS;
                cout << "V" << j + 1 << "\t" << pos[j] << "\n";
                from[counter] = x;
                to[counter] = j;
                counter++;
                q.push(j);
            }
        }
    }
    // Виводимо ребра
    cout << "\nPairs of vertices\n";
    for (int i = 0; i < counter; ++i) {
        cout << "V" << from[i] + 1 << " -> V" << to[i] + 1 << "\n";
    }
}