#include<iostream>
using namespace std;

class Time
{
	int h, m, s;

public:
	Time()
	{
		h = 0;
		m = 0;
		s = 0;
	}
	
	Time(int n)
	{
		h = n;
		m = n;
		s = n;

	}
	void print()
	{
		cout  << h<<":";
		cout << m << ":";
		cout << s<<endl ;
		
	}
	void add(Time &a, Time &b)
	{
		h = (a.h) + (b.h);
		m = (a.m) + (b.m);
		s = (a.s) + (b.s);

	}

};

int main()
{

	Time t1(2);
	Time t2(3);
	Time t3;
	cout << "At first" << endl;
	t3.print();

	t3.add(t1, t2);

	cout << "Now" << endl;
	t3.print();
	return(0);
}



