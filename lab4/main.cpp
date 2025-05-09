#include <iostream>
#include "list.h"
using namespace std;

void switcher();

void Stack() {
	Item *head = NULL;
	datatype data;
	int choice;
	do {
		cout << "Select action " << "\n";
		cout << "1. Push \n";
		cout << "2. Pop \n";
		cout << "3. Exit \n";

		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "Input data \n";
			cin >> data;
			push(head, data);
			show(head);
			break;
		}
		case 2: {
			pop(head);
			show(head);
			break;
		}
		case 3: {
			switcher();
		}
		}
	} while (choice != 3);
}

void Queue() {

	datatype data;
	Item *front = NULL;
	Item *end = NULL;
	Item* head = NULL;
	int choice;
	do {
		cout << "Select action " << "\n";
		cout << "1. Add to queue\n";
		cout << "2. Delete from queue\n";
		cout << "3. Exit \n";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "Input data \n";
			cin >> data;
			enqueue(end, front, data);
			show(front);
			break;
		}
		case 2: {
			dequeue(front);
			show(front);
			break;
		}
		case 3: {
			switcher();
		}
		}
	} while (choice != 3);
}

void List(){
	Item* first = NULL;
	Item* last = NULL;
	datatype data, key;
	int Lister;
	do {
		cout << "1. Add to beginning" << "\n";
		cout << "2. Add to end" << "\n";
		cout << "3. Delete from beginning" << "\n";
		cout << "4. Delete from the end" << "\n";
		cout << "5. Add to 'x' place" << "\n";
		cout << "6. Delete from 'x' place" << "\n";
		cout << "7. Exit\n";
		cin >> Lister;
		switch (Lister)
		{
		case 1: {
			cout << "Input data to add to the beginning\n";
			cin >> data;
			add_begin(first, last, data);
			break;
		}
		case 2: {
			cout << "Input data to add to the ending\n";
			cin >> data;
			add_end(first, last, data);
			break;
		}
		case 3: {
			del_begin(first, last);
			break;
		}
		case 4: {
			del_end(first, last);
			break;
		}
		case 5: {
			int newdata;
			cout << "Enter the item to add after\n";
			cin >> data;
			cout << "Paste item\n";
			cin >> newdata;
			add_mid(first, last, data, newdata);
			break;
		}
		case 6: {
			cout << "Enter the item to delete\n";
			cin >> data;
			del_mid(first, last, data);
			break;
		}
		case 7: {
			switcher();
		}
			  break;
		}
		if (Lister != 7) show(first);
	} while (Lister != 7);
}

void switcher() {
	int selection;
	cout << "Select: \n";
	cout << "1. Stack\n";
	cout << "2. Queue\n";
	cout << "3. List\n";
	cout << "4. Exit\n";
	cin >> selection;
	switch (selection)
	{
	case 1: {
		cout << "\nStack\n";
		Stack();
		break;
	}
	case 2: {
		cout << "\nQueue\n";
		Queue();
		break;
	}
	case 3: {
		cout << "\nList\n";
		List();
		break;
	}
	case 4: {
		cout << "U did it!";
	}
	}
}

int main()
{
	switcher();
	return 0;
}