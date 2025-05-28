#include "Dijkstra.h"
#include <iostream>
using namespace std;

void printPath(const vector<int>& parent, int v) {
    if (v == -1) return;
    printPath(parent, parent[v]);
    cout << v << " ";
}

void dijkstra(const vector<vector<int>>& adjMatrix, int startVertex, vector<int>& dist, vector<int>& parent) {
    int N = adjMatrix.size();
    vector<bool> visited(N, false);
    dist.assign(N, INF);
    parent.assign(N, -1);
    dist[startVertex] = 0;

    for (int count = 0; count < N - 1; ++count) {
        int minDist = INF, u = -1;
        for (int v = 0; v < N; ++v)
            if (!visited[v] && dist[v] < minDist)
                minDist = dist[v], u = v;

        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < N; ++v) {
            int weight = adjMatrix[u][v];
            if (!visited[v] && weight != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
}

void dijkstraAllPaths(const vector<vector<int>>& adjMatrix, int startVertex) {
    vector<int> dist, parent;
    dijkstra(adjMatrix, startVertex, dist, parent);

    cout << "\nShortest distances from vertex " << startVertex << ":\n";
    for (int i = 0; i < adjMatrix.size(); ++i) {
        if (dist[i] == INF)
            cout << "Vertex " << i << ": No path\n";
        else {
            cout << "Vertex " << i << ": Distance = " << dist[i] << ", Path = ";
            printPath(parent, i);
            cout << "\n";
        }
    }
}

void dijkstraSinglePath(const vector<vector<int>>& adjMatrix, int startVertex, int endVertex) {
    vector<int> dist, parent;
    dijkstra(adjMatrix, startVertex, dist, parent);

    if (dist[endVertex] == INF) {
        cout << "No path from " << startVertex << " to " << endVertex << "\n";
    } else {
        cout << "Shortest distance: " << dist[endVertex] << "\nPath: ";
        printPath(parent, endVertex);
        cout << "\n";
    }
}