#include<iostream>

using namespace std;

class polar
{
	int angle;
	int radius;

	public:
		static int count;
		polar()
		{
			angle = 0;
			radius = 0;
			count++;
		}
		polar(int a, int b)
		{
			angle = a;
			radius = b;
			count++;
		}

		~polar()
		{
			count--;
		}

};

int polar::count;

int main()
{
	polar p1, p2(1, 2);
	cout << "current available are " << polar::count<<endl;

	{
		polar p3(2, 3);
		cout << "current available are " << polar::count<<endl;
	}
	cout << "current available are " << polar::count << endl;
}