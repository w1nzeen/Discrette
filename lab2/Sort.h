#ifndef SORT_H
#define SORT_H

typedef int datatype;

void customSwap(datatype& a, datatype& b);
void sortBubble(datatype* array, int start, int end);
void sortInsertion(datatype* array, int start, int end);
void sortSelection(datatype* array, int start, int end);
void printArray(datatype* array, int size);

#endif //SORT_H