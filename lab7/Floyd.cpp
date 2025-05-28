#include "Floyd.h"
#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix, const string& label) {
    cout << "\n" << label << ":\n";
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INF)
                cout << setw(6) << "INF";
            else
                cout << setw(6) << matrix[i][j];
        }
        cout << "\n";
    }
}

void printPathMatrix(const vector<vector<int>>& path, int i, int j) {
    if (i == j) {
        cout << i << " ";
    } else if (path[i][j] == -1) {
        cout << "No path";
    } else {
        printPathMatrix(path, i, path[i][j]);
        cout << j << " ";
    }
}

void floydWarshall(const vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<vector<int>> dist = adjMatrix;
    vector<vector<int>> path(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && adjMatrix[i][j] != INF)
                path[i][j] = i;

    printMatrix(dist, "D^(0)");
    printMatrix(path, "P^(0)");

    for (int k = 0; k < n; ++k) {
        vector<vector<int>> newDist = dist;
        vector<vector<int>> newPath = path;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    newDist[i][j] = dist[i][k] + dist[k][j];
                    newPath[i][j] = path[k][j];
                }
            }
        }

        dist = newDist;
        path = newPath;

        cout << "\n=== Step k = " << k + 1 << " ===";
        printMatrix(dist, "D^(" + to_string(k + 1) + ")");
        printMatrix(path, "P^(" + to_string(k + 1) + ")");
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            cout << "Graph contains a negative-weight cycle at vertex " << i << ".\n";
            return;
        }
    }

    int u, v;
    cout << "\nEnter start and end vertex (0.." << n - 1 << "): ";
    cin >> u >> v;

    if (dist[u][v] == INF) {
        cout << "No path from " << u << " to " << v << ".\n";
    } else {
        cout << "Shortest path from " << u << " to " << v << " (distance = " << dist[u][v] << "): ";
        printPathMatrix(path, u, v);
        cout << "\n";
    }
}
