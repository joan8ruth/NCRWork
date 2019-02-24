/* Implementing a stack using arrays*/

#include<iostream>

using namespace std;

struct stack
{
	int *s, top, size;
};

class _stack_
{
	struct stack sta;

	public:
		_stack_();
		void push(int);
		int pop();
		int peek();
		bool isEmpty();
		bool isFull();
		~_stack_();
		void getSize(int);
		void display();

};

_stack_::_stack_()
{
	//Constructor to initialize stack top to -1 and stack size to 0

	sta.top = -1;
	sta.s = NULL;
	sta.size = 0;

}

void _stack_::getSize(int n)
{
	//n is the size of the stack given by user 

	sta.size = n;
	sta.s = new int[n];

}

bool _stack_::isFull()
{
	//This method return true if stack is full

	if(sta.top==(sta.size-1))
		return true;
	else
		return false;
}

bool _stack_::isEmpty()
{
	//This method returns true is stack is empty

	if (sta.top == -1)
		return true;
	else
		return false;

}

void _stack_::push(int e)
{
	//e is the element to push into the stack

	if (isFull()){
		
		cout << "Cannot push as stack is full" << endl;
		return;

	}

	else {

		sta.s[++sta.top] = e;
		return;
	}

}

int _stack_::pop()
{
	//e is the element that is popped and has to be returned
	int e;

	if (isEmpty()){

		cout << "Cannot pop as stack is empty" << endl;
		return -1;
	}

	else {

		e = sta.s[sta.top--];
		return e;
	}
}

int _stack_::peek()
{
	//This method shows what element called as e is on top

	int e;

	if (isEmpty()) {
		
		cout << "Stack is empty" << endl;
		return -1;
	}

	else {

		e = sta.s[sta.top];
		return e;
	}
}

void _stack_::display()
{
	//This method displays all the elements in the stack

	int i;
	if (isEmpty())
	{
		cout << "Stack is empty" << endl;

	}

	for (i = 0; i < sta.top+1; i++)
	{
		cout << sta.s[i]<<endl;
	}
}

_stack_::~_stack_()
{
	delete sta.s;
}

int main()
{
	//option variable is the user menu option number

	int option;
	int size;
	int push;
	//int popped;
	char stop;
	_stack_ myStack;

	do {

		cout << "1.Enter size 2.Push 3.Pop 4.Display Elements 5.Peek" << endl;
		cout << "Enter the option" << endl;

		cin >> option;
		switch (option)
		{
		
		case 1:cout << "Enter Size" << endl;
			cin >> size;
			myStack.getSize(size);
			break;
		case 2:cout << "Enter elements to push" << endl;
			cin >> push;
			myStack.push(push);
			break;

		case 3:cout << "ELement popped is " << myStack.pop()<<endl;
			break;

		case 4:cout << "The elemets in the stack are " << endl;
			myStack.display();
			break;

		case 5:cout << "The top element is " << myStack.peek() << endl;
			break;

		default: cout << "option not available" << endl;
			break;
		}
	
		cout << "Do you want to continue Y/N?";
		cin >> stop;

	} while (stop=='y'||stop=='Y');

	return 0;
}