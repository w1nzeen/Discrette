#include "Graph.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    Graph g;
    int vertex, choice, start, b;

    cout << "Розмір матриці суміжності (квадратичної) : ";
    cin >> vertex;

    cout << "Введіть матрицю:\n";
    vector<vector<int>> AdjMatrix(vertex, vector<int>(vertex));
    for (int i = 0; i < vertex; ++i)
        for (int j = 0; j < vertex; ++j)
            cin >> AdjMatrix[i][j];

    g.AddEdge(AdjMatrix, vertex);

    cout << "Введіть початковий номер: ";
    cin >> start;

    while (true) {
        cout << "Виберіть метод:\n";
        cout << "1       |Пошук вглиб|\n";
        cout << "2  |Рекурсивний пошук вглиб|\n";
        cout << "3       |Пошук вшир|\n";
        cout << "4         |Вихід|\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n(V)\tDFS\n";
            g.DFS(start - 1);
            break;
            case 2:
                g.start_rDFS(start - 1);
            break;
            case 3:
                cout << "\n(V)\tBFS\n";
            g.BFS(start - 1);
            break;
            case 4:
                cout << "Кінець\n";
            return 0;
            default:
                break;
        }
    }
}
