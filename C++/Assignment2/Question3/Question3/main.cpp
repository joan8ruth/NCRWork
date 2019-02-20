#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>


using namespace std;

class employee
{
	int empno;
	char *name;
	int sal;

	public:
		employee()
		{
			empno = 0;
			sal = 0;
			name = NULL;

		}
		employee(int num, const char *n, int s)
		{
			int len;
			empno = num;
			len = strlen(n);
			name = new char[len + 1];
			strcpy(name, n);
			sal = s;
		}
		employee(const employee &e)
		{
			int len;
			empno = e.empno;
			len = strlen(e.name);
			name = new char[len + 1];
			strcpy(name, e.name);
			sal = e.sal;

		}

		friend istream& operator>>(istream& cin, employee &e);
		friend ostream& operator<<(ostream& cout, employee str);
};

istream& operator>>(istream& cin, employee &e)
{
	int len;
	char n[20];
	cin >> e.empno;
	cin >> n;
	len = strlen(n);
	e.name = new char[len + 1];
	strcpy(e.name, n);
	cin >> e.sal;
	return cin;
	
}

ostream& operator<<(ostream& cout, employee e)
{
	cout << "Name is " << e.name<<endl;
	cout << "ID is " << e.empno << endl;
	cout << "Salary is " << e.sal << endl;
	return cout;
}

int main()
{
	int i,n;
	employee e[2];
	cout << "Enter details" << endl;
	for (i = 0; i < 2; i++)
	{
		cin >> e[i];
	}

	cout << "details are" << endl;
	for (i = 0; i < 2; i++)
	{
		cout << e[i];
	}
	cout << "Enter" << endl;
	cin >> n;
	return 0;
}