#include "converter.h"

int main() {
	system("chcp 65001 > nul");
	string exp;
	int selection;
	cout << "1. З інфіксної в постфіксну/префіксну\n";
	cout << "2. З постфіксної/префіксної в інфіксну\n";
	cout << "3. Обчислення числових значень виразів\n";
	cout << "4. Кінець\n";
	cin >> selection;
	switch (selection) {
	case 1: {
		int form1;
		cout << "1. Постфіксна форма\n";
		cout << "2. Префіксна форма\n";
		cin >> form1;
		switch (form1) {
		case 1: {
			cout << "Вкажіть інфіксну форму:\n";
			cin >> exp;
			cout << "Інфіксна форма: " << exp << "\n";
			cout << "Постфіксна форма: " << InfixToPostfix(exp) << "\n";
			break;
		}
		case 2: {
			cout << "Вкажіть інфіксну форму:\n";
			cin >> exp;
			cout << "Інфіксна форма: " << exp << "\n";
			cout << "Префіксна форма: " << InfixToPrefix(exp) << "\n";
			break;
		}
		}
			  break;
		}
	case 2: {
			int form2;
			cout << "1. Постфіксна форма\n";
			cout << "2. Префіксна форма\n";
			cin >> form2;
			switch (form2){  
			case 1: {
				cout << "Вкажіть постфіксну форму:\n";
				cin >> exp;
				cout << "Постфіксна форма: " << exp << "\n";
				cout << "Інфіксна форма: " << PostfixToInfix(exp) << "\n";
				break;
			}
			case 2: {
				cout << "Вкажіть префіксну форму:\n";
				cin >> exp;
				cout << "Префіксна форма: " << exp << "\n";
				cout << "Інфіксна форма: " << PrefixToInfix(exp) << "\n";
				break;
			}
				break;
			} 
		break;
	}
	case 3: {
		int form3;
		cout << "1. Постфіксна форма\n";
		cout << "2. Префіксна форма\n";
		cin >> form3;
		switch (form3)
		{
		case 1: {
			cout << "Вкажіть постфіксну форму:\n";
			cin >> exp;
			cout << "Постфіксна форма: " << exp << "\n";
			cout << "Дорівнює: " << EvaluatePostfix(exp) << "\n";
			break;
		}
		case 2: {
			cout << "Вкажіть префіксну форму:\n";
			cin >> exp;
			cout << "Префіксна форма: " << exp << "\n";
			cout << "Дорівнює: " << EvaluatePrefix(exp) << "\n";
			break;
		}
			break;
		}
		break;
	}
	case 4: {
		cout << "\n\nFINISH!!!!!\n\n\n\n";
		break;
	}
		  break;
	}
	return 0;
}
