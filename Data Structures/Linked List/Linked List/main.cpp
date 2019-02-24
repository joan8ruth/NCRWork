/* Program to implement a linked list*/

#include<iostream>

#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

class list
{
public:
	struct node* head;
	list();
	void insertfirst(int);
	void insertlast(int);
	void insertafter(int, int);
	void insertbefore(int, int);
	int deletefirst();
	int deletelast();
	void deletespecific(int);
	void display();
};

list::list()
{
	head = NULL;
}

void list::insertfirst(int n)
{
	struct node *temp;
	temp = new node;
	temp->data = n;
	temp->next = head;
	head = temp;

}

void list::insertlast(int n)
{
	struct node *temp,*curr;
	temp = new node;
	temp->data = n;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}

	else {
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;

		}

		curr->next = temp;
	}
}

void list::insertafter(int k,int n)
{
	struct node *temp, *curr;
	
	if (head != NULL) {
		curr = head;
		while (curr != NULL && curr->data != k) {
			curr = curr->next;
		}

		if (curr != NULL) {

			temp = new node;
			temp->data = n;
			temp->next = curr->next;
			curr->next = temp;
		}
		else {
			cout << "Element not found" << endl;
		}
	}
	else {
		cout << "List doesn't exist" << endl;
	}

}

void list::insertbefore(int k, int n)
{
	struct node *temp, *curr;
	if (head->data == k) {
		temp = new node;
		temp->data = n;
		temp->next = head->next;
		head = temp;
	}
	else {
		curr = head;
		while (curr->next != NULL && curr->next->data != k)
		{
			curr = curr->next;
		}
		if (curr->next != NULL) {
			temp = new node;
			temp->data = n;
			temp->next = curr->next;
			curr->next = temp;
		}
		else {
			cout << "Element not found" << endl;
		}
	}
}

int list::deletefirst()
{
	int n;
	if (head != NULL) {
		n = head->data;
		struct node *temp;
		temp = head;
		head = head->next;
		delete temp;
		return n;

	}

	else {
		cout << "List does not exist" << endl;
		return -1;
	}
}

int list::deletelast()
{
	int n;
	if (head != NULL)
	{
		if (head->next == NULL) {
			n = head->data;
			delete head;
			head = NULL;

		}

		else {
			struct node *curr;
			curr = head;
			while (curr->next->next != NULL)
			{
				curr = curr->next;
			}
			n = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}

		return n;
	}
	else {
		cout << "List is empty" << endl;
		return -1;
	}
}

void list::deletespecific(int k)
{
	struct node *temp,*curr;
	if (head != NULL)
	{
		if (head->data == k)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			temp = head;
			while (temp->next != NULL && temp->next->data != k)
				temp = temp->next;
			if (temp->next == NULL)
				cout << "Element not found" << endl;
			else {

				curr = temp->next->next;
				temp->next = curr;
				delete temp->next;

			}
		}
	}

	else
		cout << "List does not exist" << endl;
}

void list::display()
{
	if (head == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		struct node *temp;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data<<endl;
			temp = temp->next;
		}
	}
}

int main()
{
	//option variable is the user menu option number

	list l;
	int option;
	int k, n;
	char stop;
	do {

		cout << "1.Insert first 2.insert last 3.insert after 4.insert before 5.delete first 6.delete last 7.delete specific 8.display " << endl;
		cout << "Enter the option" << endl;

		cin >> option;
		switch (option)
		{

		case 1:	cout << "Enter element" << endl;
			cin >> n;
			l.insertfirst(n);
			break;
		case 2:	cout << "Enter element" << endl;
			cin >> n;
			l.insertlast(n);
			break;

		case 3:	cout << "Enter element after which you want to insert" << endl;
			cin >> k;
			cout << "Enter element" << endl;
			cin >> n;
			l.insertafter(k,n);
				break;

		case 4: cout << "Enter element before which you want to insert" << endl;
			cin >> k;
			cout << "Enter element" << endl;
			cin >> n;
			l.insertbefore(k, n);
			break;

		case 5:cout << "Element deleted is " << l.deletefirst();
			break;

		case 6:cout << "Element deleted is " << l.deletelast();
			break;

		case 7: cout << "Enter element which you want to delete" << endl;
			cin >> n;
			l.deletespecific(n);
			break;
		case 8:l.display();
			break;
		default: cout << "option not available" << endl;
			break;
		}

		cout << "Do you want to continue Y/N?";
		cin >> stop;

	} while (stop == 'y' || stop == 'Y');

	return 0;
}