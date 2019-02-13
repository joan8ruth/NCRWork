#include<iostream>
using namespace std;


	void swap_value(int a, int b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}

	void swap_reference(int &a, int &b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}



int main()
{
	int a=5, b=4,ch;
	cout << "inital values are " << a << " " << b<<endl;

	cout << "Enter how you want to swap" << endl;
	cout << "1.Swap by values" << endl;
	cout << "2.Swap by reference" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1: swap_value(a, b);
		cout << "final values are " << a << " " << b;

		    break;
	case 2:swap_reference(a, b);
		cout << "final values are " << a << " " << b;

		    break;


	}
	

	return 0;
}