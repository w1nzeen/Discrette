// Floyd.h
#ifndef FLOYD_H
#define FLOYD_H

#include <vector>
#include "Constants.h"

void floydWarshall(const std::vector<std::vector<int>>& adjMatrix);
void printPathMatrix(const std::vector<std::vector<int>>& path, int i, int j);

#endif // FLOYD_H