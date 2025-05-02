#include <iostream>
#include "Comb.h"
#include <cmath>
#include <algorithm>

using namespace std;

void mycout(int *A, int l) {
    for (int i = 0; i < l; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void myswap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void bubblesort(int *A, int l, int first, int last) {
    for (int i = first; i < last; i++) {
        for (int j = first; j < last; j++) {
            if (A[j] > A[j + 1]) {
                myswap(A[j], A[j + 1]);
            }
        }
    }
}


int factorial(int n) {
    int F = 1;
    for (int i = 1; i <= n; ++i) F *= i;
    return F;
}

int Ank(int n, int k) {
    return (factorial(n) / (factorial(n - k)));
}

int _Ank(int n, int k) {
    return pow(n, k);
}

int C(int n, int k) {
    return (Ank(n, k) / factorial(k));
}

int _C(int n, int k) {
    return factorial(n + k - 1) / (factorial(k) * factorial(n - 1));
}

int *GenPerm(int *A, int n) {
    for (int i = n - 1; i > 0; i--) {
        if (A[i] >= A[i - 1]) {
            bubblesort(A, n, i, n - 1);
            for (int j = i; j <= n - 1; j++) {
                if (A[i - 1] <= A[j]) {
                    myswap(A[i - 1], A[j]);
                    break;
                }
            }
            break;
        }
    }
    return A;
}

int *GenComb(int *A, int n, int k) {
    for (int i = k - 1; i >= 0; i--) {
        if (A[i] < n - k + i + 1) {
            ++A[i];
            for (int j = i + 1; j < k; j++)
                A[j] = A[j - 1] + 1;
            return A;
        }
    }
}



