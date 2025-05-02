#include <iostream>
/*#include <time.h>*/
#include "Sort.h"

using namespace std;

int main() {
    datatype originalArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sizeOfArray = sizeof(originalArr) / sizeof(originalArr[0]);
    int methodId, start, end;


    do {
        int arr[sizeOfArray];
        for (int i = 0; i < sizeOfArray; ++i) {
            arr[i] = originalArr[i];
        }

        cout << "\n\n\nArray to sort: ";
        printArray(arr, sizeOfArray);

        cout << endl;

        cout << "To start choose one of sorting methods with ID or exit: \n";
        cout << "1. - Bubble method \n";
        cout << "2. - Insertion method \n";
        cout << "3. - Selection method \n";
        cout << "4. - End \n";
        cout << "Enter the method ID or exit: ";
        cin >> methodId;

        switch (methodId) {
            case 1:
                cout << "Enter point of sorting start: ";
                cin >> start;

                cout << "Enter point of sorting end: ";
                cin >> end;

                sortBubble(arr, start, end - 1);
                cout << "Sorted array: ";
            printArray(arr + start, end - start);
                break;
            case 2:
                cout << "Enter point of sorting start: ";
                cin >> start;

                cout << "Enter point of sorting end: ";
                cin >> end;

                sortInsertion(arr, start, end - 1);
                cout << "Sorted array: ";
                printArray(arr, sizeOfArray);

                break;
            case 3:
                cout << "Enter point of sorting start: ";
                cin >> start;

                cout << "Enter point of sorting end: ";
                cin >> end;

                sortSelection(arr, start, end - 1);
                cout << "Sorted array: ";
                printArray(arr, sizeOfArray);

                break;
            case 4:
                cout << "Closing program ";
                return 0;

            default:
                cout << "Default methodId is null" << endl;
        }
    } while (true);
}
