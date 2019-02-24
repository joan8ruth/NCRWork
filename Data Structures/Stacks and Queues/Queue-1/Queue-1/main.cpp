/*Program to implement queue using arrays*/

#include<iostream>

using namespace std;

struct queue
{
	int *s, r, f, size;
};

class _queue_
{
	struct queue q;

public:
	_queue_();
	void enqueue(int);
	int dequeue();
	bool isEmpty();
	bool isFull();
	~_queue_();
	void getSize(int);
	void display();

};

_queue_::_queue_()
{
	//Constructor to initialize front and rear to -1 

	q.f = -1;
	q.r = -1;
	q.s = NULL;
	q.size = 0;

}

void _queue_::getSize(int n)
{
	//n is the size of the queue given by user 

	q.size = n;
	q.s = new int[n];
	q.f = -1;
	q.r = -1;

}

bool _queue_::isFull()
{
	//This method return true if queue is full

	if (q.f == (q.size - 1)&&q.r==0)
		return true;
	else
		return false;
}

bool _queue_::isEmpty()
{
	//This method returns true is stack is empty

	if (q.f == -1&&q.r==-1)
		return true;
	else
		return false;

}

void _queue_::enqueue(int e)
{
	//e is the element to enqueue into the queue

	if (isFull()) {

		cout << "Cannot push as stack is full" << endl;
		return;

	}

	else {
		
		q.s[++q.f] = e;
		if (q.r == -1)
		{
			q.r++;
		}

		return;
	}

}

int _queue_::dequeue()
{
	//e is the element that is dequeued and has to be returned
	int e;

	if (isEmpty()) {

		cout << "Cannot pop as stack is empty" << endl;
		return -1;
	}

	else {

		e = q.s[q.f];
		if (q.f == q.r)
		{
			q.r--;
		}
		q.f--;
		return e;
	}
}

void _queue_::display()
{
	//This method displays all the elements in the stack

	int i;
	
		for (i = q.r; i < q.f + 1; i++)
		{
			cout << q.s[i] << endl;
		}
	
}

_queue_::~_queue_()
{
	delete q.s;
}

int main()
{
	//option variable is the user menu option number

	int option;
	int size;
	int push;
	//int popped;
	char stop;
	_queue_ myQueue;

	do {

		cout << "1.Enter size 2.Enqueue 3.Dequeue 4.Display Elements " << endl;
		cout << "Enter the option" << endl;

		cin >> option;
		switch (option)
		{

		case 1:	cout << "Enter Size" << endl;
				cin >> size;
				myQueue.getSize(size);
				break;
		case 2:	cout << "Enter elements to push" << endl;
				cin >> push;
				myQueue.enqueue(push);
				break;

		case 3:	if (myQueue.isEmpty()){
					cout << "Queue is empty" << endl;
				}
				else{
					cout << "Element popped is " << myQueue.dequeue() << endl;
				}
				break;

		case 4: if (myQueue.isEmpty()) {
					cout << "Queue is empty" << endl;
				}
				else {
					cout << "The elemets in the stack are " << endl;
					myQueue.display();
				}
				break;

		default: cout << "option not available" << endl;
			break;
		}

		cout << "Do you want to continue Y/N?";
		cin >> stop;

	} while (stop == 'y' || stop == 'Y');

	return 0;
}