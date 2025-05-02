#include <iostream>
#include "Comb.h"
using namespace std;

int combinations() {
	int n;
	int k;
	int combchoice;
	cout << "Type the n vertices: ";
	cin >> n;
	cout << "Type the k edges: ";
	cin >> k;

	if (n < k) {
		cout << "n must be greater then k";
		return 0;
	}

	cout << "Type which combination you want:\n1.Factorial\n2.Partial permutation\n3.Partial permutation with repeat\n4.Combination\n5.Combination with repeat\n";
	cin >> combchoice;
	cout << "Factorial: " << factorial(n) << "\n";
	cout << "Partial permutation Ank(n, k): " << Ank(n, k) << "\n";
	cout << "Partial permutation with repeat _Ank(n, k): " << _Ank(n, k) << "\n";
	cout << "Combination C(n, k): " << C(n, k) << "\n";
	cout << "Combination with repeat _C(n, k): " << _C(n, k) << "\n";
	switch (combchoice) {
		case 1: {
			cout << "Your answer: " << factorial(n);
			break;
		}
		case 2: {
			Ank(n, k);
			cout << "Your answer: " << Ank(n, k);
			break;
		}
		case 3: {
			_Ank(n, k);
			cout << "Your answer: " << _Ank(n, k);
			break;
		}
		case 4: {
			C(n, k);
			cout << "Your answer: " << C(n, k);
			break;
		}
		case 5: {
			_C(n, k);
			cout << "Your answer: " << _C(n, k);
			break;
		}
		default:
			break;
	}
	return 0;
}

int Lexicon1() {
	const int n = 6;
	int A[n] = {1, 2, 3, 4, 5, 6};

	int count = 1;
	cout << count << ") ";
	mycout(A, n);

	while (count < factorial(n)) {
		GenPerm(A, n);
		count++;
		cout << count << ") ";
		mycout(A, n);
	}

	return 0;
}

int Lexicon2() {
	int n = 3;
	const int k = 6;
	int A[k] = {1, 2, 3, 4, 5, 6};
	mycout(A, n);
	for (int i = 2; i <= C(k, n); i++) {
		mycout(GenComb(A, k, n), n);
	}
	return 0;
}

int main() {
	int z;
	cout << "\n1.Combinations \n2.Lexicon with value of order \n3.Lexicon without value of order\nType part of the lab: ";
	cin >> z;
	switch (z) {
		case 1: {
			combinations();
			break;
		}
		case 2: {
			Lexicon1();
			break;
		}
		case 3: {
			Lexicon2();
			break;
		}
		default:
			break;
	}
}
