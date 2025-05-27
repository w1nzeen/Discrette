#include "Graph.h"

bool List::empty() {
    return first == NULL;
}

void queuee::enqueue(int data) {
    Item* temp = new Item;
    temp->data = data;
    temp->next = NULL;
    if (empty())
        first = temp;
    else
        last->next = temp;
    last = temp;
}

int queuee::dequeue() {
    if (empty()) return NULL;
    Item* temp = first;
    first = temp->next;
    int p = temp->data;
    delete temp;
    return p;
}

void Graph::AddEdge(vector<vector<int>> AdjMatrix, int vertex) {
    numOfVertex = vertex;

    graph.clear();
    graph = AdjMatrix;

    // виділяємо пам’ять один раз
    visited = new bool[numOfVertex];
    pos = new int[numOfVertex];
    from = new int[numOfVertex];
    to = new int[numOfVertex];
}

void Graph::DFS(int start) {
    dfsnum = 0;
    counter = 0;

    delete[] visited;
    delete[] pos;
    delete[] from;
    delete[] to;

    visited = new bool[numOfVertex];
    pos = new int[numOfVertex];
    from = new int[numOfVertex];
    to = new int[numOfVertex];

    for (int i = 0; i < numOfVertex; ++i) visited[i] = false;

    stack<int> s;
    visited[start] = true;
    pos[start] = ++dfsnum;
    cout << "V" << start + 1 << "\t" << pos[start] << "\n";
    s.push(start);

    while (!s.empty()) {
        int x = s.top();
        bool found = false;

        for (int j = 0; j < numOfVertex; ++j) {
            if (graph[x][j] == 1 && !visited[j]) {
                visited[j] = true;
                pos[j] = ++dfsnum;
                cout << "V" << j + 1 << "\t" << pos[j] << "\n";
                s.push(j);
                from[counter] = x;
                to[counter] = j;
                counter++;
                found = true;
                break;
            }
        }

        if (!found) s.pop();
    }

    cout << "\nШлях\n";
    for (int i = 0; i < counter; ++i)
        cout << "V" << from[i] + 1 << " -> V" << to[i] + 1 << "\n";

    counter = 0;
}

void Graph::start_rDFS(int start) {
    dfsnum = 0;
    counter = 0;

    delete[] visited;
    delete[] pos;
    delete[] from;
    delete[] to;

    visited = new bool[numOfVertex];
    pos = new int[numOfVertex];
    from = new int[numOfVertex];
    to = new int[numOfVertex];

    for (int i = 0; i < numOfVertex; ++i)
        visited[i] = false;

    cout << "(V)\trDFS\n";
    rDFS(start);

    cout << "\nШлях\n";
    for (int i = 0; i < counter; ++i)
        cout << "V" << from[i] + 1 << " -> V" << to[i] + 1 << "\n";

    counter = 0;
}

void Graph::rDFS(int start) {
    visited[start] = true;
    pos[start] = ++dfsnum;
    cout << "V" << start + 1 << "\t" << pos[start] << "\n";

    for (int i = 0; i < numOfVertex; ++i) {
        if (graph[start][i] == 1 && !visited[i]) {
            from[counter] = start;
            to[counter] = i;
            counter++;
            rDFS(i);
        }
    }
}

void Graph::BFS(int start) {
    _BFS = 1;
    counter = 0;

    delete[] visited;
    delete[] pos;
    delete[] from;
    delete[] to;

    visited = new bool[numOfVertex];
    pos = new int[numOfVertex];
    from = new int[numOfVertex];
    to = new int[numOfVertex];

    for (int i = 0; i < numOfVertex; ++i)
        visited[i] = false;

    queue<int> q;
    visited[start] = true;
    pos[start] = _BFS;
    cout << "V" << start + 1 << "\t" << pos[start] << "\n";
    q.push(start);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int j = 0; j < numOfVertex; ++j) {
            if (graph[x][j] == 1 && !visited[j]) {
                from[counter] = x;
                to[counter] = j;
                q.push(j);
                visited[j] = true;
                pos[j] = ++_BFS;
                cout << "V" << j + 1 << "\t" << pos[j] << "\n";
                counter++;
            }
        }
    }

    cout << "\nШлях\n";
    for (int i = 0; i < counter; ++i)
        cout << "V" << from[i] + 1 << " -> V" << to[i] + 1 << "\n";

    counter = 0;
}
