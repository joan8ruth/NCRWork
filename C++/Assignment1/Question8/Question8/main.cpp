#include<iostream>

using namespace std;

class employee {

	int id;
	int salary;

    public:

		employee()
		{
			id = 0;
			salary = 0;
			cout << "In constructor 1";
		}
		employee(int a, int b)
		{
			id = a;
			salary = b;
			cout << "In constructor 2";
		}
		employee(employee &e)
		{
			id = e.id;
			salary = e.salary;
			cout << "In constructor 3";
		}
		void set_value(int a, int b)
		{
			id = a;
			salary = b;
		}
		void display()
		{
			cout << "Id is " << id;
			cout << "salary is " << salary;

		}

		friend void inc_value(employee e);
		friend void inc_ref(employee &e);
		

};

	void inc_value(employee e)
	 {
		e.salary = (0.1*e.salary) + e.salary;

		}
	void inc_ref(employee &e)
	{
		e.salary = (0.1*e.salary) + e.salary;
	}

int main()
{
	employee e1(1, 5000);
	cout << "Before increment" << endl;
	e1.display();
	inc_value(e1);
	cout << "After increment by value" << endl;
	e1.display();
	inc_ref(e1);
	cout << "After increment by ref" << endl;
	e1.display();
}