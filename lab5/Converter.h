#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#pragma execution_character_set("utf-8")
using namespace std;

typedef int datatype;

void swap(char&, char&);
void reverse(string&);
bool isOperator(char);
bool isOperand(char);
bool isDigit(char);
datatype performAction(char, datatype, datatype);

string InfixToPostfix(string);
string InfixToPrefix(string);
string PostfixToInfix(string);
string PrefixToInfix(string);

datatype EvaluatePostfix(string);
datatype EvaluatePrefix(string);
