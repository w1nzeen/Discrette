#include "Graph.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    Graph g;
    int vertex, choice, start, b;

    // Запитуємо розмір матриці з перевіркою
    cout << "Введіть розмір квадратичної матриці: ";
    cin >> vertex;
    if (vertex <= 0) {
        cout << "Некоректний розмір матриці\n";
        return 1;
    }

    // Вводимо матрицю суміжності
    cout << "Введіть матрицю:\n";
    vector<vector<int>> AdjMatrix(vertex, vector<int>(vertex));
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            cin >> AdjMatrix[i][j];
            // Перевірка: значення має бути 0 або 1
            if (AdjMatrix[i][j] != 0 && AdjMatrix[i][j] != 1) {
                cout << "Матриця має містити лише 0 або 1\n";
                return 1;
            }
        }
    }

    // Запитуємо початкову вершину з перевіркою
    cout << "Введіть початковий номер: ";
    cin >> start;
    if (start < 1 || start > vertex) {
        cout << "Некоректний номер вершини\n";
        return 1;
    }

    g.AddEdge(AdjMatrix, vertex);

    // Меню вибору методу
    while (true) {
        cout << "Виберіть метод:\n";
        cout << "1.Пошук вглиб\n";
        cout << "2.Рекурсивний пошук вглиб\n";
        cout << "3.Пошук вшир\n";
        cout << "4. Вихід\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nВектор\tDFS\n";
            g.DFS(start - 1);
            break;
            case 2:
                cout << "\nВектор\trDFS\n";
            g.rDFS(start - 1);
            break;
            case 3:
                cout << "\nВектор\tBFS\n";
            g.BFS(start - 1);
            break;
            case 4:
                cout << "You escaped\n";
            return 0;
            default:
                cout << "Невірний вибір\n";
        }
    }
}