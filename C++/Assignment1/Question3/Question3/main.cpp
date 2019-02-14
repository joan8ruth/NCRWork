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

		
		void display()
		{
			cout<<"real is " <<real<<endl;
			cout << "imaginary is" << img << endl;

		}
		friend complex add(const complex &c1, const complex &c2);
		friend complex mul(complex &c1,complex &c2);
};

complex add(const complex &c1, const complex &c2)
{
	complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	return temp;

}

complex mul(complex &c1,  complex &c2)
{
	complex temp;
	temp.real = (c1.real * c2.real)-(c1.img*c2.img);
	temp.img = (c1.real * c2.img)+(c1.img*c2.real);
	return temp;

}


int main()
{
	complex a;

	complex b(1);
	cout << "b : ";
	b.display();
	cout << endl;
	complex c(2, 3);
	cout << "c is ";
	c.display();
	cout << endl;
	a = add(b, c);
	cout << "a :";
	cout << endl;
	a.display();
	a = mul(b, c);
	cout << "a : ";
	cout << endl;
	a.display();

	return 0;

}