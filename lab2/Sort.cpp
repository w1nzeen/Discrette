#include "Sort.h"

#include <iostream>
#include <ostream>

using namespace std;

void customSwap(datatype& a, datatype& b) {
    datatype temp = a;
    a = b;
    b = temp;
}

void minMaxValue(datatype* array, int start, int end) {
    if (start >= end) return;

    datatype min = array[start], max = array[start];

    for (int i = start; i < end; i++) {
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];
    }

    cout << "Min value:" << min << "\nMax value:" << max << endl;
}

void sortBubble(datatype* array, int start, int end) {
    bool swaped;

    int sizeOfArray = end - start + 1;
    int iterations = 0, swaps = 0;

    if (sizeOfArray <= 1) return;

    for (int i = start; i < end; i++) {
        swaped = false;
        for (int j = start; j < end-(i-start); j++) {
            if (array[j] > array[j+1]) {
                customSwap(array[j], array[j+1]);
                swaps++;
                swaped = true;
                /*printArray(array, sizeOfArray);

                cout << endl;*/
            }
        }
        iterations++;

        if (!swaped) break;
    }

    cout << "Iterations: " << iterations << endl;
    cout << "Total swaps: " << swaps << endl;

    minMaxValue(array, start, end+1);
}

void sortInsertion(datatype* array, int start, int end) {
    int sizeOfArray = end - start + 1;
    int iterations = 0, swaps = 0;

    if (sizeOfArray <= 1) return;

    for (int i = start + 1; i <= end; i++) {
        datatype key = array[i];
        int j = i - 1;

        while (j >= start && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            swaps++;
            /*printArray(array, sizeOfArray);
            cout << endl;*/
        }
        array[j + 1] = key;
        iterations++;
    }
    cout << "Iterations: " << iterations << endl;
    cout << "Total swaps: " << swaps << endl;

    minMaxValue(array, start, end+1);
}

void sortSelection(datatype* array, int start, int end) {
    int sizeOfArray = end - start + 1;
    int iterations = 0, swaps = 0;

    if (sizeOfArray <= 1) return;

    for (int i = start; i < end; i++) {
        int minIndex = i;

        for (int j = i + 1; j <= end; j++) {
            if (array[j] < array[minIndex]) minIndex = j;
        }

        if (minIndex != i) {
            customSwap(array[i], array[minIndex]);
            swaps++;
        }

        iterations++;

        /*printArray(array, sizeOfArray);
        cout << endl;*/
    }
    cout << "Total iterations: " << iterations << endl;
    cout << "Total swaps: " << swaps << endl;

    minMaxValue(array, start, end+1);
}

void printArray(datatype* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}