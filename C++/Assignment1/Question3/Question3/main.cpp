#include<iostream>
using namespace std;

class complex
{
	int real;
	int img;

	public:
		complex()
		{

		}

		complex(int n)
		{
			real = n;
			img = n;
		}

		complex(int r, int i)
		{
			real = r;
			img = i;
		}

		void add(const complex &c1,const complex &c2)
		{
			real = c1.real + c2.real;
			img = c1.img + c2.img;

		}
		void display()
		{
			cout<<"real is " <<real<<endl;
			cout << "imaginary is" << img << endl;

		}
};

int main()
{
	complex a;

	complex b(1);
	cout << "b is" << endl;
	b.display();
	complex c(2, 3);
	cout << "c is"<<endl;
	c.display();
	a.add(b, c);
	cout << "a is" << endl;
	a.display();

}