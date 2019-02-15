#include<iostream>

using namespace std;

class complex {

	int real;
	int img;

    public:

		complex()
		{
			
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
		

		void display()
		{
			cout << "real is " << real << endl;
			cout << "img is " << img << endl;
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
			return temp;
		}

		complex operator++()
		{
			++real;
			++img;
			return *this;
		}

		complex operator++(int x)
		{
			complex temp;
			temp.real = real++;
			temp.img = img++;
			return temp;
		}

		friend ostream& operator<<(ostream& cout, complex c);
		friend istream& operator>>(istream& cin, complex &c);
		


		~complex()
		{
			cout << "in destructor" << endl;
		}


};

	ostream& operator<<(ostream& cout, complex c)
	{
		cout << c.real << endl;
		cout << c.img << endl;
		return cout;
	}

	istream& operator>>(istream& cin, complex &c)
	{
		cin >> c.real;
		cin >> c.img;
		return cin;
	}


int main()
{
	complex c1(1, 1), c2;
	c1.display();
	c2 = -c1;

	cout << c1;
	c2.display();

}