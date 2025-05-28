#include "Dijkstra.h"
#include "Floyd.h"
#include <iostream>
using namespace std;

int main() {
    const int N = 7;

    vector<vector<int>> adjMatrix = {
        { 0,   4,   8, INF, INF, INF, INF },
        { 4,   0, INF,   1,  21, INF, INF },
        { 8, INF,   0, INF, INF,   3, INF },
        {INF,  1, INF,   0, INF, INF,  20 },
        {INF, 21, INF, INF,   0, INF,   7 },
        {INF, INF,  3, INF, INF,   0,   9 },
        {INF, INF, INF, 20,   7,   9,   0 }
    };

    int algo;
    cout << "Choose algorithm:\n";
    cout << "1. Dijkstra\n";
    cout << "2. Floyd-Warshall\n";
    cout << "Your choice: ";
    cin >> algo;

    if (algo == 1) {
        int mode;
        cout << "\n--- Dijkstra ---\n";
        cout << "1. Shortest path from one vertex to ALL others\n";
        cout << "2. Shortest path between TWO vertices\n";
        cout << "Choose mode: ";
        cin >> mode;

        if (mode == 1) {
            int start;
            cout << "Enter starting vertex (0 - 6): ";
            cin >> start;
            dijkstraAllPaths(adjMatrix, start);
        } else if (mode == 2) {
            int start, end;
            cout << "Enter start and end vertex (0 - 6): ";
            cin >> start >> end;
            dijkstraSinglePath(adjMatrix, start, end);
        } else {
            cout << "Invalid Dijkstra mode.\n";
        }
    } else if (algo == 2) {
        cout << "\n--- Floyd-Warshall ---\n";
        floydWarshall(adjMatrix);
    } else {
        cout << "Invalid algorithm choice.\n";
    }

    return 0;
}
