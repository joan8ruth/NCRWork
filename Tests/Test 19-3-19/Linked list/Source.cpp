#include<iostream>
#include<string.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

class LL
{
	struct node *head;

    public:	

		//constructor
		LL()
		{
			head = NULL;
		}

		//This function inserts elements at the end only
		void insert(int ele)
		{
			struct node* temp;
			struct node* curr;

			temp = new struct node;
			temp->data = ele;
			temp->next = NULL;

			if (head == NULL) {
				
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

		//This function inserts element after nth position
		void insert_n(int n,int ele)
		{
			struct node* curr=head;
			struct node* temp;
			temp = new struct node;
			temp->data = ele;
			temp->next = NULL;

			int i = 1;
				while (i != n && curr->next != NULL)
				{
					curr = curr->next;
					i++;
				}

				if (i != n)
				{
					cout << "position not found" << endl;
					return;
				}
				else
				{
					if (n == 1)
					{
						temp->next = head->next;
						head = temp;
					}
					else {
						temp->next = curr->next;
						curr->next = temp;

					}
				}

		}

		//This function deletes element with value n
		void delete_n(int n)
		{
			struct node* curr = head;
			struct node* prev=curr;
			struct node* temp;

			while (curr->data != n && curr->next != NULL)
			{
				prev = curr;
				curr = curr->next;
				
			}

			if (curr->data != n)
			{
				cout << "element not fount" << endl;
				return;
			}

			else
			{
				if (curr == head)
				{
					temp = head;
					head = head->next;
					temp->next = NULL;
					delete temp;
				}
				else {
				prev->next = curr->next;
				curr->next = NULL;
				delete curr;
				}
			}
		}


		//This function displays in forward direction
		void display()
		{
			struct node* temp = head;
			if (head == NULL)
			{
				cout << "List is empty" << endl;

			}
			else
			{
				
				while (temp != NULL)
				{
					cout << temp->data << endl;
					temp = temp->next;
				}
			}
		}

		//This function displays in reverse direction
		void display_rev()
		{
			int *rev;
			int l=0,i=0,j=0;
			struct node* temp = head;
			if (head == NULL)
			{
				cout << "List is empty" << endl;

			}
			else
			{
				cout << "List in reverse order is" << endl;
				while (temp != NULL)
				{
					l++;
					temp = temp->next;
				}
				rev = new int[l];
				temp = head;
				while (temp != NULL)
				{
					rev[i++] = temp->data;
					temp = temp->next;
				}
				j = l-1;
				while (j >= 0)
				{
					cout << rev[j--] << endl;
				}
			}
		}

	
};

int main()
{
	LL l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(2);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert_n(3, 1);
	//l1.delete_n(1);
	l1.display();
	l1.display_rev();


	return 0;
}