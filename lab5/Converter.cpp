#include "converter.h"

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

void reverse(string& str) {
	int n = str.length(); // рахує кількість символів
	for (int i = 0; i < n / 2; ++i) { // середина строки
		swap(str[i], str[n - i - 1]); // міняється симетрично
	}
	cout << str << endl;
}

bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isDigit(char c) {
	return (c >= '0' && c <= '9');
}

datatype performAction(char current, datatype x, datatype y) {
	switch (current){
	case '+': {
		return y + x;
		break;
	}
	case '-': {
		return y - x;
		break;
	}
	case '*': {
		return y * x;
		break;
	}
	case '/': {
		return y / x;
		break;
	}
	case '^': {
		return pow(y, x);
		break;
	}
		default:break;;
	}
	return 0;
}

int getPrecedence(char op) {
	if (op == '*' || op == '/') {
		return 2;
	}
	else if (op == '+' || op == '-') {
		return 1;
	}
	else {
		return 0;
	}
}

string InfixToPostfix(string infix) {
	stack<char> s;
	string postfix = "";
	for (int i = 0; i < infix.length(); ++i) {
		if (isalnum(infix[i])) { // Якщо зчитаний символ є операндом, то його записують у вихідний вираз
			postfix += infix[i];
		}
		else if (infix[i] == '(') { // Якщо зчитаний символ є знаком відкритої дужки "(", то додаємо його до стеку
			s.push(infix[i]);
		}
		else if (infix[i] == ')') { // Якщо зчитаний символ є знаком закритої дужки ")", то видобуваємо зі стеку знак операції і записуємо його у вихідний вираз
			while (!s.empty() && s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			if (!s.empty()) {
				s.pop();
			}
		}
		else { // Якщо зчитаний символ є знаком операції, то він заноситься в стек
			while (!s.empty() && s.top() != '(' && getPrecedence(infix[i]) <= getPrecedence(s.top())) {
				postfix += s.top();
				s.pop();
			}
			s.push(infix[i]);
		}
	}
	// Додаємо залишки в стеку до вихідного виразу
	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

string InfixToPrefix(string infix) { // все те саме, тільки навпаки
	reverse(infix); // задом наперед
	for (int i = 0; i < infix.length(); ++i) { // проходження по строці
		if (infix[i] == '(') {
			infix[i] = ')'; // заміна ( на )
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
		}
	}
	string prefix = InfixToPostfix(infix);
	reverse(prefix);
	return prefix;
}

string PostfixToInfix(string postfix) {
	stack<string> s;
	string infix = "";
	for (int i = 0; i < postfix.length(); ++i) { // зчитуємо нормально
		if (isOperand(postfix[i])) { // якщо операнд, то записуємо в стек
			string op(1, postfix[i]);
			s.push(op);
		}
		else { // якщо операція, то
			string op1, op2;
			op1 = s.top(); // видобути два останні елементи
			s.pop();
			op2 = s.top();
			s.pop();
			s.push("(" + op2 + postfix[i] + op1 + ")"); // помістити знак між операндами

		}
	}
	infix = s.top();  // вираз назад у стек
	return infix;
}

string PrefixToInfix(string prefix) {
	stack<string> s;
	string infix = "";
	for (int i = prefix.length() - 1; i >= 0; --i) { // йде з кінця
		if (isOperand(prefix[i])) {
			string op(1, prefix[i]); // якщо операнд, то в стек
			s.push(op);
		}
		else {
			string op1, op2;
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			s.push("(" + op1 + prefix[i] + op2 + ")");
		}
	}
	infix = s.top();
	return infix;
}

datatype EvaluatePostfix(string exp) {
	stack<datatype> s;
	for (int i = 0; i < exp.length(); ++i) {
		if (exp[i] == ' ') {
			continue;
		}
		else if (isDigit(exp[i])) {
			datatype operand = exp[i] - '0'; // Кожна цифра — це окреме число
			s.push(operand);
		}
		else if (isOperator(exp[i])) {
			if (s.size() < 2) {
				throw runtime_error("Недостатньо операндів для операції");
			}
			datatype x = s.top(); s.pop();
			datatype y = s.top(); s.pop();
			s.push(performAction(exp[i], x, y));
		}
		else {
			throw runtime_error("Некоректний символ у виразі");
		}
	}
	return s.top();
}
datatype EvaluatePrefix(string exp) {
	stack<datatype> s;
	for (int i = exp.length() - 1; i >= 0; --i) {
		if (exp[i] == ' ') {
			continue;
		}
		else if (isDigit(exp[i])) {
			datatype operand = exp[i] - '0'; // Кожна цифра — окреме число
			s.push(operand);
		}
		else if (isOperator(exp[i])) {
			if (s.size() < 2) {
				throw runtime_error("Недостатньо операндів для операції");
			}
			datatype x = s.top(); s.pop();
			datatype y = s.top(); s.pop();
			s.push(performAction(exp[i], y, x)); // y перед x для префіксу
		}
		else {
			throw runtime_error("Некоректний символ у виразі");
		}
	}
	return s.top();
}