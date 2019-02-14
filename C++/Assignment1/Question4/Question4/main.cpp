#include<iostream>
using namespace std;

inline int add(int a, int b)
{
	return(a + b);
}
inline int mul(int a, int b)
{
	return(a * b);
}
inline float division(int a, int b)
{
	return((float)a / b);
}
inline int sub(int a, int b)
{
	return(a - b);
}
inline int mod(int a, int b)
{
	return(a % b);
}

int main()
{
	int x, y;
	cout << "enter x and y values" << endl;
	cin >> x;
	cin >> y;
	cout << "sum is " << add(x, y)<<endl;
	cout << "product is " << mul(x, y)<<endl;
	cout << "difference is " << sub(x, y)<<endl;
	if (x < 0 || y < 0)
		cout << "division and mod not possible" << endl;
	else {
		cout << "quotient is " << division(x, y) << endl;
		cout << "remiander is " << mod(x, y) << endl;
	}
}