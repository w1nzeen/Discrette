#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include "Constants.h"

void dijkstraAllPaths(const std::vector<std::vector<int>>& adjMatrix, int startVertex);
void dijkstraSinglePath(const std::vector<std::vector<int>>& adjMatrix, int startVertex, int endVertex);

#endif // DIJKSTRA_H

