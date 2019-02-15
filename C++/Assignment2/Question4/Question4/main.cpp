#include<iostream>

using namespace std;

class complex {

	int real;
	int img;

    public:

		complex()
		{
			cout << "in default constructor" << endl;
		}
		complex(int a, int b)
		{
			
			real = a;
			img = b;
		}
		complex(const complex &c)
		{
			real = c.real;
			img = c.img;

		}
		~complex()
		{
			cout << "in destructor" << endl;
		}

		complex operator+(complex c)
		{
			complex temp;
			temp.real = real + c.real;
			temp.img = img + c.img;
			return temp;
				
		}

		complex operator-(complex c)
		{
			complex temp;
			temp.real = real - c.real;
			temp.img = img - c.img;
			return temp;

		}

		complex operator-()
		{
			complex temp;
			temp.real = -real;
			temp.img = -img;
		}

};